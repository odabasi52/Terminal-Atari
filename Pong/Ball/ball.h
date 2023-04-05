#ifndef BALL_H
#define BALL_H

#include "../Players/players.h"
using namespace std;

int player_1_score = 0;
int player_2_score = 0;

int ball_pos[2] {40,10};
int pos_x = 1, pos_y = 0;

class Ball{
    public:
        void ball_mover();
        void ball_follower();
        bool check_for_win();
};

#endif