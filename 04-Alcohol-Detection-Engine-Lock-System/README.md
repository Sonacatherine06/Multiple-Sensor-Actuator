# Alcohol Detection Engine Lock System

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that detects alcohol consumption and prevents engine operation. When alcohol is detected above a threshold, the engine is locked and an alarm sounds.

---

## Description

This project implements a driver safety system with:

- **Alcohol Sensor (A0):** MQ-3 or similar analog alcohol sensor.
- **Motor Driver (pins 5, 6, 7):** Controls engine/motor operation (enable, IN1, IN2).
- **Green LED (pin 8):** Indicates engine is safe to run.
- **Red LED (pin 9):** Indicates alcohol detected (engine locked).
- **Buzzer (pin 10):** Alarm when alcohol is detected.

When the alcohol reading exceeds the threshold (default: 500), the motor is stopped, the red LED lights up, and the buzzer sounds. Otherwise, the motor runs and the green LED is on.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| Alcohol Sensor (MQ-3) | 1 | Analog alcohol sensor |
| Motor Driver (L298N) | 1 | H-bridge motor driver |
| DC Motor | 1 | Simulated engine |
| Green LED | 1 | Safe indicator |
| Red LED | 1 | Danger indicator |
| Buzzer | 1 | Alarm |
| 220Ω Resistors | 2 | LED current limiting |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **A0** | Alcohol Sensor (A0) | Analog gas reading |
| **5** | Motor Enable | PWM speed control |
| **6** | Motor IN1 | Direction control |
| **7** | Motor IN2 | Direction control |
| **8** | Green LED | Safe indicator |
| **9** | Red LED | Danger indicator |
| **10** | Buzzer | Alarm output |

---

## How It Works

1. The alcohol sensor's analog value is read on A0.
2. If the value exceeds the threshold (500):
   - Red LED turns ON, green LED turns OFF
   - Buzzer sounds
   - Motor is stopped (enable = 0, IN1/IN2 = LOW)
3. If the value is below the threshold:
   - Green LED turns ON, red LED turns OFF
   - Buzzer is silent
   - Motor runs forward (enable = 255, IN1 = HIGH, IN2 = LOW)

---

## Working Principle

| Alcohol Level | Condition | Green LED | Red LED | Buzzer | Motor |
|---------------|-----------|-----------|---------|--------|-------|
| Normal | value ≤ 500 | ON | OFF | OFF | RUNNING |
| Danger | value > 500 | OFF | ON | ON | STOPPED |

---

## Expected Output (Serial Monitor, 9600 baud)

```
382
415
395
512
428
...
```

When the alcohol reading exceeds 500, the motor stops and the alarm activates.

---

## Code

```cpp
const int alcoholSensor = A0;
const int motorEnable = 5;
const int motorIN1 = 6;
const int motorIN2 = 7;
const int greenLED = 8;
const int redLED = 9;
const int buzzer = 10;
int threshold = 500;

void setup() {
  pinMode(motorEnable, OUTPUT);
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int alcoholValue = analogRead(alcoholSensor);
  Serial.println(alcoholValue);
  if (alcoholValue > threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);
    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, LOW);
    analogWrite(motorEnable, 0);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);
    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorIN2, LOW);
    analogWrite(motorEnable, 255);
  }
  delay(300);
}
```

---

## Installation & Usage

1. Wire the alcohol sensor, motor driver, LEDs, and buzzer as per the pin table.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Open Serial Monitor to view alcohol readings.
6. Apply alcohol (e.g., from an alcohol wipe) near the sensor to trigger the lock.

---

## Learning Outcomes

- ✅ Alcohol/gas sensor interfacing (MQ-3)
- ✅ H-bridge motor driver control (direction + speed via PWM)
- ✅ Multi-actuator control (LEDs, buzzer, motor)
- ✅ Threshold-based safety system design

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
