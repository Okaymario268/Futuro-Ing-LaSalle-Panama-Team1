Hello, here we gonna upload all the code that we made for the Future Enginner 2024 of the Team #1 of the Colegio De La Salle

### 1. *Materials*
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

### 2.*Setbacks*

We had to change the previous motor due to its energy consumption and weight, and we also changed the 4 batteries in series that we used for a rechargeable lipo battery

The entire design of the motor gears had to be rebuilt since a differential was used.

The size of the wheels was reduced to be able to fit the ultrasonics.

The acrylic base broke and had to be glued with a metal sheet.

We almost burned the new motor, with the new battery in one of the tests.

### 3. *Motivation*
The motivation for participating in WRO 2024 was clear and exciting: to experience the robotics competition for the first time and to represent our school in the future engineers category. We want to establish a solid foundation for future participants of our institution, inspiring young people to get involved in robotics and to promote its implementation in Panama.

### 4. *Code Explanation*

In the first lines of the code, we import the arduino libraries that we will use in addition to defining all the pins of the electronic components, outside of void setup(), then in this function we will initialize the components and reset all the variables used

In void loop(), we get the distances recorded by the ultrasonic sensors and we get the image from the pixycam, to process it in if conditionals

If the camera detects the yellow color, this will indicate to the bot to start the turn and increase the speed to be able to make the turn correctly, and then the blue line will be detected to regulate the speed and rotation of the servo motor to the default

In such case that nothing is detected with the camera, the ultrasonics will be used to detect obstacles and be able to avoid them

In each successful turn that the robot makes, this will accumulate up to 12 to be able to start the automatic shutdown and thus end the round
  
### 5. *Mobility Management*
Mobility management in this project focuses on the careful selection and implementation of motors, the design and mounting of the chassis, and the integration of all components to ensure optimal vehicle performance. The key engineering principles considered include speed, torque, power efficiency, and structural integrity.

### 6. *Motor Selection and Implementation*
   - *DC Motor 775 vs. 715:*
     - *Selection Process:*
       - The decision between the DC Motor 775 and the DC Motor 715 was based on the space constraints and performance requirements of the robot. Given the limited space, the 775 motor was chosen for its superior torque and speed capabilities.
     - *Pros of DC Motor 775:*
       - *Higher Torque and Speed:* The 775 motor can handle more amperage and voltage, delivering higher torque and speed, which is essential for the robot's performance.
       - *Built-in Ventilation:* The motor includes a cooling system, reducing the risk of overheating and extending the motor's lifespan.
       - *Easy Soldering:* The 775 motor's design facilitates easy soldering, simplifying the assembly process.
     - *Cons of DC Motor 775:*
       - *Weight and Size:* The 775 motor is relatively heavy and takes up more space, which could be challenging in a compact design.
       - *High Power Consumption:* It requires more voltage and amperage, which could lead to higher energy consumption and the need for a more robust power source.

   - *DC Motor 715:*
     - Although the 715 motor is more compact and fits easily within the vehicle, it was not chosen due to its lower torque, susceptibility to overheating, and fragility under high voltage. However, it remains a viable option for projects where space and power efficiency are more critical than raw performance.

### 7. *Implementation of Gear Systems*
   - *DC Motor 775:*
     - To convert the motor's high speed and torque into controlled movement, a gear system was implemented. A gear was attached to the motor shaft, meshing with another gear connected to the vehicle's wheels. This gear reduction system helps manage the speed and torque more effectively, ensuring smooth and efficient movement.
     - *Mounting Considerations:* Given the motor's weight, a sturdy mounting solution was necessary. A durable strap ("Suncho") was used to secure the motor to the chassis, preventing it from adding unnecessary weight while ensuring a firm attachment.

   - *Servo Motor 996R:*
     - *Selection Criteria:* The 996R servo was chosen for its ability to handle significant loads, making it ideal for steering and other precise movements.
     - *Gear System Integration:* Similar to the DC motor, a gear was attached to the servo shaft, with another gear on the wheels. This setup allows for accurate control over the vehicle's direction and turning radius.

### 8. *Chassis Design and Component Mounting*
   - *Chassis Selection:*
     - The chassis was selected to balance strength and weight, accommodating the heavier 775 motor while leaving enough room for other components. Its design allows for easy attachment of the motors and gear systems, while providing structural integrity.
     - *Mounting of Components:*
       - The motors, gears, and other components were strategically mounted to minimize weight distribution issues. The 775 motor was placed centrally to balance the vehicle's weight, while the servo motor was positioned to optimize steering control.
### 9. *Power and Sensor Management*
    - The power management system for the vehicle is centered around a 7.4V LiPo battery, selected for its lightweight design and high energy density, which ensures sufficient power to drive the DC Motor 775 and other components while maintaining overall vehicle performance. This battery was chosen over the previous setup of four batteries in series due to its more reliable power output and reduced weight, which were critical for achieving better balance and efficiency in the vehicle's operation. The vehicle's sensor array includes three ultrasonic sensors and a Pixy Cam2, selected for their precision and reliability in detecting obstacles and guiding the vehicle through challenges. The ultrasonic sensors are strategically mounted to detect objects and measure distances, allowing the vehicle to avoid collisions, while the Pixy Cam2 is utilized for color detection, enabling the vehicle to follow designated paths and make informed turns. The sensors are powered directly by the Arduino Mega, which receives regulated power from the LiPo battery via the BTN7960 motor driver. This setup ensures consistent power distribution to all sensors, minimizing power loss and maintaining stable operation throughout the vehicle’s tasks. Currently in the open challenge the camera is off to save energy
