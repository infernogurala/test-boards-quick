// PIN CONFIG
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

// ROOM TEMP (accurate measurement)
float ambientTemperature = 20.0; 

// PIN SETUP
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send a 10-microsecond HIGH pulse to trigger the sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echo pulse duration in microseconds
  long durationMicros = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate speed of sound in cm per microsecond based on temperature
  // Formula: (331.3 + 0.606 * T) * 100 cm / 1,000,000 us
  float speedOfSound = (331.3 + (0.606 * ambientTemperature)) * 0.0001;
  
  // Calculate distance (divide by 2 for the round trip)
  float distanceCm = (durationMicros * speedOfSound) / 2.0;
  
  // Print results
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  delay(500); // Wait 500ms before next reading
}
