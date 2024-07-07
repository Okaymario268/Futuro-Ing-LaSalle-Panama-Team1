#include <Servo.h>
#include <HCSR04.h>
#include <Pixy2.h>

int MotorPin1 = 3; // control with the l298n
int MotorPin2 = 4;
int ServoPin = 12; // pin of the servo motor

// Define the pins for the ultrasonic sensors
int LeftSensorPinTrig =  9;
int LeftSensorPinEcho =  8;

int RightSensorPinTrig =  10;
int RightSensorPinEcho =  11;
int FrontSensorPinTrig =  7;
int FrontSensorPinEcho =  6; 

// button pin
int ButtonPin = 2;

// Set the max range for the ultrasonic
int FrontDistanceRange = 35;
int LeftDistanceRange = 50;
int RightDistanceRange = 50;

// set the rotation of the servo
int LeftServoRotation = 180;
int RightServoRotation = 0;
int CenterServoRotation = 100;
// Signature for the pixy cam
int RedColorSignature = 1;
int GreenColorSignature = 4;

bool BotInRotation = false;
bool ButtonPressed = false;

HCSR04 LeftSensor (LeftSensorPinTrig, LeftSensorPinEcho);
HCSR04 RightSensor (RightSensorPinTrig, RightSensorPinEcho);
HCSR04 FrontSensor (FrontSensorPinTrig, FrontSensorPinEcho);
Servo servo;
//Pixy2 pixy;

//init the car

void MotorForward() {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
}

void MotorBackward() {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
}

void ServoRotation(int Angle) {
  if (BotInRotation == false) {
        servo.write(CenterServoRotation);
  }
  servo.write(Angle);
  MotorBackward();
} 

void setup() {
  Serial.begin(9600);
  Serial.println("Setup Working");
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(ButtonPin, INPUT);
   
  servo.attach(ServoPin);
  ServoRotation(CenterServoRotation);
  Serial.println("Setup Complete");
 // pixy.init(); // enable pixycam
}

void loop() {
    while (ButtonPressed == false) {
      int buttonState = digitalRead(ButtonPin);
      delay(50); // debounce delay
      if (buttonState == LOW) {
        ButtonPressed = true;
        Serial.println("Button Pressed");
      }
    }
  int FrontDistance = FrontSensor.dist() ;
  int LeftDistance = LeftSensor.dist() ;
  int RightDistance = RightSensor.dist() ; // get the distance of the ultrasonic sensor
 

  bool RedBlockDetected = false;
  bool GreenBlockDetected = false;
   
  //pixy.ccc.getBlocks();
  //if (pixy.ccc.numBlocks) {
    //for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      //if (pixy.ccc.blocks[i].m_signature == RedColorSignature) {
        //RedBlockDetected = true;
      //} /// Camera detecting red
      //else if (pixy.ccc.blocks[i].m_signature == GreenColorSignature) {
        //GreenBlockDetected = true;
     // } /// Camera detecting green
    //}
  //}
    Serial.print("Front Distance: ");
  Serial.println(FrontDistance);
  Serial.print("Left Distance: ");
  Serial.println(LeftDistance);
   Serial.print("Right Distance: ");
  Serial.println(RightDistance);
  if ((RedBlockDetected == true && BotInRotation == false) || 
      (GreenBlockDetected == true && BotInRotation == false)) {
    
    if (RedBlockDetected == true) {
      ServoRotation(RightServoRotation);
      Serial.println("Red Block Detected: Rotating Right");
    } else if (GreenBlockDetected == true) {
      ServoRotation(LeftServoRotation);
      Serial.println("Green Block Detected: Rotating Left");
    }
    BotInRotation = true;

  } else if (FrontDistance <= FrontDistanceRange && FrontDistance > 0) {
    
    Serial.println("Obstacle Detected Ahead");
    if (LeftDistance > RightDistance && LeftDistance < LeftDistanceRange) {
      BotInRotation = true;
       Serial.println("Turning Left");
      ServoRotation(LeftServoRotation);
      
    } // turn to left
    else if (RightDistance > LeftDistance && RightDistance < RightDistanceRange) {
      BotInRotation = true;
      Serial.println("Turning Right");
     ServoRotation(RightServoRotation);
       
    } // turn to right

  } else {
    if (BotInRotation == true) {
      BotInRotation = false;
      ServoRotation(CenterServoRotation);
      Serial.println("Resuming Forward Motion");
    }
  }

   delay(500);
  
}
