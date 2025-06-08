# Test 0.96" OLED Display with ESP32-WROOM-32

This guide explains how to connect and test a 0.96" I2C OLED display (SSD1306 or SH1106) using an ESP32-WROOM-32 board and the U8g2 library.

---

## 🧰 Hardware Required

- ESP32-WROOM-32 development board  
- 0.96" OLED display (I2C, 128x64, SSD1306 or SH1106)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Circuit Connections

Connect the OLED display to the ESP32 as follows:

| OLED Pin | ESP32 Pin |
|----------|-----------|
| VCC      | 3V3       |
| GND      | GND       |
| SCL      | GPIO22    |
| SDA      | GPIO21    |

> Note: These are the default I2C pins on most ESP32 boards.

---

## 🔧 Software Setup

1. **Install Arduino IDE**  
   Download from: https://www.arduino.cc/en/software

2. **Install the ESP32 board package**  
   In the Arduino IDE:  
   - Go to **File > Preferences**
   - Add this URL in **Additional Board Manager URLs**:  
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Then go to **Tools > Board > Board Manager**, search for `esp32`, and install it.

3. **Select the Board and Port**  
   - Board: `ESP32 Dev Module`
   - Port: Choose the one your ESP32 is connected to

4. **Install the U8g2 Library**  
   - Go to **Tools > Manage Libraries**
   - Search for `U8g2` and install the one by `oliver`

---

## 📟 Test Code

Upload the following code to test the OLED display:

```cpp
#include <Wire.h>
#include <U8g2lib.h>

// Use this line for SH1106
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Use this line instead if your display is SSD1306
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();                         // Clear internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);         // Choose a readable font
  u8g2.drawStr(10, 30, "Hello OLED!");        // Draw text at (10, 30)
  u8g2.sendBuffer();                          // Transfer internal memory to the display
  delay(1000);
}
