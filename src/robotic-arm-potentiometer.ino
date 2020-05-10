/**
 * Robotic Arm using potentiometer by Jorge  
 * Based on "How to Move Your 4 Servos Robot using Potentiometers?" by Zenent Robotic
 */
#include <Servo.h>

// Potentiometers
#define BASE_POT 0    
#define SHOULDER_POT 1
#define ELBOW_POT 2   
#define HAND_POT 3    

// Servo pins
#define BASE_PIN 2
#define SHOULDER_PIN 2
#define ELBOW_PIN 2
#define HAND_PIN 2

// Potentiometer values
int BASE_VAL;
int SHOULDER_VAL; 
int ELBOW_VAL; 
int HAND_VAL;

// Servos
Servo BASE;
Servo SHOULDER;
Servo ELBOW;
Servo HAND;

void setup () {
  BASE.attach(BASE_PIN);
  SHOULDER.attach(SHOULDER_PIN);
  ELBOW.attach(ELBOW_PIN);
  HAND.attach(HAND_PIN);
}

void loop () {
  // Read potentiometers (range 0-1023)
  BASE_VAL = analogRead(BASE_POT);
  SHOULDER_VAL = analogRead(SHOULDER_POT);
  ELBOW_VAL = analogRead(ELBOW_POT);
  HAND_VAL = analogRead(HAND_POT);

  // Scaling
  BASE_VAL = map(BASE_VAL, 0 , 1023, 0, 180);
  SHOULDER_VAL = map(SHOULDER_VAL, 0 , 1023, 0, 180);
  ELBOW_VAL = map(ELBOW_VAL, 0 , 1023, 0, 180);
  HAND_VAL = map(HAND_VAL, 0 , 1023, 110, 180);

  // Send values to servos
  BASE.write(BASE_VAL);
  SHOULDER.write(SHOULDER_VAL);
  ELBOW.write(ELBOW_VAL);
  HAND.write(HAND_VAL);

  delay(15);
}
