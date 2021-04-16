#include <ESP32Servo.h>

#define BRIDGE_LED 2
#define BRIDGE_SQUARE 13
#define TRAM_LED 0
#define TRAM_SQUARE 12
#define TRAM_SERVO 14

bool tramLocation;
Servo tramServo;

void setup() {
    Serial.begin(115200);
    setupBridge();
    setupTram();
}

void setupBridge() {
    pinMode(BRIDGE_LED, OUTPUT);
    pinMode(BRIDGE_SQUARE, INPUT); 
}

void setupTram() {
    pinMode(TRAM_LED, OUTPUT);
    pinMode(TRAM_SQUARE, INPUT); 
    setupServo();
    tramLocation = false;
    updateTram();
}

void setupServo() {
    tramServo.setPeriodHertz(50);
    tramServo.attach(TRAM_SERVO, 500, 2500);
}

void loop() {
    checkBridge();
    checkTram();
}

void checkBridge() {
    if (digitalRead(BRIDGE_SQUARE) == LOW) {
        digitalWrite(BRIDGE_LED,HIGH); 
    } else {
        digitalWrite(BRIDGE_LED,LOW); 
    }
}

void checkTram() {
    if (digitalRead(TRAM_SQUARE) == LOW) {
        blinkTramLED();
        moveTram();
    } else {
        digitalWrite(TRAM_LED,LOW);
    }
}

void blinkTramLED() {
    for (int i = 1; i < 5; i++) {
        digitalWrite(TRAM_LED,HIGH);
        delay(500);
        digitalWrite(TRAM_LED,LOW);
        delay(500);
    }
}

void moveTram() {
    tramLocation = !tramLocation;
    Serial.println("tram is at position " + tramLocation);
    updateTram();
}

void updateTram() {
    int maxDeg = 60;
    int minDeg = 0;
    int delayTime = 40;

    int startPos, endPos, posStep;
    if (tramLocation) {
      startPos = minDeg;
      endPos = maxDeg;
      posStep = 1;
    } else {
      startPos = maxDeg;
      endPos = minDeg;
      posStep = -1;
    }
    
    for (int posVal = startPos; posVal != endPos; posVal += posStep) { 
        tramServo.write(posVal);
        delay(delayTime);
    }
}
