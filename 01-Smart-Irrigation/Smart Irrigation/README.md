# Smart Irrigation System

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that automatically waters plants based on soil moisture levels. When the soil is dry (below a user-defined threshold from a potentiometer), a water pump and indicator LED activate.

---

## Description

This project implements an automated irrigation system using:

- **Soil Moisture Sensor (A0):** Measures soil water content.
- **Potentiometer (A1):** Sets the desired moisture threshold.
- **Water Pump (pin 9):** Activates when soil is drier than the threshold.
- **LED (pin 8):** Visual indicator when the pump is active.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| Soil Moisture Sensor | 1 | Analog probe |
| Potentiometer (10kΩ) | 1 | Threshold adjustment |
| DC Water Pump | 1 | 5V submersible pump |
| LED | 1 | Pump status indicator |
| 220Ω Resistor | 1 | LED current limiting |
| Breadboard | 1 | For prototyping |
| Jumper wires | — | For wiring |

---

## Pin Connections

| Arduino Pin | Component | Notes |
|-------------|-----------|-------|
| **A0** | Soil Moisture Sensor | Analog moisture reading |
| **A1** | Potentiometer (wiper) | User-adjustable threshold |
| **9** | Water Pump | Pump control output |
| **8** | LED | Pump ON indicator |

---

## How It Works

1. The soil moisture sensor's analog value is read on A0.
2. The potentiometer's wiper voltage is read on A1 to set the threshold.
3. If soil moisture is below the threshold (`soilValue < moistureLimit`), the pump and LED turn ON.
4. When moisture is sufficient, both turn OFF.
5. Readings are printed to the Serial Monitor every 500 ms.

---

## Working Principle

| Condition | Pump (9) | LED (8) |
|-----------|----------|---------|
| `soilValue < moistureLimit` | ON | ON |
| `soilValue >= moistureLimit` | OFF | OFF |

---

## Expected Output (Serial Monitor, 9600 baud)

```
Soil: 420  Limit: 550
Soil: 415  Limit: 550
Soil: 560  Limit: 550
```

---

## Code

```cpp
int soilSensor = A0;
int setting = A1;
int pump = 9;
int led = 8;

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soilValue = analogRead(soilSensor);
  int moistureLimit = analogRead(setting);
  Serial.print("Soil: ");
  Serial.print(soilValue);
  Serial.print("  Limit: ");
  Serial.println(moistureLimit);
  if (soilValue < moistureLimit) {
    digitalWrite(pump, HIGH);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(pump, LOW);
    digitalWrite(led, LOW);
  }
  delay(500);
}
```

---

## Installation & Usage

1. Wire all components as per the pin table.
2. Connect Arduino to your computer.
3. Open the code in Arduino IDE (select **Board → Arduino Uno**).
4. Upload the code.
5. Adjust the potentiometer to set your desired soil moisture threshold.
6. Insert the soil moisture probe into the plant's soil.

---

## Learning Outcomes

- ✅ Analog sensor reading and threshold comparison
- ✅ User-adjustable threshold via potentiometer
- ✅ Actuator control based on sensor input
- ✅ Serial Monitor data logging

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
