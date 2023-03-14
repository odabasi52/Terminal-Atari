#ifndef KEYBOARD_CPP
#define KEYBOARD_CPP

#include "Keyboard.h"


int Keyboard::_kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

void Keyboard::set_direction(){
    termios old_tio, new_tio;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them at the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    if(this->_kbhit()){
        switch (getchar())
        {
        case 'a':
            if(direction != RIGHT)
                direction = LEFT;
            break;
        case 'd':
            if(direction != LEFT)
                direction = RIGHT;
            break;
        case 'w':
            if(direction != DOWN)
                direction = UP;
            break;
        case 's':
            if(direction != UP)
                direction = DOWN; 
            break;   
        case 'q':
            std::cout << "\x1B[2J\x1B[H";
            exit(1);
            break;   
        }
    }

    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}

Direction Keyboard::get_direction(){
    return direction; 
}

#endif