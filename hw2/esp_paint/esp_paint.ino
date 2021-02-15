#define drawPin 25
#define drawLight 0
#define erasePin 26
#define eraseLight 2
#define switchPin 2

int xyzPins[] = { 13, 12, 14 };
               // VRX VRY SW

void setup() {
  Serial.begin(115200);
  // set pinmode for joystick Z-axis button
  pinMode(xyzPins[2], INPUT_PULLUP);
  
  // set pinmode for drawButton
  pinMode(drawPin, INPUT);
  
  // set pinmode for eraseButton
  pinMode(erasePin, INPUT);
  
  // set pinmode for switch
  pinMode(switchPin, INPUT);
  
}

void loop() {
  // read from each pin, save each value in a var
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);
  
  int drawButtonVal = digitalRead(drawPin);
  Serial.println(drawButtonVal);
  // TODO: if draw on, turn on draw light

  int eraseButtonVal = digitalRead(erasePin);
  Serial.println(eraseButtonVal);
  // TODO: if erase on, turn on erase light

  int switchVal = digitalRead(switchPin);
  Serial.println(switchVal);

  // output a value to the Serial console
  // based on the combination of inputs
  // not clear how to do this most efficiently
  // maybe use bitwise ops?
  
  // Serial.print('0');
  delay(100);
}
