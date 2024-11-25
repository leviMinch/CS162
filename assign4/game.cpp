/*********************************************************************
** Program Filename: game.cpp
** Author: Levi Minch 
** Date: May 29th, 2023
** Description: contains the functions for the game class, runs the game
** Input: none
** Output:  none
*********************************************************************/

#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"
#include "game.h"
#include <iostream>
#include <stdlib.h>//srand, rand
#include <time.h>//time

using namespace std;

Game::Game(){
    srand(time(NULL));
    this->length = 0;
    this->width = 0;
    this->set_grid_dimensions();
    this->arrows = 3;
    this->spawn_x = rand() % width;
    this->spawn_y = rand() % length;
    this->player_x = spawn_x;
    this->player_y = spawn_y;
    this->has_gold = false;
    this->wumpus_dead = false;
    this->debug_mode = set_debug_mode();
    this->populate_rooms();
    this->run();
}

bool Game::set_debug_mode(){
    cout << "Would you like to play in debug mode (y/n): ";
    char choice;
    cin >> choice;
    while(choice != 'y' && choice != 'n'){
        cout << "Invalid choice, try again." << endl;
        cout << "Would you like to play in debug mode (y/n): ";
        cin >> choice;
    }
    if(choice == 'y')
        return true;
    else
        return false;
    return choice;
}

void Game::set_grid_dimensions(){
    while(this->width <= 3){
        cout << "enter the width of the grid, it must be greater than 3: ";
        cin >> this->width;
    }
    while(this->length <= 3){
        cout << "enter the lenght of the grid, it must be greater than 3: ";
        cin >> this->length;
    }
}

void Game::print_percepts(){
    cout << "\n--percetps--" << endl; 
    if(this->player_x > 0){
        if(this->rooms[this->player_x - 1][this->player_y]->get_has_event())
            this->rooms[this->player_x - 1][this->player_y]->percept();
    }
    if(this->player_x < this->length - 1){
        if(this->rooms[this->player_x + 1][this->player_y]->get_has_event())
            this->rooms[this->player_x + 1][this->player_y]->percept();
    }
    if(this->player_y > 0){
        if(this->rooms[this->player_x][this->player_y - 1]->get_has_event())
            this->rooms[this->player_x][this->player_y - 1]->percept();
    }
    if(this->player_y < this->width - 1){
        if(this->rooms[this->player_x][this->player_y + 1]->get_has_event())
            this->rooms[this->player_x][this->player_y + 1]->percept();
    }
}

Game::~Game(){
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[i].size(); j++){
            delete this->rooms[i][j];
        }
    }
}

void Game::move_wumpus(){
    int chance = rand() % 4;
    if(chance != 4){
        int wumpus_x = 0;
        int wumpus_y = 0;
        for(int i = 0; i < this->length; i++){
            for(int j = 0; j < this->width; j++){
                if(this->rooms[i][j]->get_has_wumpus()){
                    this->rooms[i][j]->set_event(NULL);
                    this->add_event(new Wumpus());
                }
            }
        }
    }
}

void Game::populate_rooms(){
    for(int i = 0; i < length; i++){
        vector<Room*> row;
        for(int j = 0; j < width; j++){
            row.push_back(new Room());
        }
        this->rooms.push_back(row);
    }
    //add events to rooms:
    //add wumpus:
    this->add_event(new Wumpus());
    //add 2 pits:
    this->add_event(new Pit());
    this->add_event(new Pit());
    //add 2 bats:
    this->add_event(new Bats());
    this->add_event(new Bats());
    //add gold:
    this->add_event(new Gold());

}

//helper function for popoulate rooms, adds a specified event to random room on grid
void Game::add_event(Event *event){
    int x = rand() % width;
    int y = rand() % length;
    while(this->rooms[x][y]->get_has_event() || (x == this->spawn_x && y == this->spawn_y)){
        x = rand() % width;
        y = rand() % length;
    }
    this->rooms[x][y]->set_event(event);
}

void Game::print_grid_debug(){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            if(i == this->player_x && j == this->player_y)
                cout << "|*";
            else
                cout << "|" << rooms[i][j]->get_event_symbol();
            
        }
        cout << "|" << endl;
    }
}

void Game::print_grid(){
    cout << "--Game Grid--" << endl;
    if(this->debug_mode){
        this->print_grid_debug();
        return;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            if(i == this->player_x && j == this->player_y)
                cout << "|*";
            else
                cout << "| "; 
        }
        cout << "|" << endl;
    }
}

//note: this function is over 15 lines due to the comments
void Game::run(){
    int reverse_move = 0, counter = 0;
    //while the game is not over:
    while(!this->has_won() && counter != 2){
        this->print_percepts();
        this->print_grid();
        //check if the player is disorianted by a bat
        if(reverse_move > 0){
            reverse_move--;
            this->move_player_reverse();
        }
        else
            this->move_player();
        //check if the player is in a room with an event, if so encounter it
        counter = encounter_event();
        if(counter == 3)
            reverse_move = 6;
    }
}

int Game::encounter_event(){
    if(rooms[player_x][player_y]->get_has_event()){
        int result = rooms[player_x][player_y]->encounter(); 
        rooms[player_x][player_y]->set_event(NULL);
        if(result == 1)
            this->has_gold = true;
        else if(result == 2){
            cout << "You have died." << endl;
            return 2;
        }
        else if(result == 3)
            return 3;
    }
    return false;
}

