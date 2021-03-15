import processing.serial.*;
import java.util.Arrays;

int alarmSize = 200;
int alarmX = 200;
int alarmY = 200;

boolean panic;

Serial myPort;
String sensorStr;

void setup() {
    rectMode(CENTER);
    textAlign(CENTER, CENTER);
    calmBg();
    noStroke();
    size(400, 400);
    
    panic = false;
    
    // initialize serial port communication
    System.out.println(Arrays.toString(Serial.list()));
    String portName = Serial.list()[2];
    System.out.println(portName);
    myPort = new Serial(this, portName, 9600);
}

void parseSerial() {
    sensorStr = trim(sensorStr);
    println(sensorStr);
    
    if (sensorStr == null) {
        return;
    }
    println(sensorStr);
    
    if (sensorStr.length() == 1) {
        panic = (parseInt(sensorStr) == 3);
    }
}

void draw() {
  
    if (myPort.available() > 0) {
        sensorStr = myPort.readStringUntil('\n');
        parseSerial();
    }
    
    if (panic) {
        panicBg();
        drawPanic();
    } else {
        drawCalm();
    }
    
};
