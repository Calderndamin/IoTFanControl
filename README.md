#Wireless Temperature-Controlled Fan System
This project involves developing a prototype for a device that controls the speed of a 12V fan based on the room temperature. The system can also be monitored and controlled wirelessly using a mobile app.
Components

    Microcontroller: Arduino/ESP32
    Temperature Sensor: Adafruit AHT20
    OLED Display: Adafruit SSD1306 (128x64)
    Fan: 12V fan
    Transistor: For controlling the fan speed
    Power Supply: Bench power supply
    Connecting Wires

Features

    Monitors room temperature using an AHT20 sensor.
    Displays the current temperature on a 128x64 OLED screen.
    Controls the fan speed based on the room temperature.
    Can be monitored and controlled wirelessly via a mobile app.

Circuit Diagram

Ensure you have the following connections:

    AHT20 Sensor connected to the microcontroller via I2C (SDA, SCL).
    OLED Display connected to the microcontroller via I2C (SDA, SCL).
    Fan connected to a PWM-capable pin on the microcontroller through a transistor.

How It Works

    Initialization: The microcontroller initializes the temperature sensor (AHT20) and the OLED display (SSD1306).
    Temperature Monitoring: In the loop function, the temperature sensor reads the room temperature.
    Fan Control: If the temperature is above 22°C, the fan turns on. If below, the fan turns off.
    Display Update: The current temperature is displayed on the OLED screen every 5 seconds.

Instructions

    Set Up Hardware: Connect the components as per the circuit diagram.
    Upload Code: Upload the provided code to your microcontroller using the Arduino IDE.
    Power Up: Power the system using a bench power supply.
    Monitor and Control: Monitor the temperature on the OLED display and control the fan speed based on the temperature readings.

Libraries Required

    Adafruit AHTX0
    Adafruit GFX Library
    Adafruit SSD1306

Ensure you have these libraries installed in your Arduino IDE.
