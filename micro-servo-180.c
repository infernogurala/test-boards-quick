#include <Servo.h>

Servo myServo;
int angle = 0;

// PIN SETUP
void setup()
{
  myServo.attach(9);
}

// LOOP
void loop()
{
for(angle = 0; angle <= 180; angle++)
  {
  myServo.write(angle);
  delay(15);
  }
for(angle = 180; angle >= 0; angle--)
  {
  myServo.write(angle);
  delay(15);
  }

}
