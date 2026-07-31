#include <Servo.h>

const int soilPin = A0;
const int tempPin = A1;

const int motorPin = 8;
const int servoPin = 9;

Servo valve;

void setup() {
  Serial.begin(9600);

  pinMode(motorPin, OUTPUT);

  valve.attach(servoPin);
  valve.write(0);

  digitalWrite(motorPin, LOW);
}

void loop() {

  // Read soil moisture
  int soilValue = analogRead(soilPin);

  // Read TMP36 temperature
  int tempReading = analogRead(tempPin);

  // Convert analog reading to voltage
  float voltage = tempReading * (5.0 / 1023.0);

  // Convert voltage to temperature in Celsius
  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // If soil is dry
  if (soilValue < 500) {

    // Turn ON water pump
    digitalWrite(motorPin, HIGH);

    // Open valve
    valve.write(90);

  } else {

    // Turn OFF water pump
    digitalWrite(motorPin, LOW);

    // Close valve
    valve.write(0);
  }

  delay(1000);
}