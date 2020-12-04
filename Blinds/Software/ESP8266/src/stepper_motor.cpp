#include "stepper_motor.h"

void stepper_28BYJ_48::setUp(int pin1, int pin2, int pin3, int pin4) 
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
};

void stepper_28BYJ_48::revolution(int count) 
{
  if( count > 0 ) {
    for (int i = 0; i < 8; i++)
    {
      setOutput(i);
      delay(motorStepDelay);
    }
    current_steps++;
  }
  
  else if( count < 0 ) {
    for (int i = 7; i >= 0; i--)
    {
      setOutput(i);
      delay(motorStepDelay);
    }
    current_steps--;
  }
};

void stepper_28BYJ_48::setOutput(int out) 
{
  digitalWrite(pin1, lookup[(0+out)%4]);
  digitalWrite(pin2, lookup[(1+out)%4]);
  digitalWrite(pin3, lookup[(2+out)%4]);
  digitalWrite(pin4, lookup[(3+out)%4]);
};



