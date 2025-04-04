#include <Arduino.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PZEM004Tv30.h>

// WiFi Credentials
const char* ssid = "IOT";
const char* password = "12345678";

// Telegram Bot Token
const char* botToken = "7626283325:AAFPXefMPJPHrVlu2mh2FTvobKhXKYf4Xp8";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

// Relay Pins & States
const int relayPins[] = {2, 4, 16, 17, 5, 18};
const char* relayNames[] = {"Bulb 1", "Bulb 2", "Bulb 3", "Bulb 4", "Socket 1", "Socket 2"};
bool relayStates[] = {false, false, false, false, false, false};

// Servo Definitions
Servo servo1, servo2, servo3, servo4;
#define SERVO_1_PIN 19  // Door 1
#define SERVO_2_PIN 21  // Lock 1
#define SERVO_3_PIN 22  // Window 1
#define SERVO_4_PIN 23  // Lock 2

// Photoresistor Pins
#define PHOTO_1_PIN 34  // Bulb 3 Sensor
#define PHOTO_2_PIN 35  // Bulb 4 Sensor

// LCD Display
#define I2C_ADDR 0x3F
#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define SDA_PIN 32
#define SCL_PIN 33
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

// PZEM-004T Energy Meter
PZEM004Tv30 pzem(Serial2, 13, 15);

void gradualMove(Servo &servo, int startPos, int endPos, int durationMs) {
    int stepCount = abs(endPos - startPos);
    int stepDelay = durationMs / stepCount;

    if (startPos < endPos) {
        for (int pos = startPos; pos <= endPos; pos++) {
            servo.write(pos);
            delay(stepDelay);
        }
    } else {
        for (int pos = startPos; pos >= endPos; pos--) {
            servo.write(pos);
            delay(stepDelay);
        }
    }
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    client.setInsecure();
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Initialize relays
    for (int i = 0; i < 6; i++) {
        pinMode(relayPins[i], OUTPUT);
        digitalWrite(relayPins[i], HIGH);
    }

    // Attach servos & set to default positions
    servo1.attach(SERVO_1_PIN);
    servo2.attach(SERVO_2_PIN);
    servo3.attach(SERVO_3_PIN);
    servo4.attach(SERVO_4_PIN);
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    servo4.write(0);

    // Initialize LCD
    Wire.begin(SDA_PIN, SCL_PIN);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("PZEM Meter Init");
    Serial.println("PZEM-004T Energy Meter Test on ESP32");
}

void handleTelegramMessages() {
    int messageCount = bot.getUpdates(bot.last_message_received + 1);
    while (messageCount) {
        for (int i = 0; i < messageCount; i++) {
            String chat_id = bot.messages[i].chat_id;
            String text = bot.messages[i].text;
            bool commandFound = false;

            Serial.println("Received command: " + text);

            for (int j = 0; j < 6; j++) {
                if (text.equalsIgnoreCase("/" + String(relayNames[j]) + " on")) {
                    digitalWrite(relayPins[j], LOW);
                    relayStates[j] = true;
                    bot.sendMessage(chat_id, String(relayNames[j]) + " turned ON", "");
                    commandFound = true;
                } else if (text.equalsIgnoreCase("/" + String(relayNames[j]) + " off")) {
                    digitalWrite(relayPins[j], HIGH);
                    relayStates[j] = false;
                    bot.sendMessage(chat_id, String(relayNames[j]) + " turned OFF", "");
                    commandFound = true;
                }
            }

            if (text.equalsIgnoreCase("/status")) {
                String statusMsg = "Current Status:\n";
                for (int k = 0; k < 6; k++) {
                    statusMsg += String(relayNames[k]) + ": " + (relayStates[k] ? "ON" : "OFF") + "\n";
                }
                statusMsg += "Photoresistor 1: " + String(analogRead(PHOTO_1_PIN)) + "\n";
                statusMsg += "Photoresistor 2: " + String(analogRead(PHOTO_2_PIN)) + "\n";
                bot.sendMessage(chat_id, statusMsg, "");
                commandFound = true;
            }
        }
        messageCount = bot.getUpdates(bot.last_message_received + 1);
    }
}

void loop() {
    handleTelegramMessages();
    delay(1000);
}
