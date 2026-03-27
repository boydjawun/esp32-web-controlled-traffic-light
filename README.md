# 🚦 Traffic School - ESP32 Web-Controlled Traffic Light

<p align= "Center">
<img src = https://github.com/user-attachments/assets/313cd398-2210-4c53-85de-a74ea84082da  width = 700 height = 500/>
</p>

# 👀Description
>This project turns an ESP32 into a fully wireless Traffic Light simulator for "Traffic School" demos, classrooms, or workshops. It creates its own WiFi Access Point (no router needed) so anyone can connect with their phone or laptop and control the red, yellow, and green lights through a clean, responsive web interface. Real-time status is shown on the page, making it perfect for learning IoT, web servers, and basic electronics.

## 📖Overview
- Self-hosted WiFi Access Point (SSID: `YESP32`)
- Mobile-friendly web dashboard
- One-click toggle for each light with live ON/OFF status
- No internet required — works completely offline

### 🧰Hardware 
- ESP32 Development Board (any ESP32 DevKit)
- 5mm Red LED 
- 5mm Yellow LED
- 5mm Green LED
- 3 Female to Female Jumper Wires(GPIO5, GPIO18, GPIO19)
- 1 Female to make Jumper Wire(GND)
- USB-A to USB-C Cable 1m(Data Transfer)
- Solderless 830-point breadboard

### 💻Software
- Arduino IDE
- ESP32 Arduino Core (via Board Manager)
- Built-in libraries: `WiFi.h` and `WebServer.h`
- [Traffic School Script](https://github.com/boydjawun/esp32-web-controlled-traffic-light/blob/main/traffic_school.ino)

# 🐾Project Walkthrough

1. 🛒**Gather your parts**  
   Collect the ESP32, three LEDs, resistors, breadboard, and wires.

2. ➰**Wire the LEDs**  
   - 🔴Red LED: Female to Female Jumper Wire from GPIO **5** ➡️ Long leg of LED, Short Leg of LED ➡️ ground rail of the Solderless Breadboard  
   - 🟡Yellow LED: Female to Female Jumper Wire from GPIO **18** ➡️ Long leg of LED, Short Leg of LED ➡️ ground rail of the Solderless Breadboard   
   - 🟢Green LED: Female to Female Jumper Wire from GPIO **19** ➡️ Long leg of LED, Short Leg of LED ➡️ ground rail of the Solderless Breadboard
   - ⚫GND: Male to Female Jumper Wire from GND ➡️ the ground rail of the Solderless Breadboard

## ✔️ Finished Wiring Setup
<p align= "Center">
   <img width="700" height="700" alt="Wiring Setup" align = "center" src="https://github.com/user-attachments/assets/ad16861e-5693-4e79-b80d-ff53a5e0972b" />
</p>

3. 💻**Set up Arduino IDE**  
   - Install the latest Arduino IDE.  
   - Go to **File → Preferences** and add this board URL:  
     `https://dl.espressif.com/dl/package_esp32_index.json`  
   - In **Tools → Board → Boards Manager**, search for and install **"esp32"** by Espressif.

4. 🏗️**Create the project**  
   - Open Arduino IDE and create a new sketch.  
   - Paste the full code from [traffic_school.ino](https://github.com/boydjawun/esp32-web-controlled-traffic-light/blob/main/traffic_school.ino).  
   - (Optional) Change `ap_ssid` and `ap_password` at the top if you want a different network name/password.

5. 🤔**Upload the code**  
   - Select your ESP32 board and the correct COM port under **Tools**.  
   - Click **Upload**.  
   - After upload, open the **Serial Monitor** (set to **115200 baud**).

6. ✔️**Start the Access Point**  
   In the Serial Monitor you will see:
```
📡 Connect to WiFi: YESP32
🔑 Password: mypassword
🌐 Open your browser and go to: http://192.168.4.1
```
>This confirms the AP is running and shows the exact IP to use.

7. 🔗**Connect and control**  
- On your phone or laptop, connect to the WiFi network **YESP32** using password **mypassword**.  
- Open any browser and type the IP address shown (usually `http://192.168.4.1`).  
- Click the big colored buttons to turn the lights ON/OFF.  
- The page instantly updates to show the current status of each light.

8. **Enjoy & customize!**  
The web page is fully responsive and works great on phones.  
You can easily add more features (timers, auto-sequences, etc.) by extending the code.

## Project Demonstration
>The link below will take you to [Simple Electronics Tutorials]()
