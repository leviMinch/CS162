#include "event.h"

using namespace std;

class Pit : public Event{
    public:
        Pit();
        ~Pit();
        int encounter();
        void percept();
        char get_symbol();
        bool get_is_wumpus();
};