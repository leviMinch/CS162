/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Levi Minch
** Date: May 29th, 2023
** Description: wumpus class implementation file, this is a derived class of event
** Input: none
** Output: none
*********************************************************************/
#include "wumpus.h"
#include <iostream>

using namespace std;

Wumpus::Wumpus() : Event(){
    this->symbol = 'W';
    this->is_wumpus = true;
}

Wumpus::~Wumpus(){}

int Wumpus::encounter(){
    cout << "You have been eaten by the Wumpus!" << endl;
    return 2;
}

void Wumpus::percept(){
    cout << "You smell a terrible stench." << endl;
}

char Wumpus::get_symbol(){
    return this->symbol;
}

bool Wumpus::get_is_wumpus(){
    return this->is_wumpus;
}