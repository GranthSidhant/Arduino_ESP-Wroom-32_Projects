
# Talking to Mimo – ESP32 Emotion Display Project

This project lets users interact with an animated character named **Mimo** hosted on an ESP32. When powered on, the ESP32 creates a Wi-Fi Access Point that users can connect to. After joining the network, users can open a webpage and type a message. The message is analyzed and an emotion is displayed on a connected OLED screen in the form of a simple animated face representing that emotion.

---

## 📷 Screenshots
![video](video.gif)
![image](image1.jpg)
![image](image2.jpg)

---

## 🔧 Features

- ESP32 acts as a Wi-Fi Access Point.
- Web interface to type messages.
- Messages are processed and translated to emotions.
- OLED displays animated faces based on the emotion.

---

## 📦 Requirements

### Hardware:
- ESP32 (WROOM module recommended)
- 0.96" I2C OLED Display (SSD1306, 128x64)
- Micro USB Cable

### Libraries:
Install these libraries in the Arduino IDE (via Library Manager or ZIP):
- `Adafruit SSD1306`
- `Adafruit GFX`
- `WiFi.h`
- `WebServer.h`
- `Wire.h`

---

## 📡 Network Setup

In your Arduino code, the Wi-Fi name (SSID) and password are set as:

```cpp
const char* ssid = "Mimo-Network";
const char* password = "mimo1234";
```

After uploading the code and powering the ESP32:

1. Connect your device to the Wi-Fi network **Mimo-Network** using password **mimo1234**.
2. Open the **Serial Monitor** (9600 baud) in Arduino IDE.
3. Note the IP address shown — it will look something like `192.168.4.1`.
4. Open that IP address in a browser to access the Mimo interaction page.

---

## 🚀 Future Improvements & Ideas

This is just the beginning! Here are some exciting ways this project can be enhanced:

- 🎭 **More Emotions**: Add more animated faces to represent a broader range of emotions.
- 🧠 **AI Integration**: Use AI or sentiment analysis APIs (like OpenAI or Hugging Face) to detect emotions more accurately.
- 📱 **Mobile UI**: Improve the web interface for better mobile experience.
- 💾 **Message History**: Display the last few messages or emotions.
- 🎤 **Voice Input**: Add a microphone for voice-to-text message conversion.
- 📦 **OTA Updates**: Add support for over-the-air firmware updates.
- 🌐 **Cloud Mode**: Let users optionally connect ESP32 to home Wi-Fi to enable remote access.
- 💡 **LED Feedback**: Add RGB LED or buzzer for additional physical feedback.

If you have ideas or improvements in mind — feel free to contribute!

---

## 🤝 Contributions Welcome!

This is an open-source project and all kinds of contributions are welcome:
- Improve the design or animations
- Suggest new features
- Fix bugs
- Optimize the code

Just fork the repo, make changes, and submit a pull request!

---

> Created with ❤️ by [Granth Sidhant Yadav](https://www.linkedin.com/in/granthsidhant/)
