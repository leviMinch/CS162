/*********************************************************************
** Program Filename: gold.cpp
** Author: Levi Minch
** Date: May 29th, 2023
** Description: gold class implementation file, this is a derived class of event
** Input: none
** Output: none
*********************************************************************/


#include "gold.h"
#include <iostream>

using namespace std;

Gold::Gold() : Event(){
    this->symbol = 'G';
    this->is_wumpus = false;
}

Gold::~Gold(){}

int Gold::encounter(){
    cout << "You have found the gold!" << endl;
    return 1;
}

void Gold::percept(){
    cout << "You see a glimmer nearby." << endl;
}

char Gold::get_symbol(){
    return this->symbol;
}

bool Gold::get_is_wumpus(){
    return this->is_wumpus;
}