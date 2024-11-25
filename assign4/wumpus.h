#ifndef WUMPUS_H
#define WUMPUS_H


#include "event.h"
class Wumpus : public Event{
    public: 
        Wumpus();
        ~Wumpus();
        int encounter();
        void percept();
        char get_symbol();
        bool get_is_wumpus();
};

#endif