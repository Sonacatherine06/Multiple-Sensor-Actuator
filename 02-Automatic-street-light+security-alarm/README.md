# Automatic Street Light + Security Alarm

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that combines an **automatic street light** and a **security alarm** system. The LED street light turns on when it gets dark, and the buzzer alarm activates when motion is detected.

---

## Description

This project uses two sensors and two actuators:

- **LDR (A0):** Measures ambient light level. When dark (< 500), the LED street light turns on.
- **PIR Sensor (pin 2):** Detects human motion. When motion is detected, the buzzer sounds for 500 ms.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| LDR | 1 | Light sensor |
| 10kΩ Resistor | 1 | LDR pull-down |
| PIR Motion Sensor | 1 | HC-SR501 |
| LED | 1+ | Street light indicator |
| Buzzer | 1 | Security alert |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **A0** | LDR | Light level input |
| **2** | PIR (OUT) | Motion detection input |
| **9** | LED | Street light output |
| **8** | Buzzer | Security alarm output |

---

## How It Works

1. **Light control:** `analogRead(A0)` reads the LDR value. When the reading is below 500 (dark), the LED on pin 9 turns ON. When light returns, the LED turns OFF.
2. **Motion detection:** `digitalRead(2)` checks the PIR sensor. When motion is detected (HIGH), the buzzer on pin 8 sounds for 500 ms, then goes silent.

---

## Working Principle

| Sensor | Condition | Actuator | Action |
|--------|-----------|----------|--------|
| LDR (A0) | light < 500 | LED (9) | ON |
| LDR (A0) | light >= 500 | LED (9) | OFF |
| PIR (2) | HIGH | Buzzer (8) | ON (500 ms) |
| PIR (2) | LOW | Buzzer (8) | OFF |

---

## Code

```cpp
int ldr = A0;
int pir = 2;
int led = 9;
int buzzer = 8;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int light = analogRead(ldr);
  int motion = digitalRead(pir);
  if (light < 500)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
  if (motion == HIGH) {
    digitalWrite(buzzer, HIGH);
    delay(500);
  } else
    digitalWrite(buzzer, LOW);
}
```

---

## Installation & Usage

1. Wire the LDR to A0, PIR to pin 2, LED to pin 9, and buzzer to pin 8.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Cover the LDR to simulate darkness — the LED should turn on.
6. Wave your hand in front of the PIR sensor — the buzzer should sound.

---

## Learning Outcomes

- ✅ Dual sensor control (light + motion)
- ✅ Conditional actuator logic with multiple inputs
- ✅ Non-blocking vs blocking delay considerations

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
