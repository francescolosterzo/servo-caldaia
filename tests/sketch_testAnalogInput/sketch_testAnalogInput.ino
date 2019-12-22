/* 
 * This sketch is to test the very first step of the servo-caldaia:
 * receive an analog input
 */

// declare the pin
int pin = A0;

void setup() {
  
  // init the serial port
  Serial.begin(9600);
}

void loop() {

  int rawValue = analogRead(pin);
  int mapValue = map(rawValue,0,1023,0,100);
  
  Serial.print("raw value:");
  Serial.print(rawValue);
  Serial.print(" mapped value:");
  Serial.println(mapValue);

  delay(2000);
}
