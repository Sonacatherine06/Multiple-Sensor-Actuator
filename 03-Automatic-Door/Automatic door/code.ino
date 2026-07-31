#include <Servo.h>

Servo door;

int trigPin = 7;
int echoPin = 6;
int pirPin = 2;
int buzzerPin = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  door.attach(9);

  // Door initially closed
  door.write(0);
}

void loop() {

  // Send ultrasonic signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Calculate distance
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Read PIR
  int motion = digitalRead(pirPin);

  // If person is near AND motion is detected
  if (distance < 50 && motion == HIGH) {

    // Open door
    door.write(90);

    // Buzzer ON
    digitalWrite(buzzerPin, HIGH);

    delay(500);

    // Buzzer OFF
    digitalWrite(buzzerPin, LOW);
  }

  else {

    // Close door
    door.write(0);

    // Buzzer OFF
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}