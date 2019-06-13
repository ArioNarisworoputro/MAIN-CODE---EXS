#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class MCONTROL {

  public:
    MCONTROL();
    MCONTROL(byte ardpinENA, byte ardpinIN1, byte ardpinIN2);
    void setup();
    void forward();
    void reverse();
    void halt();
    void freerun();
    void setTerminalCommands(
      byte fr, byte rev,
      byte st, byte frun);
    void serialTest();

  private:
    byte ENA;
    byte IN1;
    byte IN2;
    byte testChar;
    byte comForward;
    byte comReverse;
    byte comHalt;
    byte comFreerun;
    void command(byte in1, byte in2);
};

#endif
