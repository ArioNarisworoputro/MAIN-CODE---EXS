#ifndef controller_h
#define controller_h

#include "L298N.h"
#include "OneButton.h"
#include "Joystick.h"


// Motor
MOTOR O_motor = MOTOR(10, 9, 8);
void motor1_forward(){O_motor.forward();}
void motor1_reverse(){O_motor.reverse();}
void motor1_halt(){O_motor.halt();}
void motor1_freerun(){O_motor.freerun();}


// Controller
OneButton O_btnFW = OneButton(13, true, true);
OneButton O_btnRV = OneButton(12, true, true);
OneButton O_btnHL = OneButton(11, true, true);
OneButton O_btnFR = OneButton(7, true, true);
JOYSTICK O_joyStick = JOYSTICK(A0, A1);


// Controller Setups
void setup_controller_btn()
{
  O_btnFW.attachClick(motor1_forward);
  O_btnRV.attachClick(motor1_reverse);
  O_btnHL.attachClick(motor1_halt);
  O_btnFR.attachClick(motor1_freerun);
}


void setup_controller_joy()
{
  O_joyStick.attachNeutral(motor1_halt);
  O_joyStick.attachLeft(motor1_forward);
  O_joyStick.attachRight(motor1_reverse);
}


void loop_controller(){
    O_btnFW.tick();
    O_btnRV.tick();
    O_btnHL.tick();
    O_btnFR.tick();
    O_joyStick.read();
    O_joyStick.tick();
}

#endif