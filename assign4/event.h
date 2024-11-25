#ifndef EVENT_H
#define EVENT_H
class Event{
    protected:
        char symbol;
        bool is_wumpus;
    public:
        /*********************************************************************
        ** Function: Event
        ** Description: Default constructor for Event class
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/ 
        Event();
        /*********************************************************************
        ** Function: ~Event
        ** Description: Destructor for Event class
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        virtual ~Event();
        /*********************************************************************
        ** Function: encounter
        ** Description: Pure virtual function for encounter. Within the bats, gold,
        ** pit, and wumpus classes, this function will be overridden to print a message and
        ** return an integer value. This integer value will communicate to the game to either
        ** end the game, reverse movement, or update if the player found gold.
        ** Parameters: None
        ** Pre-Conditions: player is on an event
        ** Post-Conditions: None
        *********************************************************************/
        virtual int encounter() = 0;
        /*********************************************************************
        ** Function: percept
        ** Description: Pure virtual function for percept. Within the bats, gold, pit, and wumpus
        ** classes, this function will be overridden to print a message to the user. Warning 
        ** messages will be printed if the player is within one square of the event.
        ** Parameters: None
        ** Pre-Conditions: close to event
        ** Post-Conditions: None
        *********************************************************************/
        virtual void percept() = 0;
        /*********************************************************************
        ** Function: get_symbol
        ** Description: Pure virtual function for get_symbol. Within the bats, gold, pit, and wumpus
        ** classes, this function will be overridden to return the symbol of the event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        virtual char get_symbol() = 0;
        /*********************************************************************
        ** Function: get_is_wumpus
        ** Description: Pure virtual function for get_is_wumpus. Within the bats, gold, pit, and wumpus
        ** classes, this function will be overridden to return the is_wumpus boolean value.
        ** this will be used to tell if an arrow has hit a wumpus. 
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: None
        *********************************************************************/
        virtual bool get_is_wumpus() = 0;

};


#endif