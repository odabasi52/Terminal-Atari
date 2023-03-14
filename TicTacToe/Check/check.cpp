#include "check.h"
using namespace std;

bool Check::isPlacable(int& choise){
    switch(choise){
        case 1:
            if(game_table[0][0] != "\u001b[30;1m1")
                return false;
            break;
        case 2:
            if(game_table[0][1] != "\u001b[30;1m2")
                return false;
            break;
        case 3:
            if(game_table[0][2] != "\u001b[30;1m3")
                return false;
            break;
        case 4:
            if(game_table[1][0] != "\u001b[30;1m4")
                return false;
            break;
        case 5:
            if(game_table[1][1] != "\u001b[30;1m5")
                return false;
            break;
        case 6:
            if(game_table[1][2] != "\u001b[30;1m6")
                return false;
            break;
        case 7:
            if(game_table[2][0] != "\u001b[30;1m7")
                return false;
            break;
        case 8:
            if(game_table[2][1] != "\u001b[30;1m8")
                return false;
            break;
        case 9:
            if(game_table[2][2] != "\u001b[30;1m9")
                return false;
    }
    return true;
};

bool Check::isWin(){
    for(int i=0;i<3;i++){
        if(game_table[i][0] == game_table[i][1] && game_table[i][1] == game_table[i][2]){
            game_table[i][0] = "\u001b[47;1m" + game_table[i][0];
            game_table[i][1] = "\u001b[47;1m" + game_table[i][1];
            game_table[i][2] = "\u001b[47;1m" + game_table[i][2];
            return true;
        }
        else if(game_table[0][i] == game_table[1][i] && game_table[1][i] == game_table[2][i]){
            game_table[0][i] = "\u001b[47;1m" + game_table[0][i];
            game_table[1][i] = "\u001b[47;1m" + game_table[1][i];
            game_table[2][i] = "\u001b[47;1m" + game_table[2][i];
            return true;
        }
    }
    if(game_table[0][0] == game_table[1][1] && game_table[1][1] == game_table[2][2]){
        game_table[0][0] = "\u001b[47;1m" + game_table[0][0];
        game_table[1][1] = "\u001b[47;1m" + game_table[1][1];
        game_table[2][2] = "\u001b[47;1m" + game_table[2][2];
        return true;
    }      
    else if(game_table[0][2] == game_table[1][1] && game_table[1][1] == game_table[2][0]){
        game_table[0][2] = "\u001b[47;1m" + game_table[0][2];
        game_table[1][1] = "\u001b[47;1m" + game_table[1][1];
        game_table[2][0] = "\u001b[47;1m" + game_table[2][0];
        return true;
    }

    return false;
}