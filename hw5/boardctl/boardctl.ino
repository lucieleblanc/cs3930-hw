#define PIN_LED 2
#define PIN_BUTTON 13

void setup() {
    // we'll send signals to the LED
    pinMode(PIN_LED, OUTPUT);

    // we'll receive signals from the button
    pinMode(PIN_BUTTON, INPUT); 
}

void loop() {
    if (digitalRead(PIN_BUTTON) == LOW) {
        digitalWrite(PIN_LED,HIGH); 
    } else {
        digitalWrite(PIN_LED,LOW); 
    }
}
