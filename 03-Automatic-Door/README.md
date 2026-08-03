# Automatic Door System

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that automatically opens a door when a person is detected nearby **and** motion is active. A servo motor operates the door, and a buzzer provides an audible confirmation.

---

## Description

This project combines two detection methods for reliable door activation:

- **Ultrasonic Sensor (HC-SR04):** Measures distance (pins 7=Trig, 6=Echo). Detects objects within 50 cm.
- **PIR Motion Sensor:** Confirms human presence by detecting infrared radiation (pin 2).
- **Servo Motor (pin 9):** Opens/closes the door barrier.
- **Buzzer (pin 8):** Audible beep when door opens.

The door opens **only when both** the ultrasonic sensor detects a nearby object **and** the PIR sensor detects motion, reducing false triggers.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement |
| PIR Motion Sensor | 1 | Motion detection |
| Servo Motor (SG90) | 1 | Door actuator |
| Buzzer | 1 | Audio feedback |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **7** | HC-SR04 (Trig) | Ultrasonic trigger |
| **6** | HC-SR04 (Echo) | Ultrasonic echo |
| **2** | PIR (OUT) | Motion detection input |
| **9** | Servo | Door control (PWM) |
| **8** | Buzzer | Audio feedback |

---

## How It Works

1. The HC-SR04 measures distance to the nearest object.
2. The PIR sensor checks for human motion.
3. **If both conditions are met** (distance < 50 cm AND motion detected), the servo opens the door to 90° and the buzzer beeps for 500 ms.
4. **If either condition fails**, the door closes (0°) and the buzzer is silent.

---

## Working Principle

| Distance | Motion | Door (Servo) | Buzzer (8) |
|----------|--------|--------------|------------|
| < 50 cm | HIGH | Open (90°) | ON (500 ms) |
| < 50 cm | LOW | Closed (0°) | OFF |
| ≥ 50 cm | HIGH | Closed (0°) | OFF |
| ≥ 50 cm | LOW | Closed (0°) | OFF |

---

## Expected Output (Serial Monitor, 9600 baud)

The code does not output serial data. The servo opens and the buzzer beeps when both conditions are met.

---

## Code

```cpp
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
  door.write(0);  // Door initially closed
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  int motion = digitalRead(pirPin);

  if (distance < 50 && motion == HIGH) {
    door.write(90);       // Open door
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
  } else {
    door.write(0);        // Close door
    digitalWrite(buzzerPin, LOW);
  }
  delay(100);
}
```

---

## Installation & Usage

1. Wire the HC-SR04, PIR sensor, servo, and buzzer as per the pin table.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Approach the sensor from within 50 cm while the PIR detects motion.

---

## Learning Outcomes

- ✅ Ultrasonic distance measurement
- ✅ PIR motion detection
- ✅ Servo motor control with `Servo.h`
- ✅ Dual-condition (AND gate) actuator logic
- ✅ Buzzer feedback

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
