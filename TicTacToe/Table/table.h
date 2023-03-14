#ifndef TABLE_H
#define TABLE_H

#include <iostream>
using namespace std;

string game_table[3][3]{
    {"\u001b[30;1m1","\u001b[30;1m2","\u001b[30;1m3"},
    {"\u001b[30;1m4","\u001b[30;1m5","\u001b[30;1m6"},
    {"\u001b[30;1m7","\u001b[30;1m8","\u001b[30;1m9"}
};

class Table{
    public:
        void draw_table();
        void update_table(int& choise, bool& player1);
        void reset_table();
};




#endif