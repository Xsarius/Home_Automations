#include "handle_input.h"

stepper_28BYJ_48 motor1;
stepper_28BYJ_48 motor2;

void getTarget(char* topic, byte* payload, unsigned int length) 
{

  char load[3];
  
  // Output the first character of the message to serial (debug)
  for(int i = 0 ; i < 3;i++)
  {
  load[i] = (char)payload[i];
  Serial.print(load[i]);
  }
  Serial.println("");

  String stringOne = load;
  int temp = stringOne.toInt();
  current_target_steps = (float)temp / (float)100 * MAX_STEPS;  // percentage to STEPS
  
  payload[1] = 'a';
  payload[2] = 'a';
}

void motorPinSetup()
{

// Sets motors I/O //

  // Motor 1 
  motor1.pin1 = MOTOR1_PIN1;
  motor1.pin2 = MOTOR1_PIN2;
  motor1.pin3 = MOTOR1_PIN3;
  motor1.pin4 = MOTOR1_PIN4;
  
  // Motor 2
  motor2.pin1 = MOTOR2_PIN1;
  motor2.pin2 = MOTOR2_PIN2;
  motor2.pin3 = MOTOR2_PIN3;
  motor2.pin4 = MOTOR2_PIN4;

  motor1.setUp(motor1.pin1, motor1.pin2, motor1.pin3, motor1.pin4);
  motor2.setUp(motor2.pin1, motor2.pin2, motor2.pin3, motor2.pin4);
}

void lowerMotorPins()
{
  // Motor 1 pins
  digitalWrite(MOTOR1_PIN1,LOW);
  digitalWrite(MOTOR1_PIN2,LOW);
  digitalWrite(MOTOR1_PIN3,LOW);
  digitalWrite(MOTOR1_PIN4,LOW);

  // Motor 2 pins
  digitalWrite(MOTOR2_PIN1,LOW);
  digitalWrite(MOTOR2_PIN2,LOW);
  digitalWrite(MOTOR2_PIN3,LOW);
  digitalWrite(MOTOR2_PIN4,LOW);

}