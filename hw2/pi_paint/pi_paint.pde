import processing.serial.*;
import java.util.Arrays;

final color canvasColor = color(255, 255, 255);
final int smallR = 20;
final int largeR = 50;

int vrx;
int vry;
int swz;

boolean drawButton;
boolean eraseButton;
boolean smallBrush;

Paintbrush pb;

Serial myPort;
String sensorStr;


class Paintbrush {
  
  int size;
  int x;
  int y;
  int r;
  int g;
  int b;
  
  public Paintbrush() {
    this.size = smallR;
    this.x = width / 2;
    this.y = height / 2;
    this.r = 125;
    this.g = 125;
    this.b = 125;
  }
  
  void mark() {
    fill(this.r, this.g, this.b);
    ellipse(this.x, this.y, this.size, this.size);
    
    this.r += random(-5, 6);
    this.r = max(this.r, 0);
    this.r = min(this.r, 255);
    
    this.g += random(-5, 6);
    this.g = max(this.g, 0);
    this.g = min(this.g, 255);
    
    this.b += random(-5, 6);
    this.b = max(this.b, 0);
    this.b = min(this.b, 255);
  }
  
  void erase() {
    fill(canvasColor);
    ellipse(this.x, this.y, this.size, this.size);
  }
  
  void move(int moveX, int moveY) {
    this.x += moveX;
    if (this.x > width) {
      this.x = width;
    } else if (this.x < 0) {
      this.x = 0;
    }
    
    this.y += moveY;
    if (this.y > height) {
      this.y = height;
    } else if (this.y < 0) {
      this.y = 0;
    }
  }
  
  void setSize(int newSize) {
    this.size = newSize;
  }
  
}

int vrxToMove(int vrx) {
  if (vrx > 1860) {
    return 1;
  } else if (vrx < 1780) {
    return -1;
  }
  return 0;
}

int vryToMove(int vry) {
  if (vry > 1970) {
    return 1;
  } else if (vry < 1890) {
    return -1;
  }
  return 0;
}


void updateBrush() {
  if (smallBrush) {
    pb.setSize(smallR);
  } else {
    pb.setSize(largeR);
  }
}

void setup() {
  size(500, 500);
  background(canvasColor);
  noStroke();
  pb = new Paintbrush();
  updateBrush();
  
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
  String[] sensorData = split(sensorStr,',');
  
  if (sensorData.length == 6) {
    vry = parseInt(sensorData[0]);
    vrx = 4095 - parseInt(sensorData[1]);
    println(vrx);
    println(vry);
    
    int drawOn = parseInt(sensorData[3]);
    drawButton = (drawOn == 0);
    println(drawButton);
    
    int eraseOn = parseInt(sensorData[4]);
    eraseButton = (eraseOn == 0);
    println(drawButton);
    
    int switchOn = parseInt(sensorData[5]);
    smallBrush = (switchOn == 0);
    println(smallBrush);
  }
}

void draw() {
  
  if (myPort.available() > 0) {
    sensorStr = myPort.readStringUntil('\n');
    parseSerial();
  }
  
  if (drawButton && eraseButton) {
    background(canvasColor);
  }
   
  updateBrush();
  
  // determine if joystick has moved
  pb.move(vrxToMove(vrx), vryToMove(vry));
  
  if (drawButton) {
    pb.mark();
  } else if (eraseButton) {
    pb.erase();
  }
  
}
