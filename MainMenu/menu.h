#ifndef MENU_H
#define MENU_H

#include "../SnakeGame/snake.cpp"
#include "../TicTacToe/TicTacToe.cpp"
#include "../Pong/pong.cpp"

using namespace std;

void atari(){
    cout << "\x1B[2J\x1B[H";

    cout << "\e[1m"  << "WELCOME TO TERMINAL ATARI"  << endl;
    cout << "\u001b[4m" << "Please choose one of the games given below or quit" << "\u001b[0m" <<endl<<endl;

    cout << "[0] " << "QUIT"  << "\u001b[0m" << endl;
    cout << "[1] " << "\u001b[31;1m" << "SNAKE"  << "\u001b[0m" << endl;
    cout << "[2] " << "\u001b[34m" << "TICTACTOE"  << "\u001b[0m" << endl;
    cout << "[3] " << "\u001b[30;1m" << "PONG"  << "\u001b[0m\nYour choice >>  ";
    
    int choice;
    cin >> choice;

    while(cin.fail() || choice < 0 || choice > 3){
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Enter one of choices: ";
        cin >> choice;
    }
    switch(choice){
        case 0:
            cout << "\x1B[2J\x1B[H";
            exit(1);
        break;
        case 1:
            snake();
        break;
        case 2:
            TicTacToe();
        break;
        case 3:
            Pong();
        break;
    }
}

#endif