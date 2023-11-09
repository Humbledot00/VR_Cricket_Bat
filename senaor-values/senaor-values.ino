#include <Wire.h>
#include "MPU9250.h"
#include <ESP8266WiFi.h>
 
MPU9250 mpu;
const char* ssid = "CSD";     // Replace with your Wi-Fi network name
const char* password = "csd@NITK2014"; // Replace with your Wi-Fi password

IPAddress serverIP(10,100,81,184);  // Replace with the IP address you want to connect to
int serverPort = 1883;  // Replace with the desired port number

WiFiClient client;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);

    if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
    WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.println("Connecting to WiFi...");
   }
   Serial.println("Connected to WiFi");

  //connect to the server
  if (client.connect(serverIP, serverPort)) {
        Serial.println("Connected to server...");
    } else {
        Serial.println("Server Connection failed...................................................................................................................");
    }

}

void loop() {
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            print_roll_pitch_yaw();
            prev_ms = millis();
        }
    }
    
//     if (client.connected()) {
//         // Send data to the server
//         client.println("Hello, server!");

//         // Check for data from the server
//         while (client.available()) {
//             char c = client.read();
//             // Process and handle received data
//         }
//     } else {
//         // Handle reconnection or error recovery here
//         client.connect(serverIP, serverPort);
//     }

//     // Add any other control or sensor-related logic here
//     // Implement appropriate delays if needed
//     //delay(1000);
 }

void print_roll_pitch_yaw() {
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);
}
