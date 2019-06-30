#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"
#include "callbackfunc.h"

void dummy();

class JOYSTICK {

  public:
    // Constructor
    JOYSTICK(uint8_t ardpinJX, uint8_t ardpinJY);

    // Read & Update
    void read();
    void tick();

    // Attach function callbacks to joystick
    void attachNeutral(func funcs);
    void attachUp(func funcs);
    void attachDown(func funcs);
    void attachLeft(func funcs);
    void attachRight(func funcs);
    void attachNW(func funcs);
    void attachSW(func funcs);
    void attachNE(func funcs);
    void attachSE(func funcs);

  private:
    uint8_t JX;
    uint8_t JY;
    int xstate;
    int ystate;
    int joystate;
    int prevJoyState;

    // Function callbacks
    func f_neutral;
    func f_up;
    func f_down;
    func f_left;
    func f_right;
    func f_NW;
    func f_SW;
    func f_NE;
    func f_SE;
};

#endif
