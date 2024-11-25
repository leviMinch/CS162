/*********************************************************************
** Program Filename: bats.cpp
** Author: Levi Minch
** Date: May 29th, 2023
** Description: bats class implementation file, this is a derived class of event
** Input: none
** Output: none
*********************************************************************/
#include "bats.h"
#include <iostream>

using namespace std;

Bats::Bats(){
    this->symbol = 'B';
    this->is_wumpus = false;
}

Bats::~Bats(){}

int Bats::encounter(){
    cout << "You get attacked by bats and become dissorianted!" << endl;
    return 3;
}

void Bats::percept(){
    cout << "You hear wings flapping." << endl;
}

char Bats::get_symbol(){
    return this->symbol;
}

bool Bats::get_is_wumpus(){
    return this->is_wumpus;
}