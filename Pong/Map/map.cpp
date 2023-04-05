#ifndef MAP_CPP
#define MAP_CPP

#include "map.h"
using namespace std;

void Map::generate_map(){
    for(int y=0;y<20;y++){
        for(int x=0;x<80;x++){
            bool isObj = false;
            //check for players
            for(int row_1:player1_row){
                if(x == 2 && y == row_1){
                    cout << "\u001b[30;1m0\u001b[0m";
                    isObj = true;
                }
            }
            for(int row_2:player2_row){
                if(x == 77 && y == row_2){
                    cout << "\u001b[30;1m0\u001b[0m";
                    isObj = true;
                }
            }
            if(x == ball_pos[0] && y == ball_pos[1]){
                isObj = true;
                cout << "\u001b[37;1mo\u001b[0m";
            }

            if(isObj)
                continue;
            else{
                if(y==0 || y == 19 || x == 79 || x == 0)
                    cout << "\u001b[34;1m#\u001b[0m";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

#endif