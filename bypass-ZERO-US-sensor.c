// PIN CONFIG
const int trigPin = 9;
const int echoPin = 10;
float duration, distance, liveDistance;

// SETUP PIN MODE
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

// <----CUSTOM FUNCTION---->
float captureDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 30000 us timeout = ~5m max range
  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) return -1;   // -1 means "no valid reading"

  return (duration * 0.0343) / 2;
}

float lastGoodDistance = 100;  // start in "green" zone

// LOOP
void loop()
{
float d = captureDistance();

  if (d > 0) {
    lastGoodDistance = d;        // only update on valid reads
  }
  liveDistance = lastGoodDistance;   // gives last valid reading into output when there are values like 0. 

  Serial.print("Distance: ");
  Serial.println(liveDistance);

}
