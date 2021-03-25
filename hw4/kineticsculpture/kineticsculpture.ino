/* Adapted from https://github.com/mbennett12/kinetic-sculpture-webapi/blob/main/example_HTTP_get.ino */

#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define USE_SERIAL Serial
#include "wifi_secrets.h"

const char *ssid_Router     = YOUR_WIFI_NAME; //Enter the router name
const char *password_Router = YOUR_WIFI_PASSWORD; //Enter the router password

String address= "http://165.227.76.232:3000/ll3163/running";

Servo myservo1; // create servo object to control a servo 
Servo myservo2;

int posVal = 0; // variable to store the servo position 
int servo1Pin = 15; // Servo motor 1 pin
int servo2Pin = 14; // Servo motor 2 pin

void setup() {
    setupWifi();
    setupServo();
}

void setupWifi() {
    USE_SERIAL.begin(115200);
  
    WiFi.begin(ssid_Router, password_Router);
    USE_SERIAL.println(String("Connecting to ")+ssid_Router);
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        USE_SERIAL.print(".");
    }
    USE_SERIAL.println("\nConnected, IP address: ");
    USE_SERIAL.println(WiFi.localIP());
    USE_SERIAL.println("Setup End");
}

void setupServo() {
    myservo1.setPeriodHertz(50); // standard 50 hz servo
    myservo1.attach(servo1Pin, 500, 2500); // attaches the servo on servoPin to the servo object

    myservo2.setPeriodHertz(50); // standard 50 hz servo
    myservo2.attach(servo2Pin, 500, 2500); // attaches the servo on servoPin to the servo object
}

void loop() {
  
  if((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(address);
 
    int httpCode = http.GET(); // start connection and send HTTP header
    if (httpCode == HTTP_CODE_OK) { 
        String response = http.getString();
        if (response.equals("false")) {
            // Do not run sculpture, perhaps sleep for a couple seconds
            delay(5000);
        }
        else if(response.equals("true")) {
            // Run sculpture
            flap();
        }
        USE_SERIAL.println("Response was: " + response);
    } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
    delay(500); // sleep for half of a second
  }
}


void flap() {
    int maxDeg = 60;
    for (posVal = 0; posVal <= maxDeg; posVal += 1) { 
        myservo1.write(posVal);
        myservo2.write(posVal);
        delay(10);
    }
    for (posVal = maxDeg; posVal >= 0; posVal -= 1) {
        myservo1.write(posVal);
        myservo2.write(posVal);
        delay(10);
    }
}
