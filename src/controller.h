#ifndef controller2_h
#define controller2_h

#include <Arduino.h>
#include "OneButton.h"
#include "L298N.h"

extern MCONTROL MotorA;
void clickUP();
void clickLEFT();
void clickDOWN();
void clickRIGHT();
void joystickMOVE(int analogX, int analogY);

extern "C"{
  typedef void (*joycallback)(int valJX, int valJY);
}

class CONTROLLER {

  public:
    CONTROLLER(uint8_t ardpinUP, uint8_t ardpinLEFT,
        uint8_t ardpinDOWN,uint8_t ardpinRIGHT,
        uint8_t ardpinJX, uint8_t ardpinJY);
    
    void attachMotor(uint8_t ardpinENA, uint8_t ardpinIN1, uint8_t ardpinIN2);
    void attachCommands();
    void controlLoop();

  private:
    OneButton btnUP;
    OneButton btnLEFT;
    OneButton btnDOWN;
    OneButton btnRIGHT;
    OneButton btnJC;
    joycallback _joyCommand;
    uint8_t joyX;
    uint8_t joyY;
};

#endif