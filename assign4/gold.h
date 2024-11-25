#include "event.h"

using namespace std;

class Gold : public Event{
    public:
        Gold();
        ~Gold();
        int encounter();
        void percept();
        char get_symbol();
        bool get_is_wumpus();
};