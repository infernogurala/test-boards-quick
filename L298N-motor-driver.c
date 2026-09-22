// Motor A pins
const int enA = 5; // UST BE CONNECTED TO PWM, controls the speed
const int in1 = 3;  // Controls the direction of rotation 
const int in2 = 4;
#define speed 200

// Motor B pins
const int enB = 6; //  <---MUST BE CONNECTED TO PWM, controls the speed--->
const int in3 = 7;
const int in4 = 8;

//SETUP PINS
void setup()
{
    // Set all motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speed);
}
