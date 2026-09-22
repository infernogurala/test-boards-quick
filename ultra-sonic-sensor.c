// PIN CONFIG
const int trigPin = 9;
const int echoPin = 10;
float duration, distance;

void setup()
{
  pinMode(triPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
