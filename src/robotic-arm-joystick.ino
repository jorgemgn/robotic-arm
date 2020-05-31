/**
 * Robotic Arm using joystick by Jorge
 * Based on "How to control 2 servos using a joystick?" by ebotics
 */
#include <Servo.h>

// Analog pins
#define JOYA_X A0 // Joystick A X-axis analog pin A0
#define JOYA_Y A1 // Joystick A Y-axis analog pin A1
#define JOYB_X A2 // Joystick B X-axis analog pin A2
#define JOYB_Y A3 // Joystick B Y-axis analog pin A3

// Scale bounding
#define FROM_HIGH 1023
#define FROM_LOW 0
#define TO_LOW 0
#define TO_HIGH 180

// Servo PWM/digital pins
#define BASE_PWM_PIN 4
#define SHOULDER_PWM_PIN 3
#define ELBOW_PWM_PIN 5
#define HAND_PWM_PIN 6
#define CLAMP_PWM_PIN 7

// Positions
#define INIT_POSITION 0

// Base & Shoulder joystick
int joyA_ReadX = 0; // X-axis reading
int joyA_ReadY = 0; // Y-axis reading

// Elbow & Hand joystick
int joyB_ReadX = 0; // X-axis reading
int joyB_ReadY = 0; // Y-axis reading
const int JOYB_SW = 2;     // Joystick button. Used to control the clamp
int JOYB_SW_state = 0;     // Joystick button state

// Declare servos
Servo BASE;
Servo SHOULDER;
Servo ELBOW;
Servo HAND;
Servo CLAMP;

// Set servos starting position
void initServoPositions () {      
  BASE.write(INIT_POSITION);
  SHOULDER.write(INIT_POSITION);
  ELBOW.write(INIT_POSITION);
  HAND.write(INIT_POSITION);
  CLAMP.write(INIT_POSITION);
}

void setup () {
  initServoPositions();

  // Base servo attach to PWM/digital pin 3
  BASE.attach(BASE_PWM_PIN);    

  // Shoulder servo attach to PWM/digital pin 4
  SHOULDER.attach(SHOULDER_PWM_PIN);

  // Elbow servo attach to PWM/digital pin 5
  ELBOW.attach(ELBOW_PWM_PIN);    

  // Hand servo attach to PWM/digital pin 6
  HAND.attach(HAND_PWM_PIN);   
  
  // CLAMP servo attach to PWM/digital pin 7
  CLAMP.attach(CLAMP_PWM_PIN);   
}

void loop () {
  // Joystick values (0-1023)
  joyA_ReadX = analogRead(JOYA_X); // X-axis reading from Base & Shoulder joystick
  joyA_ReadY = analogRead(JOYA_Y); // Y-axis reading from Base & Shoulder joystick
  joyB_ReadX = analogRead(JOYB_X); // X-axis reading from Elbow & Hand joystick
  joyB_ReadY = analogRead(JOYB_Y); // Y-axis reading from Elbow & Hand joystick

  // Scaling
  joyA_ReadX = map(joyA_ReadX, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH); // Base servo degrees
  joyA_ReadY = map(joyA_ReadY, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH); // Shoulder servo degrees
  joyB_ReadX = map(joyB_ReadX, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH); // Elbow servo degrees
  joyB_ReadY = map(joyB_ReadY, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH); // Hand servo degrees

  // Send calculated values to servos
  BASE.write(joyA_ReadX);     // Move base servo according to the analog reading
  SHOULDER.write(joyA_ReadY); // Move shoulder servo according to the analog reading
  ELBOW.write(joyB_ReadX);    // Move elbow servo according to the analog reading
  HAND.write(joyB_ReadY);      // Move hand servo according to the analog reading
 
  // Clamp control
  JOYB_SW_state = digitalRead (JOYB_SW);                  // Move hand servo according to the Elbow & Hand joystick button reading

  if (JOYB_SW_state == HIGH) {
    CLAMP.write (90);                                      // If button state is high, Hand servo turn 90 degrees
  }
  else {
    CLAMP.write (0);                                       // If button state is low, Hand servo return to low position
  }  

  // keep the arm from moving abruptly
  delay(150);
}

