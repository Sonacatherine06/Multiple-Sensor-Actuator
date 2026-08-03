# Happy Birthday Light Show

![Arduino](https://img.shields.io/badge/Arduino-Uno-333333)
![C++](https://img.shields.io/badge/Language-C++-00534E)

An Arduino Uno project that creates a birthday celebration light show using an **LCD display** and **12 LEDs**. The LCD displays a scrolling "HAPPY BIRTHDAY" message while the LEDs blink in sequence for a festive effect.

---

## Description

This decorative project combines:

- **16x2 LCD Display:** Displays "HAPPY BIRTHDAY" scrolling across the screen.
- **12 LEDs:** Blink in unison to create a celebratory lighting effect.
- **12 individual LED pins** — a wide pin range is used to drive the lighting show.

---

## Hardware Components

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Main controller |
| 16x2 LCD Display | 1 | HD44780-compatible |
| LEDs | 12 | Any color |
| 220Ω Resistors | 12 | Current limiting for each LED |
| 10kΩ Potentiometer | 1 | LCD contrast adjustment |
| Breadboard | 1 | Large, for prototyping |
| Jumper wires | 30+ | For wiring |
| USB cable | 1 | For programming |

---

## Pin Connections

### LCD (LiquidCrystal LCD(12, 11, 5, 4, 3, 2))

| LCD Pin | Arduino Pin |
|---------|-------------|
| RS | 12 |
| Enable | 11 |
| D4 | 5 |
| D5 | 4 |
| D6 | 3 |
| D7 | 2 |
| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer wiper (contrast) |
| A (Backlight+) | 5V (via 220Ω) |
| K (Backlight−) | GND |

### LED Array (12 pins)

The LEDs are connected to the following pins:

```
LED Pins: 0, 1, 6, 7, 8, 9, 10, 13, A5, A4, A3, A2
```

Each LED connects (with a 220Ω resistor) to its respective pin, with the cathode to GND.

> **Warning:** Pins 0 and 1 are used for serial communication. If you need Serial Monitor debugging, disconnect the LEDs on these pins.

---

## How It Works

1. The LCD is initialized with a 16×2 character display and "HAPPY BIRTHDAY" is printed.
2. All 12 LED pins are configured as outputs.
3. In `loop()`:
   - `lcd.scrollDisplayLeft()` scrolls the message left by one position.
   - All LEDs turn ON simultaneously (brief flash).
   - All LEDs turn OFF.
   - This creates a pulsing, synchronized light-and-message effect.

---

## Code

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ledPins[] = {0, 1, 6, 7, 8, 9, 10, 13, A5, A4, A3, A2};

void setup() {
  lcd.begin(16, 2);
  lcd.print("HAPPY BIRTHDAY");
  for (int i = 0; i < 12; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  lcd.scrollDisplayLeft();
  for (int i = 0; i < 12; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(300);
  for (int i = 0; i < 12; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(300);
}
```

---

## Installation & Usage

1. Wire the LCD and 12 LEDs as per the pin connections.
2. Connect Arduino to your computer.
3. Install the **LiquidCrystal** library via **Sketch → Include Library → LiquidCrystal**.
4. Open the code in Arduino IDE (select **Board → Arduino Uno**).
5. Upload the code.
6. The LCD will display scrolling "HAPPY BIRTHDAY" and the LEDs will blink in sync.

---

## File Structure

```
09-Happy-Birthday/
├── README.md                ← This file
├── HBD/
│   ├── Codes/
│   │   └── sketch.ino       ← Arduino source code
│   └── README.md            ← (empty)
```

---

## License

This project is part of the **Multiple-Sensor-Actuator** repository, licensed under the MIT License.
