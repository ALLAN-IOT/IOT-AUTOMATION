Here is a **GitHub README** specifically based on the details from your uploaded **IoT Home Automation Report** and **Arduino code**:  

---

# 🏠 IoT Home Automation System  

## 📌 Overview  
This project implements a **smart home automation system** that allows users to remotely control household devices like **lights, sockets, doors, and windows** via **Telegram Bot** and **WiFi-based ESP32**. It also integrates **real-time energy monitoring** using the **PZEM-004T sensor** and provides device status feedback using **photoresistors**.  

## 🔹 Features  
✅ **Remote Control via Telegram:** Turn **lights, sockets, doors, and windows** ON/OFF.  
✅ **Real-Time Energy Monitoring:** Measure **voltage, current, power, and energy consumption**.  
✅ **Device Status Feedback:** Detect light status using **photoresistors**.  
✅ **Battery Monitoring System:** LEDs indicate **charging, low battery, and full charge status**.  
✅ **Automated Plant Watering:** Integrated **soil moisture sensor** for automatic watering.  
✅ **Security Alarm System:** **Sound sensor** triggers an alarm upon loud noise detection.  

---

## 🔌 Components Used  

### **Microcontroller & Communication**  
- **ESP32** (WiFi-enabled microcontroller)  
- **Telegram Bot API** (for remote control)  

### **Sensors & Modules**  
- **PZEM-004T** (Voltage, Current, Power, and Energy Measurement)  
- **Photoresistors** (Light detection for feedback)  
- **Soil Moisture Sensor** (Smart plant watering)  
- **Sound Sensor** (Security alarm activation)  
- **GY-169 Module** (Battery monitoring)  

### **Actuators & Output Devices**  
- **Relay Modules** (For controlling lights and sockets)  
- **Servo Motors** (For doors and windows)  
- **LCD 2004 (I2C)** (Display real-time energy data)  
- **LED Indicators** (Error, Charging, Low Battery, Full Battery)  

---

## ⚙️ Pin Configuration  

| **Component** | **GPIO Pin** |  
|--------------|------------|  
| **Relay 1 (Bulb 1)** | GPIO 2 |  
| **Relay 2 (Bulb 2)** | GPIO 4 |  
| **Relay 3 (Bulb 3)** | GPIO 16 |  
| **Relay 4 (Bulb 4)** | GPIO 17 |  
| **Relay 5 (Socket 1)** | GPIO 5 |  
| **Relay 6 (Socket 2)** | GPIO 18 |  
| **Photoresistor 1 (Bulb 3)** | GPIO 34 |  
| **Photoresistor 2 (Bulb 4)** | GPIO 35 |  
| **Servo 1 (Door 1)** | GPIO 19 |  
| **Servo 2 (Door 2)** | GPIO 21 |  
| **Servo 3 (Window 1)** | GPIO 22 |  
| **Servo 4 (Window 2)** | GPIO 23 |  
| **LCD I2C SDA** | GPIO 32 |  
| **LCD I2C SCL** | GPIO 33 |  
| **PZEM-004T RX** | GPIO 13 |  
| **PZEM-004T TX** | GPIO 15 |  
---

## 🚀 Installation & Setup  

### **1️⃣ Required Software**  
- **Arduino IDE** – [Download Here](https://www.arduino.cc/en/software)  
- **ESP32 Board Manager** (Install via Arduino IDE)  
- **Required Libraries:**  
  - `WiFi.h` (For ESP32 WiFi Communication)  
  - `UniversalTelegramBot.h` (For Telegram Bot Control)  
  - `Servo.h` (For Servo Motors)  
  - `LiquidCrystal_I2C.h` (For LCD Display)  
  - `PZEM004T.h` (For Energy Monitoring)  

### **2️⃣ Hardware Connections**  
- Connect **ESP32** to sensors, relays, LCD, and actuators using the **Pin Configuration** table.  
- Power the ESP32 module via USB or an external **5V power source**.  

### **3️⃣ Upload Code**  
- Open **`IOT_AUTOMATION_ALLAN_MARTIN_MICHAEL.ino`** in **Arduino IDE**.  
- Replace WiFi credentials and Telegram Bot token:  
  ```cpp
  const char* ssid = "IOT";
  const char* password = "12345678";
  #define BOTtoken "7626283325:AAFPXefMPJPHrVlu2mh2FTvobKhXKYf4Xp8"
  ```
- Select **ESP32 Board**, choose the correct COM Port, and **upload the code**.  

---

## 📲 Usage  

- **Start Telegram Bot** and send commands:  
  - `/light_on` – Turn on a light  
  - `/light_off` – Turn off a light  
  - `/socket_on` – Turn on a socket  
  - `/socket_off` – Turn off a socket  
  - `/open_door` – Open a door  
  - `/close_door` – Close a door  
  - `/status` – Get real-time device status  
- LCD will display **real-time energy consumption data**.  
- If **lights are ON**, **photoresistors detect and confirm the status**.  
- If **sound is detected**, the **alarm system is triggered**.  

---

## 🔧 Future Improvements  
🚀 **Integrate Mobile App** for additional control.  
🚀 **Voice Control via Google Assistant & Alexa**.  
🚀 **Expand to Smart Security Systems** (CCTV & Motion Sensors).  
🚀 **Energy Optimization Features** using AI-based automation.  

---

## 📜 License  
This project is **open-source** under the **MIT License**.  

---

## 📞 Contact  
📧 **Email:** [kiptanuiallan38@gmail.com](mailto:kiptanuiallan38@gmail.com)  
🌐 **GitHub:** [ALLAN-IOT](https://github.com/ALLAN-IOT)  

---

🔥 **Transforming Homes with IoT Innovation!** 🚀  
