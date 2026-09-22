#include <Servo.h>

Servo myServo;

// PIN SETUP
void setup()
{
  myServo.attach(9);
}

// LOOP
void loop()
{
  myServo.write(90);
  delay(2000);

  myServo.write(0);
  delay(2000);

  myServo.write(90);
  delay(2000);

  myServo.write(180);
  delay(2000);

}
