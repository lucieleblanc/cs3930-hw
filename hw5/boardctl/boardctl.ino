#define BRIDGE_LED 2
#define BRIDGE_SQUARE 13
#define TRAM_LED 0
#define TRAM_SQUARE 12

bool tramLocation;

void setup() {
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
    tramLocation = false;
    updateTram();
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
    println("tram is at position " + tramLocation);
    updateTram();
}

void updateTram(location) {
    if (location == true) {
        
    }
}
