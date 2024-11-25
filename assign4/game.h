#ifndef GAME_H
#define GAME_H

#include "room.h"
#include "event.h"
#include <vector>

using namespace std;

class Game{
    private: 
        //grid:
        vector<vector <Room*> > rooms; 
        int length;
        int width;
        //locations:
        int spawn_x;
        int spawn_y;
        int player_x;
        int player_y;
        //checkers for win conditions:
        bool has_gold;
        bool wumpus_dead;
        int arrows; //arrows left
        bool debug_mode;

    public:
        //constructor and destructor:
        /*********************************************************************
        ** Function: Game
        ** Description: constructor, initializes all variables and starts the game
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: creates a game object
        *********************************************************************/ 
        Game();
        /*********************************************************************
        ** Function: ~Game
        ** Description: destructor, deletes all rooms and events
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: deletes a game object
        *********************************************************************/ 
        ~Game();
        /*********************************************************************
        ** Function: run
        ** Description: Game loop, runs the game for each turn, checks for win conditions
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: runs the game
        *********************************************************************/ 
        void run();

        //helper functions:
        /*********************************************************************
        ** Function: populate_rooms
        ** Description: populates the grid with rooms and events
        ** Parameters:  none
        ** Pre-Conditions: none
        ** Post-Conditions: populates the grid
        *********************************************************************/ 
        void populate_rooms();
        /*********************************************************************
        ** Function: has_won
        ** Description: checks if the player has won
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: returns true if the player has won
        *********************************************************************/ 
        bool has_won();
        /*********************************************************************
        ** Function: print_grid_debug
        ** Description: prints the grid with debug info
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: prints the grid with debug info 
        *********************************************************************/ 
        void print_grid_debug();
        /*********************************************************************
        ** Function: add_event
        ** Description: adds an event to the grid
        ** Parameters: Event *event
        ** Pre-Conditions: none
        ** Post-Conditions: adds an event to the grid
        *********************************************************************/ 
        void add_event(Event *event);

        //move player:
        /*********************************************************************
        ** Function: move_player
        ** Description: moves the player
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: moves the player
        *********************************************************************/ 
        void move_player();
        //helper for move player
        /*********************************************************************
        ** Function: get_move
        ** Description: gets a valid move from the user
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: returns the move
        *********************************************************************/ 
        char get_move();
        /*********************************************************************
        ** Function: move_player_reverse
        ** Description: moves the player in the opposite direction, used for the bat feature
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: moves the player in the opposite direction
        *********************************************************************/ 
        void move_player_reverse();
        /*********************************************************************
        ** Function: fire_arrow
        ** Description: fires an arrow in the direction the player chooses
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: fires an arrow in the direction the player chooses
        *********************************************************************/ 
        void fire_arrow();
        /*********************************************************************
        ** Function: get_arrow_direction
        ** Description: gets the direction the player wants to fire the arrow
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: returns the direction the player wants to fire the arrow
        *********************************************************************/ 
        char get_arrow_direction();
        //fire arrow directions:
        /*********************************************************************
        ** Function: fire_up, fire_down, fire_left, fire_right
        ** Description: fires an arrow in the direction the player chooses
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: fires an arrow in the direction the player chooses
        *********************************************************************/ 
        void fire_up();
        void fire_down();
        void fire_left();
        void fire_right();
        
        /*********************************************************************
        ** Function: set_grid_dimensions
        ** Description: sets the grid dimensions, geting the length and width from the user
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: sets the grid dimensions
        *********************************************************************/ 
        void set_grid_dimensions();
        
        /*********************************************************************
        ** Function: print_percepts
        ** Description: prints the percepts for the player, i.e. if there is a bat, pit, gold, or wumpus nearby
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: prints the percepts for the player
        *********************************************************************/ 
        void print_percepts();
        /*********************************************************************
        ** Function: set_debug_mode
        ** Description: sets the debug mode, which prints the grid with debug info
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: sets the debug mode
        *********************************************************************/ 
        bool set_debug_mode();
        /*********************************************************************
        ** Function: encounter_event
        ** Description: encounters an event, i.e. if the player is in a room with a bat, pit, gold, or wumpus
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: returns an int
        *********************************************************************/ 
        int encounter_event();
        /*********************************************************************
        ** Function: print_grid
        ** Description: prints the grid
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: prints the grid
        *********************************************************************/ 
        void print_grid();
        /*********************************************************************
        ** Function: move_wumpus
        ** Description: 3/4 chance to move the wumpus to a random location on the board, called when an arrow is fired 
        ** Parameters: none
        ** Pre-Conditions: none
        ** Post-Conditions: possibly moves the wumpus
        *********************************************************************/ 
        void move_wumpus();
};

#endif