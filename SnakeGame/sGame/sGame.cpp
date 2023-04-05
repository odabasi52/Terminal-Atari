#ifndef sGAME_CPP
#define sGAME_CPP

#include "sGame.h"
#include "../Snake/Snake.cpp"

void sGame::draw_map(){
    /*clear terminal*/
    std::cout << "\x1B[2J\x1B[H";

    for(int* cell: map){
        int w = cell[0];
        int h = cell[1];
        bool ifSnake = false;

        for(int* body_part: snake_body){
            //default snake location is middle
            if(w == body_part[0] && h==body_part[1]){
                std::cout << "\u001b[32m" << 'O'  << "\u001b[0m";
                ifSnake = true;
            }
        }
        if(!ifSnake){
            //first and last lines are walls
            if(h == 0 || h == map_height-1)
                std::cout << "\u001b[34m" << '#';
            //first and last columns are walls
            else if(w == 0 || w == map_width-1)
                std::cout << "\u001b[34m" << '#';
            //default apple location
            else if(w == apple_w && h == apple_h)
                std::cout << "\u001b[31m" <<'*';           
            else
                std::cout << ' ';
        }

        if(w == map_width-1)
            std::cout << std::endl;
    }
}

void sGame::reset_map(){
    std::cout << "\x1B[2J\x1B[H";
    
    snake_body = {};
    int* body_part = new int[2]{(int)map_width/2, (int)map_height/2};
    snake_body.push_back(body_part);
    body_part = new int[2]{(int)map_width/2 -1, (int)map_height/2};
    snake_body.push_back(body_part);
    body_part = new int[2]{(int)map_width/2 -2, (int)map_height/2};
    snake_body.push_back(body_part);
    delete body_part;
    this->generate_apple();

    for(int* cell: map){
        int w = cell[0];
        int h = cell[1];

        //first and last lines are walls
        if(h == 0 || h == map_height-1)
            std::cout << '#';
        //first and last columns are walls
        else if(w == 0 || w == map_width-1)
            std::cout << '#';
        //default apple location
        else if(w == apple_w && h == apple_h)
            std::cout << '*';        
        else if(w >= (int)map_width/2 -2 && w<=(int)map_width/2 && h == (int)map_height/2)
            std::cout << 'O';   
        else
            std::cout << ' ';

        if(w == map_width-1)
            std::cout << std::endl;
    }
}

void sGame::create_map(){ 
    for(int h=0; h < map_height; h++){
        for(int w=0; w < map_width; w++){
            int* cell = new int[2];
            cell[0] = w;
            cell[1] = h;
            
            map.push_back(cell);
        }
    }
}

void sGame::generate_apple(){
    srand(time(NULL));
    apple_w = (rand() % map_width-3)+1;
    apple_h = (rand() % map_height-3)+1;
}

sGame::sGame(int width, int height){
    map_width = width;
    map_height = height;

    int* body_part = new int[2]{(int)map_width/2, (int)map_height/2};
    snake_body.push_back(body_part);
    body_part = new int[2]{(int)map_width/2 -1, (int)map_height/2};
    snake_body.push_back(body_part);
    body_part = new int[2]{(int)map_width/2 -2, (int)map_height/2};
    snake_body.push_back(body_part);
    delete body_part;

    this->generate_apple();    
}

void sGame::play(){
    Snake* snake = new Snake();
    snake->MoveSnake();
    delete snake;
}

#endif