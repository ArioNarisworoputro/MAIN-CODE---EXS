#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class MCONTROL {

  public:
  // Constructor and initial setup
    MCONTROL();
    MCONTROL(uint8_t ardpinENA, uint8_t ardpinIN1, uint8_t ardpinIN2);
    void setup();

    // Motor Commands
    void forward();
    void reverse();
    void halt();
    void freerun();

    // Control over over serial
    void setTerminalCommands(
      uint8_t fr, uint8_t rev,
      uint8_t st, uint8_t frun);
    void serialTest();

  private:
    uint8_t ENA;
    uint8_t IN1;
    uint8_t IN2;
    uint8_t testChar;
    uint8_t comForward;
    uint8_t comReverse;
    uint8_t comHalt;
    uint8_t comFreerun;
    void command(uint8_t in1, uint8_t in2);
};

#endif
