// SETTINGS
#define servoPin 2      //SERVO

// LIBRARIES
#include <Servo.h>      //SERVO
Servo myservo;          //SERVO

void setup() {
  myservo.attach(servoPin);
}

void loop() {
  myservo.write(0);
  delay(500);
  myservo.write(45);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(135);
  delay(500);
}
