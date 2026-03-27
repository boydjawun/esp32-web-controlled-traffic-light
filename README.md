# 🚦 Traffic School - ESP32 Web-Controlled Traffic Light

<img src = https://github.com/user-attachments/assets/313cd398-2210-4c53-85de-a74ea84082da  width = 600 height = 400/>

## Description
This project turns an ESP32 into a fully wireless traffic light simulator for "Traffic School" demos, classrooms, or workshops.  
It creates its own WiFi Access Point (no router needed) so anyone can connect with their phone or laptop and control the red, yellow, and green lights through a clean, responsive web interface.  
Real-time status is shown on the page, making it perfect for learning IoT, web servers, and basic electronics.

## Features
- Self-hosted WiFi Access Point (SSID: `YESP32`)
- Mobile-friendly web dashboard
- One-click toggle for each light with live ON/OFF status
- No internet required — works completely offline

## Tools & Components Used

### Hardware
- ESP32 Development Board (any ESP32 DevKit)
- Red LED + 220Ω resistor
- Yellow LED + 220Ω resistor
- Green LED + 220Ω resistor
- Breadboard + jumper wires
- USB cable for programming/power

### Software
- Arduino IDE
- ESP32 Arduino Core (via Board Manager)
- Built-in libraries: `WiFi.h` and `WebServer.h`

## Step-by-Step Instructions (Based on the Code)

1. **Gather your parts**  
   Collect the ESP32, three LEDs, resistors, breadboard, and wires.

2. **Wire the LEDs**  
   - Red LED: Anode → 220Ω resistor → GPIO **5**, Cathode → GND  
   - Yellow LED: Anode → 220Ω resistor → GPIO **18**, Cathode → GND  
   - Green LED: Anode → 220Ω resistor → GPIO **19**, Cathode → GND  
   (All LEDs are active-HIGH as used in the code.)

3. **Set up Arduino IDE**  
   - Install the latest Arduino IDE.  
   - Go to **File → Preferences** and add this board URL:  
     `https://dl.espressif.com/dl/package_esp32_index.json`  
   - In **Tools → Board → Boards Manager**, search for and install **"esp32"** by Espressif.

4. **Create the project**  
   - Open Arduino IDE and create a new sketch.  
   - Paste the full code from `traffic_school.ino` (the improved version with `WiFi.softAP`).  
   - (Optional) Change `ap_ssid` and `ap_password` at the top if you want a different network name/password.

5. **Upload the code**  
   - Select your ESP32 board and the correct COM port under **Tools**.  
   - Click **Upload**.  
   - After upload, open the **Serial Monitor** (set to **115200 baud**).

6. **Start the Access Point**  
   In the Serial Monitor you will see:

   📡 Connect to WiFi: YESP32
🔑 Password: mypassword
🌐 Open your browser and go to: http://192.168.4.1

This confirms the AP is running and shows the exact IP to use.

7. **Connect and control**  
- On your phone or laptop, connect to the WiFi network **YESP32** using password **mypassword**.  
- Open any browser and type the IP address shown (usually `http://192.168.4.1`).  
- Click the big colored buttons to turn the lights ON/OFF.  
- The page instantly updates to show the current status of each light.

8. **Enjoy & customize!**  
The web page is fully responsive and works great on phones.  
You can easily add more features (timers, auto-sequences, etc.) by extending the code.

## Project Structure
