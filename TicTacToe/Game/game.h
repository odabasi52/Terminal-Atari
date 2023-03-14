#ifndef GAME_H
#define GAME_H

#include "../Table/table.cpp"
#include "../Check/check.cpp"
using namespace std;

void play(){
    Table* table = new Table();
    Check* check = new Check();
    int choise;
    bool player1 = true;
    while(1){
        cout << "\x1B[2J\x1B[H";
        table->draw_table();

        cout << "\u001b[37;1mEnter your choise: ";
        cin >> choise;
        while(cin.fail() || !check->isPlacable(choise) || choise > 9 || choise < 1){
            cin.clear();
            cin.ignore(200,'\n');
            cout << "\u001b[37;1mChoose one of valid cells: ";
            cin >> choise;
        }

        table->update_table(choise, player1);
        if(check->isWin()){
            cout << "\x1B[2J\x1B[H";
            table->draw_table();
            string player = player1?"\u001b[37;1mPLAYER 1":"\u001b[37;1mPLAYER 2";
            cout << player << " WON THE GAME\n";
            cout << "[1] RESET\n[2] QUIT\nChoose Operation: ";
            int operation;
            cin >> operation;
            while(cin.fail() || operation < 1 || operation > 2){
                cin.clear();
                cin.ignore(200,'\n');
                cout << "\u001b[37;1mChoose one of valid operations: ";
                cin >> operation;
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