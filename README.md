# Multiple Sensor Actuator Projects

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

A collection of 9 Arduino Uno projects, each demonstrating **multiple sensors and actuators** working together to create smart, interactive systems.

---

## Table of Contents

- [Projects](#projects)
- [Technologies](#technologies-used)
- [Hardware Requirements](#hardware-requirements)
- [Usage](#usage)
- [License](#license)

---

## Projects

| # | Project | Sensors | Actuators | Key Pins |
|---|---------|---------|-----------|----------|
| 01 | [Smart Irrigation](01-Smart-Irrigation) | Soil Moisture (A0) | Water Pump (9), LED (8) | A0, A1, 9, 8 |
| 02 | Automatic Street Light + Security | LDR (A0), PIR (2) | LED (9), Buzzer (8) | A0, 2, 9, 8 |
| 03 | [Automatic Door](03-Automatic-Door) | Ultrasonic (7,6), PIR (2) | Servo (9), Buzzer (8) | 7, 6, 2, 9, 8 |
| 04 | Alcohol Detection Engine Lock | Alcohol Sensor (A0) | Motor (5,6,7), LEDs (8,9), Buzzer (10) | A0, 5, 6, 7, 8, 9, 10 |
| 05 | Automatic Plant Watering | Soil Moisture (A0), Pot (A1) | Pump (9), LED (8) | A0, A1, 9, 8 |
| 06 | [Smart Parking System](06-Smart-parking-system) | Ultrasonic (9,10), Button (2) | Servo (3), LEDs (5,6), Buzzer (8) | 9, 10, 2, 3, 5, 6, 8 |
| 07 | Smart Energy Saving Room | PIR (2), LDR (A0) | LED (8), Servo (9), LCD | 2, A0, 8, 9 |
| 08 | Smart Temperature Fan System | LM35 (A0), Pot (A1) | Fan (9), LED (8) | A0, A1, 9, 8 |
| 09 | Happy Birthday | — | LCD (12,11,5,4,3,2), 12 LEDs | 12, 11, 5, 4, 3, 2, A5, A4, A3, A2, 0, 1, 6, 7, 8, 9, 10, 13 |

Each project folder contains its own README with detailed instructions.

---

## Technologies Used

| Technology | Version |
|------------|---------|
| Arduino IDE | 1.8+ or 2.x |
| Programming Language | C/C++ (Arduino framework) |
| Microcontroller | Arduino Uno (ATmega328P) |
| Libraries | Servo, LiquidCrystal |

---

## Hardware Requirements

- Arduino Uno (or compatible board)
- USB cable (Type-A to Type-B)
- Breadboard and jumper wires
- Components listed per project (see individual READMEs)

---

## Usage

1. Navigate to the project folder you want to use.
2. Read the project-specific README.md for component lists and wiring instructions.
3. Assemble the circuit on a breadboard.
4. Connect the Arduino Uno to your computer.
5. Open the source file (`code.ino` or `sketch.ino`) in the Arduino IDE.
6. Upload the code to the Arduino.

---

## License

This repository is licensed under the MIT License.
