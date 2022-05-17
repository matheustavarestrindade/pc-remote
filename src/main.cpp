#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

// OLED FeatherWing buttons map to different pins depending on board.
// The I2C (Wire) bus may also be different.
#define BUTTON_A 15
#define BUTTON_B 32
#define BUTTON_C 14
#define WIRE Wire


Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);

void setup() {
    Serial.begin(9600);

    Serial.println("OLED FeatherWing test");
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Address 0x3C for 128x32

    Serial.println("OLED begun");

    // Show image buffer on the display hardware.
    // Since the buffer is intialized with an Adafruit splashscreen
    // internally, this will display the splashscreen.
    display.display();
    delay(1000);

    // Clear the buffer.
    display.clearDisplay();
    display.display();

    Serial.println("IO test");

    pinMode(BUTTON_A, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
    pinMode(BUTTON_C, INPUT_PULLUP);

    // text display tests
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Connecting to SSID\n'adafruit':");
    display.print("connected!");
    display.println("IP: 10.0.1.23");
    display.println("Sending val #0");
    display.setCursor(0, 0);
    display.display();  // actually display all of the above
}

void loop() {
    if (!digitalRead(BUTTON_A)) display.print("A");
    if (!digitalRead(BUTTON_B)) display.print("B");
    if (!digitalRead(BUTTON_C)) display.print("C");
    delay(10);
    yield();
    display.display();
}

// #include <WiFi.h>

// #include "HomeAutomation.h"

// #define RELAY_GPIO 12
// #define CPU_ONLINE_CHECK_PIN 14

// char* device_name = "Computer Manager";
// char* device_type = "computer_manager_v1";

// HomeAutomation automation(device_name, device_type);
// bool isPCPowerOn = false;

// void handleRequest() {
//     String data = "{";
//     data += "\"pc_online\":";
//     data += (isPCPowerOn ? "true" : "false");
//     data += "}";

//     automation.setContentLength(CONTENT_LENGTH_UNKNOWN);
//     automation.sendHeader("Content-Length", String(data.length()));
//     automation.send(200, "text/json", data);
// }

// void handlePowerOn() {
//     // Switch relay on for 3 sec

//     digitalWrite(RELAY_GPIO, 1);
//     delay(3000);
//     digitalWrite(RELAY_GPIO, 0);

//     automation.send(200, "text/json", "{\"success\": true}");
// }

// void handleForceShutdown() {
//     // Switch relay on for 10 sec

//     digitalWrite(RELAY_GPIO, 1);
//     delay(10000);
//     digitalWrite(RELAY_GPIO, 0);

//     automation.send(200, "text/json", "{\"success\": true}");
// }

// void setup() {
//     Serial.begin(115200);
//     // Serial.print("STARTING :\n ");

//     pinMode(RELAY_GPIO, OUTPUT);
//     pinMode(CPU_ONLINE_CHECK_PIN, INPUT);

//     automation.on("/data", handleRequest);
//     automation.on("/power_on", handlePowerOn);
//     automation.on("/power_off", handlePowerOn);
//     automation.on("/force_shutdown", handleForceShutdown);
//     automation.setup();
// }

// uint64_t lastUpdateTime = millis();

// void loop() {
//     automation.networkLoop();
//     if (lastUpdateTime < millis()) {
//         isPCPowerOn = digitalRead(CPU_ONLINE_CHECK_PIN) > 0;
//         lastUpdateTime = millis() + 1000;
//     }
// }
