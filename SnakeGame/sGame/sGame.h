#ifndef GAME
#define GAME

#include <vector>
#include <memory>
#include <stdlib.h>
#include <time.h>

int apple_w, apple_h;
bool isEaten = false;

std::vector<int*> snake_body;
std::vector<int*> map;

int map_width, map_height;

class sGame{
    public:
        sGame(int width, int height);
        sGame() = default;
        
        void draw_map();
        void reset_map();
        void create_map();
        void play();
        void generate_apple();
};

#endif