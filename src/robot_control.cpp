/**
 * robotics_2103 - Robot Control Script
 * This script handles a line-following robot with basic movement functions.
 */

#include <Arduino.h>

// Motor Pin Definitions
const int LEFT_MOTOR_SPEED = 5;
const int LEFT_MOTOR_DIR = 4;
const int RIGHT_MOTOR_SPEED = 6;
const int RIGHT_MOTOR_DIR = 7;

// Line Sensor Pin Definitions
const int SENSOR_LEFT = A0;
const int SENSOR_CENTER = A1;
const int SENSOR_RIGHT = A2;

// Threshold for line detection
const int THRESHOLD = 500;

void setup() {
  // Initialize Motor Pins
  pinMode(LEFT_MOTOR_SPEED, OUTPUT);
  pinMode(LEFT_MOTOR_DIR, OUTPUT);
  pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);

  // Initialize Sensor Pins
  pinMode(SENSOR_LEFT, INPUT);
  pinMode(SENSOR_CENTER, INPUT);
  pinMode(SENSOR_RIGHT, INPUT);

  Serial.begin(9600);
  Serial.println("Robot Initialized");
}

/**
 * Move the robot straight
 */
void goStraight(int speed) {
  digitalWrite(LEFT_MOTOR_DIR, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, speed);
  digitalWrite(RIGHT_MOTOR_DIR, HIGH);
  analogWrite(RIGHT_MOTOR_SPEED, speed);
}

/**
 * Turn the robot left
 */
void turnLeft(int speed) {
  digitalWrite(LEFT_MOTOR_DIR, LOW);
  analogWrite(LEFT_MOTOR_SPEED, speed);
  digitalWrite(RIGHT_MOTOR_DIR, HIGH);
  analogWrite(RIGHT_MOTOR_SPEED, speed);
}

/**
 * Turn the robot right
 */
void turnRight(int speed) {
  digitalWrite(LEFT_MOTOR_DIR, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, speed);
  digitalWrite(RIGHT_MOTOR_DIR, LOW);
  analogWrite(RIGHT_MOTOR_SPEED, speed);
}

/**
 * Stop the robot
 */
void stopRobot() {
  analogWrite(LEFT_MOTOR_SPEED, 0);
  analogWrite(RIGHT_MOTOR_SPEED, 0);
}

void loop() {
  int valLeft = analogRead(SENSOR_LEFT);
  int valCenter = analogRead(SENSOR_CENTER);
  int valRight = analogRead(SENSOR_RIGHT);

  // Simple Line Following Logic
  if (valCenter > THRESHOLD) {
    goStraight(150);
  } else if (valLeft > THRESHOLD) {
    turnLeft(150);
  } else if (valRight > THRESHOLD) {
    turnRight(150);
  } else {
    stopRobot();
  }

  delay(10);
}
