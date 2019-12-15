/*
 * sketch for controlling the servo-caldaia:
 * main logic:
 * - if analog input is below threshold: stay on angleLow
 * - else: go to angleHigh
 */

#include <Servo.h>
#include "config.h"

Servo myServo;
int const inputPin = A0;
int const servoPin = 9;
int const mapMin = 0;
int const mapMax = 100;
int const mapThr = 50;

void setup() {

  Serial.begin(9600);

  /*
  // DEBUG
  Serial.print("tempLow: ");
  Serial.print(tempLow);
  Serial.print(" tempHihg: ");
  Serial.println(tempHigh);
  */

  myServo.attach(servoPin);
  myServo.write(0);

  delay(5000);
}

void loop() {

  int rawVal = analogRead(inputPin);
  int mapVal = map(rawVal, 0, 1023, mapMin, mapMax);

  Serial.print("rawVal: ");
  Serial.print(rawVal);
  Serial.print(" mapVal: ");
  Serial.println(mapVal);

  int tempToGo = tempLow;
  if (mapVal > mapThr) {
    Serial.println("mapped value is above threshold!");
    tempToGo = tempHigh;
  }
  else Serial.println("mapped value is below threshold :(");

  int angle = map(tempToGo, 0, 90, 0, 179);
  myServo.write(angle);
  
  delay(1000);
}
