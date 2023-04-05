#ifndef PLAYERS_CPP
#define PLAYERS_CPP

#include "players.h"
using namespace std;

int Players::_kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

void Players::moveVSAI(){
    termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio=old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    if(this->_kbhit()){
        switch(getchar()){
            //Player 1
            case 'w':
                if(player1_row[0] != 1){
                    player1_row.insert(player1_row.begin(), player1_row[0] - 1);
                    player1_row.pop_back();
                }
                break;
            case 's':
                if(player1_row[5] != 18){
                    player1_row.push_back(player1_row[5] + 1);
                    player1_row.erase(player1_row.begin());
                }
                break;
        }
    }
};

void Players::moveVSReal(){
    termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio=old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    if(this->_kbhit()){
        switch(getchar()){
            //Player 1
            case 'w':
                if(player1_row[0] != 1){
                    player1_row.insert(player1_row.begin(), player1_row[0] - 1);
                    player1_row.pop_back();
                }
                break;
            case 's':
                if(player1_row[5] != 18){
                    player1_row.push_back(player1_row[5] + 1);
                    player1_row.erase(player1_row.begin());
                }
                break;

            //Player2
            case 'o':
                if(player2_row[0] != 1){
                    player2_row.insert(player2_row.begin(), player2_row[0] - 1);
                    player2_row.pop_back();
                }
                break;
            case 'l':
                if(player2_row[5] != 18){
                    player2_row.push_back(player2_row[5] + 1);
                    player2_row.erase(player2_row.begin());
                }
                break;
        }
    }
};


#endif