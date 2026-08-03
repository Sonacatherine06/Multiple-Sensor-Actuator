# Smart Parking System

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that manages a smart parking gate. An ultrasonic sensor detects approaching vehicles, a button sets the parking status (full/empty), a servo operates the gate, and LEDs + buzzer provide status feedback.

---

## Description

This project implements a complete parking management system with:

- **HC-SR04 Ultrasonic Sensor (pins 9=Trig, 10=Echo):** Detects approaching vehicles.
- **Push Button (pin 2):** Toggle between "parking empty" and "parking full" modes.
- **Servo Motor (pin 3):** Opens/closes the gate barrier.
- **Green LED (pin 5):** Indicates parking is available.
- **Red LED (pin 6):** Indicates parking is full.
- **Buzzer (pin 8):** Audible alert when parking is full.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| HC-SR04 Ultrasonic Sensor | 1 | Vehicle detection |
| Push Button | 1 | Parking status toggle |
| Servo Motor (SG90) | 1 | Gate barrier |
| Green LED | 1 | Parking available indicator |
| Red LED | 1 | Parking full indicator |
| Buzzer | 1 | Full-parking alert |
| 220Ω Resistors | 3 | LED current limiting |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **9** | HC-SR04 (Trig) | Ultrasonic trigger |
| **10** | HC-SR04 (Echo) | Ultrasonic echo |
| **2** | Push Button | Parking status toggle (INPUT_PULLUP) |
| **3** | Servo | Gate control (PWM) |
| **5** | Green LED | Available indicator |
| **6** | Red LED | Full indicator |
| **8** | Buzzer | Alert output |

---

## How It Works

1. The ultrasonic sensor continuously measures the distance to the nearest object.
2. The push button toggles between "parking full" and "parking empty" states.
3. **If parking is NOT full:** Green LED on, red LED off, buzzer silent. When a car is detected within 15 cm, the gate opens (90°) for 3 seconds, then closes.
4. **If parking IS full:** Red LED on, green LED off, buzzer sounds continuously, and the gate stays closed.
5. Status is printed to the Serial Monitor every 200 ms.

---

## Working Principle

| Button State | Distance | Green LED (5) | Red LED (6) | Buzzer (8) | Servo (3) |
|---|---|---|---|---|---|
| Not full (HIGH) | < 15 cm | ON | OFF | OFF | Open (90°) → Close (0°) |
| Not full (HIGH) | ≥ 15 cm | ON | OFF | OFF | Closed (0°) |
| Full (LOW) | Any | OFF | ON | ON | Closed (0°) |

---

## Expected Output (Serial Monitor, 9600 baud)

```
Button: 1
Distance: 12
Button: 1
Distance: 18
Button: 0
Distance: 15
...
```

When parking is full (button pressed), the red LED stays on and the buzzer sounds continuously regardless of distance.

---

## Code

```cpp
#include <Servo.h>

Servo gate;
int trigPin = 9;
int echoPin = 10;
int parkingButton = 2;
int servoPin = 3;
int greenLED = 5;
int redLED = 6;
int buzzer = 8;

long duration;
int distance;

void setup() {
  gate.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(parkingButton, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  gate.write(0);       // Gate closed
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  bool carDetected = (distance < 15);
  bool parkingFull = (digitalRead(parkingButton) == LOW);

  Serial.print("Button: ");
  Serial.println(digitalRead(parkingButton));
  Serial.print("Distance: ");
  Serial.println(distance);

  if (parkingFull == false) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
    if (carDetected) {
      gate.write(90);
      delay(3000);
      gate.write(0);
    }
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);
    gate.write(0);
  }
  delay(200);
}
```

---

## Installation & Usage

1. Wire all components as per the pin table.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Open Serial Monitor at 9600 baud to view distance and button readings.
6. Press the button to set parking full status; place an object near the sensor to trigger the gate.

---

## Learning Outcomes

- ✅ Ultrasonic distance sensing
- ✅ State management with a toggle button
- ✅ Servo gate control with timing
- ✅ Multi-actuator coordination (LEDs, buzzer, servo)
- ✅ Serial Monitor debugging

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
