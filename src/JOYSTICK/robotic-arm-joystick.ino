/*
  Robotic Arm using joystick by Jorge
  Based on "How to control 2 servos using a joystick?" by ebotics
*/

/*LIBRARIES*/

// servo library
#include <Servo.h>

/*JOYSTICKS*/

// Base & Shoulder joystick
int joyA_ReadX = 0;        // X-axis reading
int joyA_ReadY = 0;        // Y-axis reading
int joyA_X = A0;           // X-axis analog pin A0
int joyA_Y = A1;           // Y-axis analog pin A1

// Elbow & Hand joystick
int joyB_ReadX = 0;        // X-axis reading
int joyB_ReadY = 0;        // Y-axis reading
int joyB_X = A2;           // X-axis analog pin A2
int joyB_Y = A3;           // Y-axis analog pin A3
const int joyB_SW = 2;     // Joystick button. Used to control the clamp

/*SERVOS*/

// Base
Servo BASE;                // Base servo
int BASE_DEGREES = 0;      // Base servo degrees

// Shoulder
Servo SHOULDER;            // Shoulder servo
int SHOULDER_DEGREES = 0;  // Shoulder servo degrees

// Elbow
Servo ELBOW;               // Elbow servo
int ELBOW_DEGREES = 0;     // Elbow servo degrees

// Hand
Servo HAND;                // Hand servo
int HAND_DEGREES = 0;      // Hand servo degrees

/*FUNCTIONS*/

void startingpos () {      // Set servos starting position

  BASE.write (0);
  SHOULDER.write (0);
  ELBOW.write (0);
  HAND.write (0);

}

void setup () {

  /*SERVOS*/

  startingpos ();

  // Base
  BASE.attach (3);         //Base servo attach to PWM/digital pin 3

  // Shoulder
  SHOULDER.attach (4);     //Shoulder servo attach to PWM/digital pin 4

  // Elbow
  ELBOW.attach (5);        //Elbow servo attach to PWM/digital pin 5

  // Hand
  HAND.attach (6);         //Hand servo attach to PWM/digital pin 6

}

void loop () {

  /*ANALOG READS*/

  // Joystick values. Ranges from 0 to 1023
  joyA_ReadX = analogRead (joyA_X);                      // X-axis reading from Base & Shoulder joystick
  joyA_ReadY = analogRead (joyA_Y);                      // Y-axis reading from Base & Shoulder joystick
  joyB_ReadX = analogRead (joyB_X);                      // X-axis reading from Elbow & Hand joystick
  joyB_ReadY = analogRead (joyB_Y);                      // Y-axis reading from Elbow & Hand joystick

  /*VALUES SCALING*/

  joyA_ReadX = map (joyA_ReadX, 0 , 1023, 0, 180);       // Base servo degrees
  joyA_ReadY = map (joyA_ReadY, 0 , 1023, 0, 180);       // Shoulder servo degrees
  joyB_ReadX = map (joyB_ReadX, 0 , 1023, 0, 180);       // Elbow servo degrees
  joyB_ReadY = map (joyB_ReadY, 0 , 1023, 0, 180);       // Hand servo degrees

  /*SEND VALUES TO SERVOS*/

  BASE.write(joyA_ReadX);                                // Move base servo according to the analog reading
  SHOULDER.write(joyA_ReadY);                            // Move shoulder servo according to the analog reading
  ELBOW.write(joyB_ReadX);                               // Move elbow servo according to the analog reading
  HAND.write(joyB_ReadY);                                // Move hand servo according to the analog reading

  /*TIME BETWEEN ACTION AND ACTION*/

  delay(15);                                             // This waiting time serves to keep the arm from moving abruptly

}
