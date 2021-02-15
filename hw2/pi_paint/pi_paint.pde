final color canvasColor = color(255, 255, 255);
final color startColor = color(125, 125, 125);
final int smallR = 20;
final int largeR = 50;

int vrx;
int vry;
int swz;

boolean drawButton;
boolean eraseButton;
boolean smallBrush;

Paintbrush pb;

class Paintbrush {
  
  int size;
  int x;
  int y;
  color col;
  
  public Paintbrush() {
    this.size = smallR;
    this.col = startColor;
    this.x = width / 2;
    this.y = height / 2;
  }
  
  void mark() {
    fill(this.col);
    ellipse(this.x, this.y, this.size, this.size);
  }
  
  void erase() {
    fill(canvasColor);
    ellipse(this.x, this.y, this.size, this.size);
  }
  
  void move(int moveX, int moveY) {
    this.x += moveX;
    this.y += moveY;
  }
  
  void setSize(int newSize) {
    this.size = newSize;
  }
  
}

int vrxToMove(int vrx) {
  if (vrx > 1830) {
    return 1;
  } else if (vrx < 1810) {
    return -1;
  }
  return 0;
}

int vryToMove(int vry) {
  if (vry > 1940) {
    return 1;
  } else if (vry < 1920) {
    return -1;
  }
  return 0;
}

void setup() {
  background(canvasColor);
  pb = new Paintbrush();
  
  if (smallBrush) {
    pb.setSize(smallR);
  } else {
    pb.setSize(largeR);
  }

}

void draw() {
  
  if (drawButton && eraseButton) {
    background(canvasColor);
  }
  
  if (smallBrush) {
    pb.setSize(smallR);
  } else {
    pb.setSize(largeR);
  }
  
  // determine if joystick has moved
  pb.move(vrxToMove(vrx), vryToMove(vry));
  
  if (drawButton) {
    pb.mark();
  } else if (eraseButton) {
    pb.erase();
  }
  
}
