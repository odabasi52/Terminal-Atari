#ifndef PLAYERS_H
#define PLAYERS_H

#include <termios.h>
#include <iostream>
#include <vector>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

vector<int> player1_row = {6,7,8,9,10,11};
vector<int> player2_row = {6,7,8,9,10,11};

class Players{
    public:
        void moveVSAI();
        void moveVSReal();
        int _kbhit();
};


#endif