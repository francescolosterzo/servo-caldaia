#include <Servo.h>

Servo myServo;
int const servoPin = 9;

void setup() {

  myServo.attach(servoPin);

  // go to mid-point by default
  myServo.write(90);

  delay(5000);

  
}

void loop() {

  myServo.write(0);

  delay(2000);
  
  myServo.write(90);

  delay(2000);

  myServo.write(180);

  delay(2000);

  /*
  // to explore range
  myServo.write(0);

  delay(2000);

  myServo.write(180);

  delay(2000);
  */

}
