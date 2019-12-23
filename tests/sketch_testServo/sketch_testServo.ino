#include <Servo.h>

int const switchPin = A0;

Servo myServo;
int const servoPin = 9;

void setup() {

  myServo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {

  int rawVal = analogRead(switchPin);
  int mapVal = map(rawVal, 0, 1023, 0, 100);

  Serial.print("rawVal: ");
  Serial.print(rawVal);
  Serial.print(" mapVal: ");
  Serial.println(mapVal);

  //myServo.write(0);
  /*
  if (mapVal > 30) {
    myServo.write(90);
  }
  else {
    myServo.write(0);
    delay(2000);

    myServo.write(180);
    delay(2000);
  }
  */

  /*   
  // test
  myServo.write(0);

  delay(2000);
  
  myServo.write(90);

  delay(2000);

  myServo.write(180);

  delay(2000);
  */
  

  // to explore range
  myServo.write(0);

  delay(2000);

  myServo.write(90);

  delay(2000);

  myServo.write(180);

  delay(2000);

}
