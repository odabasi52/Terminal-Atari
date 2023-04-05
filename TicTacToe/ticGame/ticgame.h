#ifndef ticGAME_H
#define ticGAME_H

#include "../Table/table.cpp"
#include "../Check/check.cpp"
#include <termios.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void play(){
    Table* table = new Table();
    Check* check = new Check();
    int choice;
    bool player1 = false;
    while(1){
        cout << "\x1B[2J\x1B[H";
        table->draw_table();

        termios old_tio, new_tio;
        tcgetattr(STDIN_FILENO,&old_tio);
        new_tio=old_tio;
        new_tio.c_lflag &=(~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
        while(1){
            choice = getchar();
            choice -= 48;
            if( (choice > 0 || choice < 10) && check->isPlacable(choice))
                break;
        }
        
        
        table->update_table(choice, player1);
        if(check->isWin()){
            cout << "\x1B[2J\x1B[H";
            table->draw_table();
            string player = player1?"\u001b[37;1mPLAYER 1":"\u001b[37;1mPLAYER 2";
            cout << player << " WON THE GAME\n";
            cout << "[1] RESET\n[2] QUIT\n";
            int operation;
            while(1){
                operation = getchar();
                operation -= 48;
                if(operation == 1 || operation == 2)
                    break;
            }

            switch(operation){
                case 1:
                    table->reset_table();
                    break;
                case 2:
                    cout << "\x1B[2J\x1B[H";
                    exit(1);
                    break;
            }
        }
        
        player1 = !player1;
    }
}

#endif