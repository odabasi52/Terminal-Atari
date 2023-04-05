#ifndef pGAME_H
#define pGAME_H

#include "../Map/map.cpp"

class pGame{
    public:
        void playAI();
        void playReal();
        void end_game();
        int getch();

        void start_game();
}; 
#endif
