
/*
  SMART HOUSE IoT PROJECT
  ESP32 + Blynk

  Reconstructed reference sketch based on the original project.
  The original source code is unavailable.
  This version has not been physically retested.

  Features:
  - LCD startup messages
  - Three independently controlled room lights
  - Servo-controlled door
*/

// ==========================================
// BLYNK CONFIGURATION
// ==========================================

#define BLYNK_TEMPLATE_ID "TMPL27C-9QdMT"
#define BLYNK_TEMPLATE_NAME "Smart House"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

// ==========================================
// LIBRARIES
// ==========================================

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ==========================================
// WI-FI CONFIGURATION
// ==========================================

char ssid[] = "MY_HOTSPOT_NAME";
char pass[] = "MY_HOTSPOT_PASSWORD";

// ==========================================
// PIN CONFIGURATION
// ==========================================

#define LED_1 25
#define LED_2 26
#define LED_3 27

#define SERVO_PIN 18

#define LCD_SDA 21
#define LCD_SCL 22

// ==========================================
// COMPONENT CONFIGURATION
// ==========================================

// LCD configuration
#define LCD_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

// Servo configuration
Servo doorServo;

#define DOOR_CLOSED 0
#define DOOR_OPEN 90

// ==========================================
// LCD STARTUP DISPLAY
// ==========================================

void displayStartup() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SMART HOUSE");

  lcd.setCursor(0, 1);
  lcd.print("LOADING...");

  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SMART HOUSE");

  lcd.setCursor(0, 1);
  lcd.print("READY");
}

// ==========================================
// BLYNK DATastream CONTROLS
// ==========================================

// Servo motor - Virtual Pin V1
// 1 = Open door
// 0 = Close door

BLYNK_WRITE(V1) {

  int doorCommand = param.asInt();

  if (doorCommand == 1) {
    doorServo.write(DOOR_OPEN);
  }
  else {
    doorServo.write(DOOR_CLOSED);
  }
}

// LED 1 - Virtual Pin V2

BLYNK_WRITE(V2) {

  int ledState = param.asInt();

  digitalWrite(LED_1, ledState ? HIGH : LOW);
}

// LED 2 - Virtual Pin V3

BLYNK_WRITE(V3) {

  int ledState = param.asInt();

  digitalWrite(LED_2, ledState ? HIGH : LOW);
}

// LED 3 - Virtual Pin V4

BLYNK_WRITE(V4) {

  int ledState = param.asInt();

  digitalWrite(LED_3, ledState ? HIGH : LOW);
}

// ==========================================
// SETUP
// ==========================================

void setup() {

  Serial.begin(115200);

  // Configure LED pins
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  // Turn off all LEDs at startup
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);

  // Initialise LCD
  Wire.begin(LCD_SDA, LCD_SCL);

  lcd.init();
  lcd.backlight();

  // Display startup messages
  displayStartup();

  // Initialise servo motor
  doorServo.setPeriodHertz(50);
  doorServo.attach(SERVO_PIN, 500, 2400);

  // Set door to closed position
  doorServo.write(DOOR_CLOSED);

  // Connect to Wi-Fi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// ==========================================
// MAIN LOOP
// ==========================================

void loop() {

  Blynk.run();
}
