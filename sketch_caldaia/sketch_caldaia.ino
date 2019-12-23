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
int const mapThr = 35;

int const seconds = 1000;
int const minutes = 60 * seconds;
int const timeToWait = N * seconds;

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
  myServo.write(90);

  delay(5000);
}

void loop() {

  int rawVal = analogRead(inputPin);
  int mapVal = map(rawVal, 0, 1023, mapMin, mapMax);

  Serial.print("rawVal: ");
  Serial.print(rawVal);
  Serial.print(" mapVal: ");
  Serial.println(mapVal);

  // boolean flag to have the servo wait once set at tempHi
  bool isOn = false;
  
  int tempToGo = tempLo;
  if (tempLo < tempLoBound) {
    tempToGo = tempLoBound;
  }
  if (mapVal > mapThr) {
    Serial.println("mapped value is above threshold!");
    if (tempHi < tempHiBound) {
      tempToGo = tempHi;
    }
    else {
      tempToGo = tempHiBound;
    }
    isOn = true;
  }
  else Serial.println("mapped value is below threshold :(");

  int angleToGo = map(tempToGo, knobLoBound, knobHiBound, 180, 0);
  myServo.write(angleToGo);
  
  if (isOn) {
    delay(timeToWait);
  }
  
  delay(1000);
}
