#ifndef SNAKEGAME_CPP
#define SNAKEGAME_CPP

#include "Headers/Headers.h"

using namespace std;

void snake()
{
    cout << "\x1B[2J\x1B[H";

    int w,h;
    cout << "\e[1m" << "\u001b[4m" << "WELCOME TO SNAKE GAME" << "\u001b[0m" <<endl;
    cout <<  "WASD to play, Q to quit while playing" << "\u001b[0m" <<endl << endl;
    cout << "Please enter width and height for game area (100 30): ";
    cin >> w >> h;

    while(cin.fail() || w < 30 || h < 15){
        cin.clear();
        cin.ignore(20, '\n');
        cout << "(!ERROR!) Enter valid width and height: ";
        cin >> w >> h;
    }

    int speed_choise;
    cout << "\e[1m" << "[1]" << "\u001b[32m"  <<" Normal" << "\u001b[0m" << endl;
    cout << "\e[1m" << "[2]" << "\u001b[34m"  <<" Fast" << "\u001b[0m" << endl;
    cout << "\e[1m" << "[3]" << "\u001b[31m"<<" Lightspeed" << "\u001b[0m" <<endl;
    cout << "Choose one of speed levels: ";
    cin >> speed_choise;
    while(cin.fail() || speed_choise < 1 || speed_choise > 3){
        cin.clear();
        cin.ignore(20, '\n');
        cout << "(!ERROR!) Enter an integer between 1-3: ";
        cin >> speed_choise;
    }
    int speed = (speed_choise==1)?80000:(speed_choise==2)?50000:20000;

    Game* game = new Game(w,h);
   
    game->create_map();
    game->draw_map();

    while(1){
        game->play();
        usleep(speed);
    }
}

#endif