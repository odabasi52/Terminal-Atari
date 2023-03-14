#ifndef MENU_H
#define MENU_H

#include "../SnakeGame/snake.cpp"
#include "../TicTacToe/TicTacToe.cpp"

using namespace std;

void atari(){
    cout << "\x1B[2J\x1B[H";

    cout << "\e[1m"  << "WELCOME TO TERMINAL ATARI"  << endl;
    cout << "\u001b[4m" << "Please choose one of the games given below or quit" << "\u001b[0m" <<endl<<endl;

    cout << "[0] " << "QUIT"  << "\u001b[0m" << endl;
    cout << "[1] " << "\u001b[32m" << "SNAKE"  << "\u001b[0m" << endl;
    cout << "[2] " << "\u001b[34m" << "TICTACTOE"  << "\u001b[0m" << endl;

    int choise;
    cout << "\nYour choise: ";
    cin >> choise;

    while(cin.fail() || choise < 0 || choise > 5){
        cin.clear();
        cin.ignore(20, '\n');
        cout << "(!ERROR!) Choose one of valid options: ";
        cin >> choise;
    }

    switch(choise){
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
    }
}

#endif