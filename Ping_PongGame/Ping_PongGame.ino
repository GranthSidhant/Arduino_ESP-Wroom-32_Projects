#include <U8g2lib.h>
#include <Wire.h>

// Joystick pins
const int joystickXPin = 34;
const int joystickYPin = 35;

// Screen setup
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Paddle setup
int paddleWidth = 20;
int paddleHeight = 4;
int paddleX = 64 - paddleWidth / 2; // Paddle starts in the middle
int paddleY = 60;

// Ball setup
int ballX = 64;
int ballY = 32;
int ballSpeedX = 2;
int ballSpeedY = 2;
int ballSize = 3;

void setup() {
  // Initialize the OLED display
  u8g2.begin();

  // Initialize joystick pins
  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
}

void loop() {
  // Read joystick input
  int joystickX = analogRead(joystickXPin);

  // Map joystick input to paddle movement
  paddleX = map(joystickX, 0, 4095, 0, 128 - paddleWidth);

  // Update ball position
  ballX += ballSpeedX;
  ballY += ballSpeedY;

  // Ball collision with walls
  if (ballX <= 0 || ballX >= 128 - ballSize) {
    ballSpeedX = -ballSpeedX;
  }

  if (ballY <= 0) {
    ballSpeedY = -ballSpeedY;
  }

  // Ball collision with paddle
  if (ballY >= paddleY - ballSize && ballX + ballSize >= paddleX && ballX <= paddleX + paddleWidth) {
    ballSpeedY = -ballSpeedY;
  }

  // Reset ball if it goes past the paddle
  if (ballY > 64) {
    ballX = 64;
    ballY = 32;
    ballSpeedX = 2;
    ballSpeedY = 2;
  }

  // Draw everything on the screen
  u8g2.clearBuffer();
  u8g2.drawBox(paddleX, paddleY, paddleWidth, paddleHeight); // Draw paddle
  u8g2.drawDisc(ballX, ballY, ballSize); // Draw ball
  u8g2.sendBuffer();

  // Add a small delay for smoother movement
  delay(10);
}
