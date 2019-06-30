#include "Joystick.h"

JOYSTICK::
JOYSTICK(uint8_t ardpinJX, uint8_t ardpinJY)
{
    JX = ardpinJX;
    JY = ardpinJY;
    pinMode(JX, INPUT);
    pinMode(JY, INPUT);
    prevJoyState = -1;

    // Fill function callbacks with dummy function
    f_neutral = dummy;
    f_up = dummy;
    f_down = dummy;
    f_left = dummy;
    f_right = dummy;
    f_NW = dummy;
    f_SW = dummy;
    f_NE = dummy;
    f_SE = dummy;
}


// Attach function callbacks to joystick
void JOYSTICK::attachNeutral(func funcs){f_neutral = funcs;}
void JOYSTICK::attachUp(func funcs){f_up = funcs;}
void JOYSTICK::attachDown(func funcs){f_down = funcs;}
void JOYSTICK::attachLeft(func funcs){f_left = funcs;}
void JOYSTICK::attachRight(func funcs){f_right = funcs;}
void JOYSTICK::attachNW(func funcs){f_NW = funcs;}
void JOYSTICK::attachSW(func funcs){f_SW = funcs;}
void JOYSTICK::attachNE(func funcs){f_NE = funcs;}
void JOYSTICK::attachSE(func funcs){f_SE = funcs;}


void JOYSTICK::
read()
{
    // Divide x,y joystick to 9 different states
    // x y
    // 0 0 - SW 
    // 0 1 - LEFT
    // 0 2 - NW
    // 1 0 - DOWN
    // 1 1 - NEUTRAL
    // 1 2 - UP
    // 2 0 - SE
    // 2 1 - RIGHT
    // 2 2 - NE
    xstate = map(analogRead(JX), 0, 1023, 0, 2);
    ystate = map(analogRead(JY), 0, 1023, 0, 2);
    joystate = xstate*10 + ystate;
}


void JOYSTICK::
tick(){
    // Dont run commands if we are still on the same joystick state
    // Prevent commands running more than once
    if (joystate == prevJoyState)
    {
        return;
    }

    switch (joystate)
    {
        case 11: // NEUTRAL
            f_neutral();
            break;

        case 12: // UP
            f_up();
            break;

        case 10: // DOWN
            f_down();
            break;

        case 1: // LEFT
            f_left();
            break;

        case 21: // RIGHT
            f_right();
            break;

        case 2: // NW
            f_NW();
            break;

        case 0: // SW
            f_SW();
            break;

        case 22: // NE
            f_NE();
            break;

        case 20: // SE
            f_SE();
            break;
    }

    // Update prev joy state
    prevJoyState = joystate;
}

// dummy function
void dummy(){}