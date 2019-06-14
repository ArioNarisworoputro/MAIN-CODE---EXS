#ifndef controller_h
#define controller_h

#include <Arduino.h>
#include "OneButton.h"
#include "L298N.h"

// Commands/Functions to be attached to buttons and joystick
void clickUP();
void clickLEFT();
void clickDOWN();
void clickRIGHT();
void joystickMOVE(int analogX, int analogY);

// Callback function for joystick
// To pass on functions as an argument to another function
extern "C"{
  typedef void (*joycallback)(int valJX, int valJY);
}

class CONTROLLER {

  public:
    CONTROLLER(uint8_t ardpinUP, uint8_t ardpinLEFT,
        uint8_t ardpinDOWN,uint8_t ardpinRIGHT,
        uint8_t ardpinJX, uint8_t ardpinJY);
    
    // Attach main commands to buttons and joystick
    // Call controlLoop() inside main.cpp loop() please
    void attachMotor(uint8_t ardpinENA, uint8_t ardpinIN1, uint8_t ardpinIN2);
    void attachCommands();
    void controlLoop();

    // Enabling and disabling buttons/joystick inputs
    //void enableButtons();
    //void disableButtons();
    //void enableJoystick();
    //void disableJoystick();

  private:
    OneButton btnUP;
    OneButton btnLEFT;
    OneButton btnDOWN;
    OneButton btnRIGHT;
    OneButton btnJC;
    joycallback _joyCommand;
    uint8_t bEnable;
    uint8_t jEnable;
    uint8_t joyX;
    uint8_t joyY;
};

#endif