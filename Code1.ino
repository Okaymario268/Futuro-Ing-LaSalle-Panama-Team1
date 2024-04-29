#include <Stepper.h>
#include <Ultrasonic.h>
#include <HCSR04.h>
#include <Servo.h>

int RevolutionPereSec = 60; /// Revolution of the stepper motor
int StepperSpeed = 150; // Speed for the stepper motor
int StepperSideSPeed = 80;

int StepperPin1 = 8;
int StepperPin2 = 9;
int StepperPin3 = 10;
int StepperPin4 = 11;

int ServoPin  = 7;

Servo Servo1;

Stepper Motor1 (RevolutionPereSec,StepperPin1,StepperPin2,StepperPin3,StepperPin4);
HCSR04 LeftUltrasonic (5,4);
HCSR04 RightUltrasonic(12,13);

int TurnServo(int Degrees) {
  Servo1.write(Degrees);
}
 
void Forward() {
  Motor1.step(StepperSpeed);
}

void setup() {
  Serial.begin(9600);
  Servo1.attach(ServoPin);
  Motor1.setSpeed(StepperSpeed);

}

 


void loop() {
  int LeftSonicDistance = LeftUltrasonic.dist();
  int RightSonicDistance = RightUltrasonic.dist();

  if (LeftSonicDistance <=5 or RightSonicDistance <=5 ) {
    if (LeftSonicDistance > RightSonicDistance) {
      TurnServo(180);
    } // Turn to the left
    else {
      TurnServo(-180);
    }// Turn to the right
  } 
  else {
    Forward();
  }
   
   
  
}
