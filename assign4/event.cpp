/*********************************************************************
** Program Filename: event.cpp
** Author: Levi Minch 
** Date: May 29th, 2023
** Description: event class implementation file, this is an abstract class, as such it only has a constructor and destructor
** Input: none
** Output: none
*********************************************************************/
#include "event.h"
#include <iostream>

using namespace std;

Event::Event(){
    this->symbol = ' ';
    this->is_wumpus = false;
}

Event::~Event(){}