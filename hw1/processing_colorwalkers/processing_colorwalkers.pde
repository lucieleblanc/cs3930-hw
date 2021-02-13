Walker walkers[];
float mean = 0;
float standardDeviation = 10;
int numWalkers = 3;

void setup() {
  fullScreen();
  background(0, 0, 0);
  
  walkers = new Walker[numWalkers];
  for (int i = 0; i < numWalkers; i++) {
    walkers[i] = new Walker();
  }
  
  mean = 0;
  standardDeviation = 10;
}

public class Walker {
  
  float x;
  float y;
  float r;
  float g;
  float b;
  float size;
  
  public Walker() {
    this.x = width/2 + randomGaussian() * width/6;
    this.y = height/2 + randomGaussian() * height/6;
    this.r = 125;
    this.g = 125;
    this.b = 125;
    this.size = 20;
  }
  
  void display() {
    strokeWeight(abs(size * randomGaussian()));   
    stroke(this.r, this.g, this.b);
    point(this.x, this.y);
  }

  void walk() {
    
    float xStepSize = standardDeviation * randomGaussian() + mean;
    float yStepSize = standardDeviation * randomGaussian() + mean;
  
    this.x += xStepSize;
    this.x %= width;
    
    this.y += yStepSize;
    this.y %= height;
    
    float rColorChange = 20 * randomGaussian();
    this.r += rColorChange;
    
    float gColorChange = 20 * randomGaussian();
    this.g += gColorChange;
    
    float bColorChange = 20 * randomGaussian();
    this.b += bColorChange;
  }

}

void draw() {
  fill(0, 0, 0, 0.5);
  noStroke();
  rect(0, 0, width, height);
  for (Walker w : walkers) {
    w.walk();
    w.display();
  }
}
