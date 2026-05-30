int ledpin =A1;
int krita =0;
const int enA = 9;
const int in1 = 8;
const int in2 = 7;

int ledout =0;

const int trigPin = 11;
const int echoPin = 10;

// Variables
long duration;
int distance;

void setup() {
  pinMode(8,OUTPUT);
pinMode(12,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Set direction: Forward
 
  digitalWrite(in2, LOW);

  Serial.begin(9600); // For debugging via Serial Monitor
}

void loop() {  int motorSpeed = 127; 
  analogWrite(enA, motorSpeed);

  // 1. Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. Trigger the sensor (10 microsecond pulse)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. Read the echoPin (returns the sound wave travel time)
  duration = pulseIn(echoPin, HIGH);

  // 4. Calculate distance in cm
  // Speed of sound is 0.034 cm/us. Divide by 2 (out and back)
  distance = duration * 0.034 / 2;

  // 5. Motor Control Logic
  if (distance > 0 && distance <= 10) {
    // Object detected within 10cm - STOP
    digitalWrite(in1, LOW);
    Serial.print("STOPPED! Object at: ");
  } else {
    // Path clear - RUN
    digitalWrite(in1, HIGH);
    Serial.print("Running. Distance: ");
  }

  Serial.println(distance);
  ledout =analogRead(ledpin);
Serial.println(ledout);
if(ledout <=500){
  digitalWrite(8,HIGH);
  
}else digitalWrite(8,LOW);
if(ledout >500){
  digitalWrite(12,HIGH);
  
}else digitalWrite(12,LOW);
  // Small delay to stabilize readings
  delay(100);
}
