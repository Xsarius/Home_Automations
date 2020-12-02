#include <Arduino.h>       // Standard arduino library
#include "stepper_motor.h" // Enables stepper motors movement
#include "config.h"        // Configuration settings

extern stepper_28BYJ_48 motor1;
extern stepper_28BYJ_48 motor2;

extern int current_steps;
extern int current_target_steps;
extern int target_steps;

extern char load[3];

void getTarget(char *, byte *, unsigned int);
void motorPinSetup();
void lowerMotorPins();
