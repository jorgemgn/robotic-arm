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

// Scale bounding
#define FROM_HIGH 1023
#define FROM_LOW 0
#define TO_LOW 0
#define HAND_TO_LOW 110
#define TO_HIGH 180

// Servo pins
#define BASE_PIN 2
#define SHOULDER_PIN 2
#define ELBOW_PIN 2
#define HAND_PIN 2

// Potentiometer values
int base_val;
int shoulder_val; 
int elbow_val; 
int hand_val;

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
  base_val = analogRead(BASE_POT);
  shoulder_val = analogRead(SHOULDER_POT);
  elbow_val = analogRead(ELBOW_POT);
  hand_val = analogRead(HAND_POT);

  // Scaling
  base_val = map(base_val, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);
  shoulder_val = map(shoulder_val, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);
  elbow_val = map(elbow_val, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);
  hand_val = map(hand_val, FROM_LOW, FROM_HIGH, HAND_TO_LOW, TO_HIGH);

  // Send values to servos
  BASE.write(base_val);
  SHOULDER.write(shoulder_val);
  ELBOW.write(elbow_val);
  HAND.write(hand_val);

  delay(15);
}
