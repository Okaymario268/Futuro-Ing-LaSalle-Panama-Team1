Hello, here we gonna upload all the code that we made for the Future Enginner 2024 of the Team #1 of the Colegio De La Salle

**Materials**
  - Pixy Cam2
  - Protoboard
  - Btn7960
  - Dc Motor 
  - Servo motor 10kg
  - Battery Lipo 7.4v
  - Switch
  - Button
  - Ultra sonic sensor
  - Arduino Mega

First we start with the battery, to this we connect 2 cables, one positive (red) and one negative (black), the positive is connected to the switch, and at the other end of this we connect another cable to the btn7960 (Port B+), while the battery gnd cable is connected directly to the btn7960 (Port B-)

In the Btn7960 the positive and negative cables of the motor were connected to their respective ports (M+ for positive, M- for negative),

In the B+ and B- ports we connected an adapter cable to power the arduino board, taking advantage of the arduino's built-in voltage regulator

In the Btn7960 8 cables were connected to the ports, Vcc, Gnd, R_Irs, L _Irs, RPWM, LPWM, L_En, R_En to the arduino, these cables will supply power to this component and allow it to control the speed of the motor

On the board arduino we connected our Servo Motor, the pixy cam and the 3 ultrasonics, each one to their respective ports.

**Setbacks**

We had to change the previous motor due to its energy consumption and weight, and we also changed the 4 batteries in series that we used for a rechargeable lipo battery

The entire design of the motor gears had to be rebuilt since a differential was used

The size of the wheels was reduced to be able to fit the ultrasonics

The acrylic base broke and had to be glued with a metal sheet

We almost burned the new motor, with the new battery in one of the tests

**Motivation**

The motivation to participate in the WRO of 2024, was only one, to be able to experiment for the first time and represent the school in the category of future engineers and thus be able to give a base to the future participants of this school to encourage future young people after us to participate and implement robotics in Panama

**Code Explanation**

In the first lines of the code, we import the arduino libraries that we will use in addition to defining all the pins of the electronic components, outside of void setup(), then in this function we will initialize the components and reset all the variables used

In void loop(), we get the distances recorded by the ultrasonic sensors and we get the image from the pixycam, to process it in if conditionals

If the camera detects the yellow color, this will indicate to the bot to start the turn and increase the speed to be able to make the turn correctly, and then the blue line will be detected to regulate the speed and rotation of the servo motor to the default

In such case that nothing is detected with the camera, the ultrasonics will be used to detect obstacles and be able to avoid them

In each successful turn that the robot makes, this will accumulate up to 12 to be able to start the automatic shutdown and thus end the round
  
