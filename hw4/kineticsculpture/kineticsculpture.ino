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
int servo2Pin = 2;  // Servo motor 2 pin

int stepperPorts[] = {14, 27, 26, 25};

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

void setupStepper() {
  // set pins to output
  for (int i = 0; i < 4; i++) {
    pinMode(stepperPorts[i], OUTPUT);
  }
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


void rotateStepper() {
  // Rotate a full turn
  Serial.println("turning one dir");
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  // Rotate a full turn towards another direction
  Serial.println("turning another dir");
  moveSteps(false, 32 * 64, 10);
  delay(1000);
}

void moveSteps(bool dir, int steps, byte ms) { 
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // Rotate a step
    delay(constrain(ms,3,20));        // Control the speed
  }
}

void moveOneStep(bool dir) {
  // Define a variable, use four low bit to indicate the state of port 
  static byte out = 0x01;
  // Decide the shift direction according to the rotation direction
  if (dir) { // ring shift left
    out!=0x08 ? out=out<<1 : out=0x01; 
  } else { // ring shift right
    out!=0x01 ? out=out>>1 : out=0x08;
  }
  // Output singal to each port
  for (int i = 0; i < 4; i++) {
    digitalWrite(stepperPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms){ for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}

void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}
