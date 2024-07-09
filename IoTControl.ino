  #include <Adafruit_AHTX0.h>
  #include <SPI.h>
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>

  Adafruit_AHTX0 aht;

    #define SCREEN_WIDTH 128 // OLED display width, in pixels
    #define SCREEN_HEIGHT 64 // OLED display height, in pixels

    // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
    #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
    #define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET);

    #define LOGO_HEIGHT   16
    #define LOGO_WIDTH    16

  int PWMpin = 16;  // Choose a suitable PWM-capable pin
  int PWMvalue = 0;  // Start with the fan off
  const int fanPin = 23;  // Pin connected to the base of the transistor

  void setup() {

    pinMode(PWMpin, OUTPUT);
    pinMode(fanPin, OUTPUT);

    Wire1.begin(18, 19);
    Serial.begin(115200);

    //detects DHT20
    if (! aht.begin()) {
      Serial.println("Could not find AHT. Check wiring");
      while (1) delay(10);
    }
    Serial.println("AHT20 found");

    
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println(F("SSD1306 allocation failed"));
      for(;;); // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(5000); // Pause for 2 seconds

    // Clear the buffer
    display.clearDisplay();

    testdrawstyles();

  }

  void loop() {

    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data

    if(temp.temperature >= 22.0){
      digitalWrite(fanPin, HIGH);  // Turn the fan ON
    }else{
      digitalWrite(fanPin, LOW);  // Turn the fan OFF
    }

    // Clear the previous display content
    display.clearDisplay();

    // Set text properties
    display.setTextSize(1); 
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(25, 25);

    // Print the temperature 
    display.print("Temp: "); 
    display.print(temp.temperature);
    display.print(" C");

    // Update the display
    display.display(); 

    delay(5000); // Update every 5 seconds

  }

  void testdrawstyles(void) {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Hey there!"));
    display.println(F("What's good?"));

    display.display();
    delay(2000);

  }
