# Smart Energy Saving Room System

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that automatically saves energy in a room. A **PIR motion sensor** turns lights and a **servo-operated curtain** ON when someone enters, and the curtain opens only when it's bright enough (detected by an **LDR**).

---

## Description

This smart room system uses:

- **PIR Motion Sensor (pin 2):** Detects human presence.
- **LDR (A0):** Measures ambient light level.
- **LED (pin 8):** Room light, activates on motion.
- **Servo Motor (pin 9):** Curtain control — opens only when motion is detected AND it's bright.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| PIR Motion Sensor (HC-SR501) | 1 | Motion detection |
| LDR | 1 | Light level sensor |
| 10kΩ Resistor | 1 | LDR pull-down |
| LED | 1 | Room light |
| Servo Motor (SG90) | 1 | Curtain control |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **2** | PIR (OUT) | Motion detection input |
| **A0** | LDR | Light level input |
| **8** | LED | Room light output |
| **9** | Servo | Curtain control (PWM) |

---

## How It Works

1. The PIR sensor detects motion. If motion is detected (HIGH), the LED on pin 8 turns ON.
2. The LDR measures ambient light. If light level is above 500 (bright), the servo opens the curtain to 90°.
3. When no motion is detected, the LED turns OFF and the curtain closes to 0°.
4. Both sensor values are printed to the Serial Monitor.

---

## Working Principle

| Motion | Light Level | LED (8) | Servo (9) |
|--------|-------------|---------|-----------|
| Detected | > 500 (bright) | ON | Open (90°) |
| Detected | ≤ 500 (dark) | ON | Closed (0°) |
| Not detected | Any | OFF | Closed (0°) |

---

## Expected Output (Serial Monitor, 9600 baud)

```
PIR: 1  LDR: 650
PIR: 1  LDR: 200
PIR: 0  LDR: 650
...
```

---

## Code

```cpp
#include <Servo.h>

Servo curtainServo;
#define PIR_PIN 2
#define LDR_PIN A0
#define LED_PIN 8
#define SERVO_PIN 9

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  curtainServo.attach(SERVO_PIN);
  curtainServo.write(0);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(PIR_PIN);
  int lightValue = analogRead(LDR_PIN);
  Serial.print("PIR: ");
  Serial.print(motion);
  Serial.print("  LDR: ");
  Serial.println(lightValue);

  if (motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    if (lightValue > 500) {
      curtainServo.write(90);
    } else {
      curtainServo.write(0);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    curtainServo.write(0);
  }
  delay(500);
}
```

---

## Installation & Usage

1. Wire the PIR sensor to pin 2, LDR to A0, LED to pin 8, and servo to pin 9.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Open Serial Monitor at 9600 baud to view sensor readings.

---

## Learning Outcomes

- ✅ Motion-based lighting control
- ✅ Light-dependent curtain automation
- ✅ Nested conditional logic
- ✅ Multi-sensor decision making

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
