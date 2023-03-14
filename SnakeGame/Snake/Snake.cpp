#ifndef SNAKE_CPP
#define SNAKE_CPP

#include "Snake.h"

void Snake::MoveSnake(){
    Keyboard* kb = new Keyboard(); 
    Game* game = new Game();
    std::string gameover_choice;
    
    bool hitYourself = false;
    kb->set_direction();
    Direction dir = kb->get_direction();
    
    switch(dir){
        case LEFT:
            for(int i = 1; i < snake_body.size(); i++){
                if(snake_body[0][0] == snake_body[i][0] && snake_body[0][1] == snake_body[i][1])
                    hitYourself = true;
            }

            /*Check if there is collision*/
            if(snake_body[0][0] <= 1 || hitYourself){
                std::cout << "\u001b[31m" << "\e[1m" << "!__G-A-M-E_____O-V-E-R__!\n"  << "\u001b[0m";
                
                while(1){
                    std::cout << "Write reset or quit: ";
                    std::cin.clear();
                    std::cin >> gameover_choice;
                    if(gameover_choice == "reset"){
                        game -> reset_map();
                        break;
                    }
                    else if(gameover_choice == "quit"){
                        std::cout << "\x1B[2J\x1B[H";
                        exit(1);
                    }
                    else std::cout << "Invalid input\n\n";                
                } 
            }
            else{
                if(snake_body[0][0] == apple_w && snake_body[0][1] == apple_h){
                    game->generate_apple();
                    isEaten = true;
                }
                this->UpdateSnake(dir);
                isEaten = false;
                game->draw_map();
            }
        break;

        case RIGHT:
            for(int i = 1; i < snake_body.size(); i++){
                if(snake_body[0][0] == snake_body[i][0] && snake_body[0][1] == snake_body[i][1])
                    hitYourself = true;
            }

            /*Check if there is collision*/
            if(snake_body[0][0] >= map_width - 2 || hitYourself){
                std::cout << "\u001b[31m" << "\e[1m" << "!__G-A-M-E_____O-V-E-R__!\n"  << "\u001b[0m";
                
                while(1){
                    std::cout << "Write reset or quit: ";
                    std::cin.clear();
                    std::cin >> gameover_choice;
                    if(gameover_choice == "reset"){
                        game -> reset_map();
                        break;
                    }
                    else if(gameover_choice == "quit"){
                        std::cout << "\x1B[2J\x1B[H";
                        exit(1);
                    }
                    else std::cout << "Invalid input\n\n";                
                } 
            }
            else{
                if(snake_body[0][0] == apple_w && snake_body[0][1] == apple_h ){
                    game->generate_apple();
                    isEaten = true;
                }
                this->UpdateSnake(dir);
                isEaten = false;
                game->draw_map();
            }
        break;

        case UP:
            for(int i = 1; i < snake_body.size(); i++){
                if(snake_body[0][0] == snake_body[i][0] && snake_body[0][1] == snake_body[i][1])
                    hitYourself = true;
            }

            /*Check if there is collision*/
            if(snake_body[0][1] <= 1 || hitYourself){
                std::cout << "\u001b[31m" << "\e[1m" << "!__G-A-M-E_____O-V-E-R__!\n"  << "\u001b[0m";
                
                while(1){
                    std::cout << "Write reset or quit: ";
                    std::cin.clear();
                    std::cin >> gameover_choice;
                    if(gameover_choice == "reset"){
                        game -> reset_map();
                        break;
                    }
                    else if(gameover_choice == "quit"){
                        std::cout << "\x1B[2J\x1B[H";
                        exit(1);
                    }
                    else std::cout << "Invalid input\n\n";                
                }   
            }
            else{
                if(snake_body[0][0] == apple_w && snake_body[0][1] == apple_h){
                    game->generate_apple();
                    isEaten = true;
                }
                this->UpdateSnake(dir);
                isEaten = false;
                game->draw_map();              
            }           
        break;

        case DOWN:
            for(int i = 1; i < snake_body.size(); i++){
                if(snake_body[0][0] == snake_body[i][0] && snake_body[0][1] == snake_body[i][1])
                    hitYourself = true;
            }

            /*Check if there is collision*/
            if(snake_body[0][1] >= map_height - 2 || hitYourself){
                std::cout << "\u001b[31m" << "\e[1m" << "!__G-A-M-E_____O-V-E-R__!\n"  << "\u001b[0m";
                
                while(1){
                    std::cout << "Write reset or quit: ";
                    std::cin.clear();
                    std::cin >> gameover_choice;
                    if(gameover_choice == "reset"){
                        game -> reset_map();
                        break;
                    }
                    else if(gameover_choice == "quit"){
                        std::cout << "\x1B[2J\x1B[H";
                        exit(1);
                    }
                    else std::cout << "Invalid input\n\n";                
                } 
            }
            else{
                if(snake_body[0][0] == apple_w && snake_body[0][1] == apple_h){
                    game->generate_apple();
                    isEaten = true;
                }
                this->UpdateSnake(dir);
                isEaten = false;
                game->draw_map(); 
            }
        break;
    }

    
    delete kb;
    delete game;
}


void Snake::UpdateSnake(Direction dir){
    int* new_head = new int[2];
    switch(dir){
        case LEFT:
            new_head = new int[2]{snake_body[0][0]-1, snake_body[0][1]};
            snake_body.insert(snake_body.begin(), new_head);
            if(!isEaten)
                snake_body.pop_back();
        break;
        case RIGHT:
            new_head = new int[2]{snake_body[0][0]+1, snake_body[0][1]};
            snake_body.insert(snake_body.begin(), new_head);
            if(!isEaten)
                snake_body.pop_back();
        break;
        case UP:
            new_head = new int[2]{snake_body[0][0], snake_body[0][1]-1};
            snake_body.insert(snake_body.begin(), new_head);
            if(!isEaten)
                snake_body.pop_back();
        break;
        case DOWN:
            new_head = new int[2]{snake_body[0][0], snake_body[0][1]+1};
            snake_body.insert(snake_body.begin(), new_head);
            if(!isEaten)
                snake_body.pop_back();
        break;
    }
}

#endif