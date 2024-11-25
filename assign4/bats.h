#include "event.h"

class Bats : public Event{
    public:
        Bats();
        ~Bats();
        int encounter();
        void percept();
        char get_symbol();
        bool get_is_wumpus();
};