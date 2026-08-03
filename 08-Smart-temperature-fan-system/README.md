# Smart Temperature Fan System

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that automatically controls a **fan** based on ambient temperature. A **potentiometer** sets the desired temperature threshold, a **TMP36** or similar temperature sensor measures the current temperature, and a **fan** + **LED** activate when the temperature exceeds the threshold.

---

## Description

This smart fan controller combines:

- **Temperature Sensor (A0):** LM35 or TMP36 — outputs voltage proportional to temperature (10 mV/°C).
- **Potentiometer (A1):** Sets the desired temperature threshold (mapped to 20–50°C range).
- **Fan (pin 9):** DC fan or motor — activates when current temperature ≥ set temperature.
- **LED (pin 8):** Visual indicator when the fan is ON.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| LM35 / TMP36 Temperature Sensor | 1 | Analog temperature sensor |
| Potentiometer (10kΩ) | 1 | Threshold adjustment |
| DC Motor / Fan | 1 | 5V fan or motor |
| NPN Transistor (2N2222) | 1 | Fan switch |
| 1N4007 Diode | 1 | Flyback protection |
| LED | 1 | Fan status indicator |
| 220Ω Resistor | 1 | LED current limiting |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **A0** | Temperature Sensor (Vout) | Analog temperature input |
| **A1** | Potentiometer (wiper) | User-set threshold |
| **9** | Fan (via transistor) | PWM fan control |
| **8** | LED | Fan status indicator |

---

## How It Works

1. **Temperature reading** — `analogRead(A0)` reads the LM35 voltage. The value is converted to voltage (`sensorValue × 5.0 / 1023.0`) and then to temperature (`voltage × 100` for LM35's 10 mV/°C slope).
2. **Threshold setting** — `analogRead(A1)` reads the potentiometer value, which is mapped to a temperature range of 20–50°C via `map(potValue, 0, 1023, 20, 50)`.
3. **Fan control** — if `temperature >= setTemperature`, the fan (pin 9) and LED (pin 8) turn ON. Otherwise, both turn OFF.
4. Both readings are printed to the Serial Monitor every 500 ms.

---

## Working Principle

| Condition | Fan (9) | LED (8) |
|-----------|---------|---------|
| current temp ≥ set temp | ON | ON |
| current temp < set temp | OFF | OFF |

The potentiometer allows real-time threshold adjustment (20–50°C range).

---

## Expected Output (Serial Monitor, 9600 baud)

```
Current Temp: 26.35 C   Set Temp: 30 C
Current Temp: 27.82 C   Set Temp: 30 C
Current Temp: 30.12 C   Set Temp: 30 C
```

The fan turns ON when `Current Temp` reaches or exceeds `Set Temp`.

---

## Code

```cpp
const int tempPin = A0;
const int potPin = A1;
const int fanPin = 9;
const int ledPin = 8;

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  int potValue = analogRead(potPin);
  int setTemperature = map(potValue, 0, 1023, 20, 50);

  Serial.print("Current Temp: ");
  Serial.print(temperature);
  Serial.print(" C   ");
  Serial.print("Set Temp: ");
  Serial.print(setTemperature);
  Serial.println(" C");

  if (temperature >= setTemperature) {
    digitalWrite(fanPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  delay(500);
}
```

---

## Installation & Usage

1. Connect the temperature sensor to A0, potentiometer to A1, fan (via transistor) to pin 9, and LED to pin 8.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Open Serial Monitor at 9600 baud to view temperature readings.
6. Turn the potentiometer to set the desired temperature threshold.

---

## Learning Outcomes

- ✅ Temperature sensor interfacing (LM35/TMP36)
- ✅ Voltage-to-temperature conversion
- ✅ Potentiometer-based threshold setting with `map()`
- ✅ Fan motor control via transistor
- ✅ Serial Monitor real-time monitoring

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
