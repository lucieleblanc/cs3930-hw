#include <ESP32Servo.h>

#define BRIDGE_LED 2
#define BRIDGE_SQUARE 13
#define TRAM_LED 0
#define TRAM_SQUARE 12
#define TRAM_SERVO 15

bool tramLocation;
Servo tramServo;

void setup() {
    Serial.begin(115200);
    setupBridge();
    setupTram();
    Serial.println("Done setting up!");
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
    delay(50);
}

void checkBridge() {
    if (digitalRead(BRIDGE_SQUARE) == LOW) {
        Serial.println("Bridge read LOW");
        digitalWrite(BRIDGE_LED,LOW); 
    } else {
        Serial.println("Bridge read HIGH");
        digitalWrite(BRIDGE_LED,HIGH); 
        delay(500);
    }
}

void checkTram() {
    if (digitalRead(TRAM_SQUARE) == HIGH) {
        Serial.println("Tram read HIGH");
        digitalWrite(TRAM_LED,LOW);
    } else {
        Serial.println("Tram read LOW");
        blinkTramLED();
        moveTram();
        delay(5000);
    }
}

void blinkTramLED() {
    for (int i = 0; i < 5; i++) {
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
    int maxDeg = 100;
    int minDeg = 20;
    int delayTime = 40;

    int startPos, endPos, posStep;
    if (!tramLocation) {
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
