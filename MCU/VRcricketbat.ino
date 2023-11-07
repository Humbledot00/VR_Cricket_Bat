

// #include <Wire.h>
// #include "MPU9250.h"
 
// MPU9250 mpu;

// void setup() {
//     Serial.begin(115200);
//     Wire.begin();
//     delay(2000);

//     if (!mpu.setup(0x68)) {  // change to your own address
//         while (1) {
//             Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
//             delay(5000);
//         }
//     }
// }

// void loop() {
//     if (mpu.update()) {
//         static uint32_t prev_ms = millis();
//         if (millis() > prev_ms + 25) {
//             print_roll_pitch_yaw();
//             prev_ms = millis();
//         }
//     }
// }

// void print_roll_pitch_yaw() {
//     Serial.print("Yaw, Pitch, Roll: ");
//     Serial.print(mpu.getYaw(), 2);
//     Serial.print(", ");
//     Serial.print(mpu.getPitch(), 2);
//     Serial.print(", ");
//     Serial.println(mpu.getRoll(), 2);
// }

#include <ESP8266WiFi.h>

const char* ssid = "CSD";     // Replace with your Wi-Fi network name
const char* password = "csd@NITK2014"; // Replace with your Wi-Fi password

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

// void loop() {
//   // Print the ESP8266 IP address
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Add your code here

//   delay(10000); // Delay for 10 seconds
// }

