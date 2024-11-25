#ifndef ROOM_H
#define ROOM_H
#include "event.h"

class Room{
    private:
        //possible has an event
        Event *event;
        bool has_event;
    public:
        /*********************************************************************
        ** Function: Room
        ** Description: Default constructor for Room class
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        Room();
        /*********************************************************************
        ** Function: ~Room
        ** Description: Destructor for Room class, will delete event if it exists
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        ~Room();
        /*********************************************************************
        ** Function: get_has_event
        ** Description: Returns has_event boolean value, used to tell if a room has an event
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        bool get_has_event();
        /*********************************************************************
        ** Function: get_event_symbol
        ** Description: Returns event symbol, used for printing the grid 
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: returns the event symbol
        *********************************************************************/
        char get_event_symbol();
        /*********************************************************************
        ** Function: encounter()
        ** Description: Calls the encounter function of the event class
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        int encounter();
        /*********************************************************************
        ** Function: percept()
        ** Description: Calls the percept function of the event class
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        void percept();
        /*********************************************************************
        ** Function: set_event
        ** Description: Sets the event pointer to the event passed in
        ** updates has_event boolean value
        ** Parameters: Event *event
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        void set_event(Event *event);
        /*********************************************************************
        ** Function: get_has_wumpus
        ** Description: Returns the has_wumpus boolean value of the event class
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        bool get_has_wumpus();
};
#endif