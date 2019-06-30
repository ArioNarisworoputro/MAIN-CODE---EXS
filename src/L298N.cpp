#include "L298N.h"

// Motor control
// IN1 IN2
// H    L = Forward
// L    H = Reverse
// H    H = Break and hold/ stop
// L    L = Free running

// Connection Description
// 1 Arduino pin (ex: pin 10) to L298N ENA pin 
// 1 Arduino pin (ex: pin 9) to L298N IN1 pin 
// 1 Arduino pin (ex: pin 8) to L298N IN2 pin
// Motor + terminal to L298N Motor A left conn
// Motor - terminal to L298N Motor A right conn
// 12V Power Supply + terminal to L298N VMS conn
// 12V Power Supply GND/- terminal to L298N GND conn 
// Arduino GND pin to L298N GND conn (sharing it with 12V pwoer supply - terminal)


MOTOR::
MOTOR(uint8_t ardpinENA, uint8_t ardpinIN1, uint8_t ardpinIN2)
{
  ENA = ardpinENA;
  IN1 = ardpinIN1;
  IN2 = ardpinIN2;
}


void MOTOR::
setup() 
{
  // Set these arduino pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENA, 255);

  // Set the motor to break initially
  halt();

  // Set terminal commands for testing
  // Default value is
  // 1 = forward
  // 2 = reverse
  // 3 = Halt
  // 4 = Free run
  // Other numbers = Forward
  setTerminalCommands(1, 2, 3, 4);
}


// Motor Commands
void MOTOR::forward() {command(HIGH, LOW);}
void MOTOR::reverse() {command(LOW, HIGH);}
void MOTOR::halt(){command(HIGH, HIGH);}
void MOTOR::freerun() {command(LOW, LOW);}
void MOTOR::
command(uint8_t in1, uint8_t in2) 
{
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
}


void MOTOR::
setTerminalCommands(
  uint8_t fr, uint8_t rev,
  uint8_t st, uint8_t frun) 
{
  comForward = fr;
  comReverse = rev;
  comHalt = st;
  comFreerun = frun;
}


void MOTOR::
serialTest() 
{
  if (Serial.available() > 0) {
    testChar = Serial.read() - '0';

    if (testChar != 218) {// Don't run if newline
      Serial.print(testChar);
      
      if (testChar == comForward) {
        forward();
        Serial.println("-forward");
        
      } else if (testChar == comReverse) {
        reverse();
        Serial.println("-reverse");
        
      } else if (testChar == comHalt) {
        halt();
        Serial.println("-halt");
        
      } else if (testChar == comFreerun) {
        freerun();
        Serial.println("-freerun");
        
      } else{
        Serial.println("-invalid command");
      }

      // Wait until serial is not available
      while (Serial.available() > 0);
    }
  }
}
