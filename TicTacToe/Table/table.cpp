#include "table.h"

void Table::draw_table(){
    cout << " \u001b[37;1m_________________" << endl;
    
    for(int i=0;i<3;i++){    
        cout << "\u001b[37;1m|     |     |     |" << endl;
        cout << "\u001b[37;1m|  "<< game_table[i][0] << "\u001b[37;1m  |  " 
            << game_table[i][1] << "\u001b[37;1m  |  " << game_table[i][2] << "\u001b[37;1m  |" << endl;
        cout << "\u001b[37;1m|_____|_____|_____|" << endl;
    }    
}


void Table::update_table(int& choise, bool& player1){
    string cell_char = player1?"\u001b[31mX\u001b[0m":"\u001b[34mO\u001b[0m";
    switch(choise){
        case 1:
            game_table[0][0] = cell_char;
        break;
        case 2:
            game_table[0][1] = cell_char;
        break;
        case 3:
            game_table[0][2] = cell_char;
        break;
        case 4:
            game_table[1][0] = cell_char;
        break;
        case 5:
            game_table[1][1] = cell_char;
        break;
        case 6:
            game_table[1][2] = cell_char;
        break;
        case 7:
            game_table[2][0] = cell_char;
        break;
        case 8:
            game_table[2][1] = cell_char;
        break;
        case 9:
            game_table[2][2] = cell_char;
        break;
    }
    
}

void Table::reset_table(){
    int num = 1;
    for(int i = 0; i<3;i++){
        for(int j=0;j<3;j++){
            game_table[i][j] = "\u001b[30;1m" + to_string(num);
            num++;
        }
    }
}