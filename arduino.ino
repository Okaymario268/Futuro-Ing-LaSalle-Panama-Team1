#include <Servo.h>
#include <HCSR04.h>
#include <Pixy2.h>

 

//int MotorPin = 1; // control with the l298n
 

int LeftSensorPinTrig =  3;
int LeftSensorPinEcho =  4;

int RightSensorPinTrig =  5;
int RightSensorPinEcho =  6;

int FrontSensorPinTrig =  7;
int FrontSensorPinEcho =  8; 

int FrontDistanceRange = 15;

int ServoPin = 9;

// set the rotation of the servo
int LeftServoRotation = 50;
int RightServoRotation = 100;
int CenterServoRotation = 85;


int RedColorSignature = 1;
int GreenColorSignature = 4;

bool BotInLeft = false; // the direction of the bot is left
bool BotInRight = false; // the direction of the bot is  Right

bool EnablePixyCam = false;

HCSR04 LeftSensor (LeftSensorPinTrig,LeftSensorPinEcho);
HCSR04 RightSensor (LeftSensorPinTrig,RightSensorPinEcho);
HCSR04 FrontSensor (FrontSensorPinTrig,FrontSensorPinEcho);
Servo servo;
Pixy2 pixy;
//init the car
void setup() {
  pinMode(LeftSensorPinEcho,OUTPUT);
  pinMode(RightSensorPinEcho,OUTPUT);
  pinMode(FrontSensorPinEcho,OUTPUT);

  Serial.begin(9600);

 // pinMode(MotorPin,OUTPUT);

 //servo.attach(ServoPin);
 
 pixy.init(); // enable pixycam
  

}
 



void loop () {
  int FrontDistance = FrontSensor.dist();
  int LeftDistance = LeftSensor.dist();
  int RightDistance = RightSensor.dist(); /// get the distance of the ultrasonic sensor
  pixy.ccc.getBlocks();
  Serial.println(FrontDistance);

    // compare distance
    if ( FrontDistanceRange >=FrontDistance  ) {
      //servo.write(CenterServoRotation);
     
        if (LeftDistance < RightDistance) {
             //servo.write(LeftServoRotation);
             Serial.println("Left");
        }
        else {
          // Serial.println("Right");
           // servo.write(RightServoRotation);
        }
    }  
    else {
       // servo.write(CenterServoRotation);
    }




}