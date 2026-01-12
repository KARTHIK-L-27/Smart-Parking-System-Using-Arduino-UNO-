int trigPin = 9;
int echoPin = 10;

int greenLED = 6;
int redLED = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance < 10) { // Occupied
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  } else {             // Free
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }

  delay(500);
}
