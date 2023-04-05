#ifndef GAME_CPP
#define GAME_CPP

#include "pgame.h"
using namespace std;

void pGame::start_game(){
    cout << "\x1B[2J\x1B[H";

    int choice;
    cout << "\u001b[30;1mOPTIONS:  Player1{W-S}  Player2{O-L}\n\n";
    cout << "\u001b[37;1mMAKE YOUR CHOICE\n";
    cout << "\u001b[32;1m[1]\u001b[0m VS Computer \n\u001b[32;1m[2]\u001b[0m VS Player\n";
    while(1){
        choice = this->getch();
        if(choice == 49 || choice == 50)
            break;
    }

    switch(choice){
        case 49:
            this->playAI();
            break;

        case 50:
            this->playReal();
            break;
    }
}

void pGame::playAI(){
    Map* map = new Map();
    Players* p = new Players();
    Ball* ball = new Ball();
    while(1){
        cout << "\x1B[2J\x1B[H";
        map->generate_map();
        if(ball->check_for_win()){
            this->end_game();
        }
        else{
            p->moveVSAI();
            ball->ball_follower();
            ball->ball_mover();
            ball_pos[0] += pos_x;  ball_pos[1] += pos_y;
            usleep(57000);
        }
    }    
}

void pGame::playReal(){
    Map* map = new Map();
    Players* p = new Players();
    Ball* ball = new Ball();
    while(1){
        cout << "\x1B[2J\x1B[H";
        map->generate_map();
        if(ball->check_for_win()){
            this->end_game();
        }
        else{
            p->moveVSReal();
            ball->ball_mover();
            ball_pos[0] += pos_x;  ball_pos[1] += pos_y;
            usleep(80000);
        }
    }
}

void pGame::end_game(){
    cout << "\u001b[32;1m[1]\u001b[0m Exit\n\u001b[32;1m[2]\u001b[0m Reset\n";
    int choice;

    while(1){
        choice = getch();
        if(choice == 49 || choice == 50)
            break;
    }
    if(choice == 49)
        exit(1);
    else{
        ball_pos[0] = 40; ball_pos[1] = 10;
        pos_x = -pos_x;
        pos_y = 0;
        player1_row = {6,7,8,9,10,11};
        player2_row = {6,7,8,9,10,11};
    }
}

int pGame::getch(){
    termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio=old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    return getchar();
}
#endif