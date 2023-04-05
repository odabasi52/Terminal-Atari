#ifndef BALL_CPP
#define BALL_CPP

#include "ball.h"
using namespace std;


void Ball::ball_mover(){
    int x = ball_pos[0];
    int y = ball_pos[1];

    if(x == 78){
        ball_pos[0] = 40; ball_pos[1] = 10;
        pos_x = -pos_x;
        pos_y = 0;
        player1_row = {6,7,8,9,10,11};
        player2_row = {6,7,8,9,10,11};
        player_1_score++;

        cout << "Player1: " << player_1_score << " | Computer: "<< player_2_score;
        cout << "\nPress any key to continue";
        getchar(); 
    }
    else if(x == 1){
        ball_pos[0] = 40; ball_pos[1] = 10;
        pos_x = -pos_x;
        pos_y = 0;
        player1_row = {6,7,8,9,10,11};
        player2_row = {6,7,8,9,10,11};
        player_2_score++;
        
        cout << "Player1: " << player_1_score << " | Computer: "<< player_2_score;
        cout << "\nPress any key to continue";
        getchar(); 
    }

    else if(x == 76 && (y == player2_row[0] || y == player2_row[1] || y == player2_row[2] )){
        pos_x = -1;
        pos_y = -1;
    }
    else if(x == 76 && (y == player2_row[3] || y == player2_row[4] || y == player2_row[5])){
        pos_x = -1;
        pos_y = 1;
    }
    else if(x == 3 && (y == player1_row[0] || y == player1_row[1] || y == player1_row[2])){
        pos_x = 1;
        pos_y = -1;
    }
    else if(x == 3 && (y == player1_row[3] || y == player1_row[4] || y == player1_row[5])){
        pos_x = 1;
        pos_y = 1;
    }
    else if(y == 18){
        pos_y = -1;
    }
    else if(y == 1){
        pos_y = 1;
    }
}

void Ball::ball_follower(){
    if(ball_pos[0] > 73 && ball_pos[1] < player2_row[2] && player2_row[0] != 1){
        player2_row.insert(player2_row.begin(), player2_row[0] - 1);
        player2_row.pop_back();
    }

    else if(ball_pos[0] > 73 && ball_pos[1] > player2_row[3] && player2_row[5] != 18){
        player2_row.push_back(player2_row[5] + 1);
        player2_row.erase(player2_row.begin());
    }    
}

bool Ball::check_for_win(){
    if(player_1_score >= 3){
        cout << "Player1 won\n";
        player_1_score = 0; player_2_score = 0;
        return true;
    }
    else if(player_2_score >= 3){
        cout << "Player2 won\n";
        player_1_score = 0; player_2_score = 0;
        return true;
    }
        
    return false;
}

#endif