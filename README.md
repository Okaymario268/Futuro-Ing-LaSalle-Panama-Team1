Hello, here we gonna upload all the code that we made for the Future Enginner 2024 of the Team #1 of the Colegio De La Salle
Materials
  - Pixy Cam2
  - Protoboard
  - L298n
  - Dc Motor 775 Huagson
  - Servo motor 10kg
  - 4 pack of battery of 9v
  - Switch
  - Button
  - Ultra sonic
  - Arduino Uno
Design
  The Battery are atteched in serie to get more voltage total (36v total)
  Now positive cable of the baterry go to the switch and the gnd cable to the gnd port of the l298n, getting antoehr cable to the other
  port of the switch, so now if the switch is pressed it can desactivate/activate the energy of the bot
  After of this we cut some cables to put it in the ports of the motor to the Out1 and Out2 of the l298n to control it, with 4 cable extra
  1 to the gnd and and another to the 5v port of the l298n, and putting the rest of the cables to In1 and In2 to the ports 2 and 3 in the arduino board
  Allowing that we can control the motor with the board
  Now we connect all the ultrasonic and the pixycam to the arduino board
  All the echo and trig to the digital pins and vcc and gnd to the respective ports
  And the botton with 3 cables a gnd,5v,one to analog port

code explanation
  First we set all the pins to the sensors and motors
  and we set it in pinMode based on the need of the components

In the first lines of code are to detect the push of the button and start the code
Then we put an if conditional for the pixycam2 to detect the red and green color, and if everything fails the ultrasonics go to detect the distance first requiring the activation of the front sensor and then the side sensors allowing the rotation of the robot
  

    

  
  
