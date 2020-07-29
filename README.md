[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](./LICENSE.md)

# Robotic Arm

Control of a robotic arm (allowing four freedom degrees).

![robotic-arm](images/robotic-arm.gif)

### A bit of theory

- [Theory](THEORY.md)

### Materials

- 1 x Arduino UNO  
  <img src="images/arduino-uno.jpg" width="100"/>  

- 1 x Servo SG90  
  <img src="images/servo-sg90.jpg" width="100"/>

- 4 x 10K potentiometer  
  <img src="images/10k-potentiometer.jpg" width="100"/>
  
- 2 x Axes joystick  
  <img src="images/joystick.jpg" width="100"/>
  
- 1 x Kit jumpers  
  <img src="images/dupont.jpg" width="100"/>
  
- 1 x Protoboard  
  <img src="images/protoboard.jpg" width="100"/>
  
- 2 x 9V Battery (1 x 9V battery per Arduino UNO; and 1 x 9V battery per servos)  
  <img src="images/9v_battery.jpg" width="100"/>
  
- 1 x Voltage regulator (Used to reduce the 9V battery to the 6V admitted by the SG90 Servo)  
  <img src="images/voltage-regulator.jpg" width="100"/>

### Control modes

- [Using two joysticks | 2 x servos per joystick](./src/robotic-arm-joystick.ino)
- [Using four potentiometers | 1 x servo per potentiometer](./src/robotic-arm-potentiometer.ino)
  
### Wiring diagram

<img src="images/wiring-diagram-potentiometer.png" alt="Using four potentiometers" width="600"/>
<img src="images/wiring-diagram-joystick.png" alt="Using two joysticks" width="600"/>
