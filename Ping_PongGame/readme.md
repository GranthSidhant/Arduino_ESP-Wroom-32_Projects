# 🎮 ESP32 Joystick Paddle Game with OLED Display

A simple paddle-ball game built using an ESP32-WROOM-32, a 0.96" OLED display, and an HW-504 joystick. Move the paddle using the joystick to keep the ball bouncing—if you miss it, the game resets!

---

## 📦 Components Required

- ESP32-WROOM-32 development board  
- 0.96" I2C OLED display (128x64, SH1106 or SSD1306 driver)  
- HW-504 Joystick module  
- Jumper wires (male-to-male)  
- Small breadboard *(recommended if you need extra power rails)*  

---

## 📚 Required Libraries

Install the following library via Arduino IDE:

- **U8g2** by olikraus  
  *(Go to Tools → Manage Libraries → Search "U8g2" and install)*

---

## 🔌 Circuit Connections

### OLED Display (I2C)

| OLED Pin | ESP32 Pin |
|----------|-----------|
| VCC      | 3V3       |
| GND      | GND       |
| SCL      | GPIO22    |
| SDA      | GPIO21    |

### Joystick HW-504

| Joystick Pin | ESP32 Pin | Description       |
|--------------|-----------|-------------------|
| GND          | GND       | Ground            |
| VCC          | 3V3       | Power             |
| VRx          | GPIO34    | Analog X-axis     |
| VRy          | GPIO35    | Analog Y-axis     |
| SW           | GPIO32    | *(optional)* Button press

> ⚠️ Note:  
> The ESP32 board has only one 3.3V pin.  
> If you're connecting both the OLED and joystick, use a **small breadboard** to split the 3.3V and GND lines safely.

---

## 🚀 How It Works

- The paddle is drawn at the bottom of the OLED screen.
- The ball bounces around the screen.
- Move the joystick left or right to control the paddle.
- If the ball hits the paddle, it bounces back.
- If the ball misses the paddle and goes out, it resets.

---

## 🧪 How to Run

1. Connect all components as per the diagram above.
2. Open Arduino IDE.
3. Select your board: `ESP32 Dev Module`.
4. Select the right COM port.
5. Install the **U8g2** library if not already installed.
6. Upload the code to your ESP32.

---

## 🧠 Notes

- This game is very basic but extensible—you can add a score counter, speed increase, sound using a buzzer, or even a game over screen.
- Make sure not to power the OLED or joystick from 5V if they’re 3.3V-only modules.

<!-- ---

## 📸 Preview

*(Insert a screenshot or video/GIF of the game running on OLED here if you want)*

--- -->

## 👨‍💻 Author

**Granth Sidhant Yadav**  
[GitHub](https://github.com/GranthSidhant)  
[LinkedIn](https://www.linkedin.com/in/granthsidhant)

---

Happy coding! 🎉
