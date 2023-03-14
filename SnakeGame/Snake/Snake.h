#ifndef SNAKE
#define SNAKE

#include "../Game/Game.cpp"
#include "../Keyboard/Keyboard.cpp"

int snake_length;

class Snake{
    public:
        void MoveSnake();
        void UpdateSnake(Direction dir);
};

#endif