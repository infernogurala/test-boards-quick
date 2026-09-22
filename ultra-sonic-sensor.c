// PIN CONFIG
const int trigPin = 9;
const int echoPin = 10;
float duration, distance, liveDistance;

// SETUP PIN MODE
void setup()
{
  pinMode(triPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

// <----CUSTOM FUNCTION---->
float captureDistance()
{
  digitalWrite(trigPin, LOW):
    delayMicroseconds(2);
  digitalWrite(trigPin, HIGH):
    delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
}

// LOOP
void loop()
{
  //get distance
  liveDistance = captureDistance();
  // print distance
  Serial.print("Distance: ");
  Serial.println(liveDistance);
}
