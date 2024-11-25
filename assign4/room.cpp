/*********************************************************************
** Program Filename: room.cpp
** Author: Levi Minch
** Date: May 29th, 2023
** Description: room class implementation file, this is a class that holds an event pointer, and has functions to interact with the event
** Input: none
** Output: none
*********************************************************************/
#include "room.h"
#include <iostream>

using namespace std;

Room::Room(){
    this->event = NULL;
    this->has_event = false;
}

bool Room::get_has_event(){
    return this->has_event;
}

char Room::get_event_symbol(){
    if(this->has_event)
        return this->event->get_symbol();
    else
        return ' ';
}
Room::~Room(){
    if(this->has_event)
        delete this->event;
}

int Room::encounter(){
    if(this->has_event)
        return this->event->encounter();
    else
        return 0;
}

void Room::percept(){
    if(this->has_event)
        this->event->percept();
}

void Room::set_event(Event* event){
    delete this->event;
    this->event = event;
    //this if statement allows us to remove the event from the room if necessary
    if(this->event == NULL)
        this->has_event=false;
    else
        this->has_event = true;
}

bool Room::get_has_wumpus(){
    if(this->has_event)
        return this->event->get_is_wumpus();
}

