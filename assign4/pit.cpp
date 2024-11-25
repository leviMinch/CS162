/*********************************************************************
** Program Filename: pit.cpp
** Author: Levi Minch
** Date: May 29th, 2023
** Description: pit class implementation file, this is a derived class of event
** Input: none
** Output: none
*********************************************************************/
#include "pit.h"
#include <iostream>

using namespace std;

Pit::Pit(){
    this->symbol = 'P';
    this->is_wumpus = false;
}

Pit::~Pit(){}

int Pit::encounter(){
    cout << "You have fallen into a pit!" << endl;
    return 2;
}

void Pit::percept(){
    cout << "You feel a breeze." << endl;
}

char Pit::get_symbol(){
    return this->symbol;
}

bool Pit::get_is_wumpus(){
    return this->is_wumpus;
}

