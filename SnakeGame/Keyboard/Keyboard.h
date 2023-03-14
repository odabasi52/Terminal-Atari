#ifndef KEYBOARD
#define KEYBOARD

#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <sys/ioctl.h>

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

Direction direction;

class Keyboard{
    public:
        void set_direction();
        Direction get_direction();
        int _kbhit();
        
};

#endif