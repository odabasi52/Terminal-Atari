#ifndef PONG_CPP
#define PONG_CPP

#include "pGame/pgame.cpp"
using namespace std;

void Pong(){
    pGame* mg = new pGame();
    mg->start_game();
}

#endif