//this function could be smaller and fit under 15 lines if I didn't have to check for out of bounds
//additionally, I could make an invididual funciton for each move, but that would be a lot of functions adding more clutter
void Game::move_player(){
    char move = this->get_move();
    if(move == 'w'){
        if(this->player_x == 0){
            cout << "You cannot move that way." << endl;
        }
        else
            this->player_x--;
    }
    else if(move == 'a'){
        if(this->player_y == 0){
            cout << "You cannot move that way." << endl;
        }
        else
            this->player_y--;
    }
    else if(move == 's'){
        if(this->player_x == this->length - 1){
            cout << "You cannot move that way." << endl;
        }
        else
            this->player_x++;
    }
    else if(move == 'd'){
        if(this->player_y == this->width - 1){
            cout << "You cannot move that way." << endl;
        }
        else
            this->player_y++;
    }
    else if(move == 'f'){
        this->fire_arrow();
        this->move_wumpus();
    }
}

void Game::fire_arrow(){
    cout << "You have chosen to fire an arrow.";
    if (this->arrows < 0){
        cout << "You have no arrows left." << endl;
        return;
    }
    char direction = this->get_arrow_direction();
    if(direction =='w')
        this->fire_up();
    else if(direction =='a')
        this->fire_left();
    else if(direction == 's')
        this->fire_down();
    else if(direction == 'd')
        this->fire_right();
    this->arrows--;
}

//helper for fire_arrow
char Game::get_arrow_direction(){
    char direction;
    cout << "Enter a direction to fire the arrow: ";
    cin >> direction;
    while(direction != 'w' && direction != 'a' && direction != 's' && direction != 'd'){
        cout << "Invalid direction, try again: ";
        cin >> direction;
    }
    return direction;
}

void Game::fire_up(){
    int counter = 3;
    int x = this->player_x;
    int y = this->player_y;
    while(x > 0 && counter >0){
        x--;
        counter--;
        if(this->rooms[x][y]->get_has_event()){
            if(this->rooms[x][y]->get_has_wumpus()){
                this->wumpus_dead = true;
                cout << "You have killed the wumpus!" << endl;
                this->rooms[x][y]->set_event(NULL);
            }
        }
    }
}

void Game::fire_down(){
    int counter = 3;
    int x = this->player_x;
    int y = this->player_y;
    while(x < this->length - 1 && counter >0){
        x++;
        counter--;
        if(this->rooms[x][y]->get_has_event()){
            if(this->rooms[x][y]->get_has_wumpus()){
                this->wumpus_dead = true;
                cout << "You have killed the wumpus!" << endl;
                this->rooms[x][y]->set_event(NULL);
            }
        }
    }
}

void Game::fire_left(){
    int counter = 3;
    int x = this->player_x;
    int y = this->player_y;
    while(y > 0 && counter >0){
        y--;
        counter--;
        if(this->rooms[x][y]->get_has_event()){
            if(this->rooms[x][y]->get_has_wumpus()){
                this->wumpus_dead = true;
                cout << "You have killed the wumpus!" << endl;
                this->rooms[x][y]->set_event(NULL);
            }
        }
    }
}

void Game::fire_right(){
    int counter = 3;
    int x = this->player_x;
    int y = this->player_y;
    while(y < this->width - 1 && counter >0){
        y++;
        counter--;
        if(this->rooms[x][y]->get_has_event()){
            if(this->rooms[x][y]->get_has_wumpus()){
                this->wumpus_dead = true;
                cout << "You have killed the wumpus!" << endl;
                this->rooms[x][y]->set_event(NULL);
            }
        }
    }
}

//used for bats
void Game::move_player_reverse(){
    char move = this->get_move();
    if(move == 's'){
        if(this->player_x == 0){
            cout << "You cannot move that way." << endl;
        }
        else{
            this->player_x--;
        }
    }
    else if(move == 'd'){
        if(this->player_y == 0){
            cout << "You cannot move that way." << endl;
        }
        else{
            this->player_y--;
        }
    }
    else if(move == 'w'){
        if(this->player_x == this->length - 1){
            cout << "You cannot move that way." << endl;
        }
        else{
            this->player_x++;
        }
    }
    else if(move == 'a'){
        if(this->player_y == this->width - 1){
            cout << "You cannot move that way." << endl;
        }
        else{
            this->player_y++;
        }
    }
    else if(move == 'f'){
        this->fire_arrow();
        this->move_wumpus();
    }
}

//helper function for move player
char Game::get_move(){
    char move;
    cout << "Enter a move: ";
    cin >> move;
    while(move != 'w' && move != 'a' && move != 's' && move != 'd' && move != 'f'){
        cout << "Invalid move, try again: ";
        cin >> move;
    }
    return move;
}


bool Game::has_won(){
    if(this->has_gold && this->wumpus_dead && this->player_x == this->spawn_x && this->player_y == this->spawn_y){
        cout << "-------------------------" << endl;
        cout << "You have won the game!!!!\nCongragulations!!!" << endl;
        cout << "-------------------------" << endl;
        return true;
    }
    else
        return false;
}