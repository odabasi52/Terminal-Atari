#ifndef ticGAME_H
#define ticGAME_H

#include "../Table/table.cpp"
#include "../Check/check.cpp"


using namespace std;

void play(){
    Table* table = new Table();
    Check* check = new Check();
    int choice;
    bool player1 = true;
    while(1){
        cout << "\x1B[2J\x1B[H";
        table->draw_table();
        cout << "Enter a cell number: ";
        cin >> choice;
        while(choice < 1 || choice > 9 || cin.fail() || !check->isPlacable(choice)){
            cin.clear();
            cin.ignore(200,'\n');
            cout << "Enter one of cell numbers: ";
            cin >> choice;
        }
        
        
        table->update_table(choice, player1);
        if(check->isWin()){
            cout << "\x1B[2J\x1B[H";
            table->draw_table();
            string player = player1?"\u001b[37;1mPLAYER 1":"\u001b[37;1mPLAYER 2";
            cout << player << " WON THE GAME\n";
            cout << "[1] RESET\n[2] QUIT\nYour Choice >>  ";
            int operation;
            cin >> operation;
            while(operation > 2 || operation < 1 || cin.fail()){
                cin.clear();
                cin.ignore(200,'\n');
                cout << "Enter one of choices: ";
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