void calmBg() {
    background(255, 255, 255);
    noStroke();

    fill(66, 38, 17);
    rect(width / 2, height * (5.0/6), width, height / 3.0);
    fill(153, 73, 15);
    rect(width / 2, height * (3.0/4), width, height / 6.0);
    
    fill(153, 153, 153);
    arc(alarmX - 80, alarmY - 70, 100, 100, radians(135), radians(320));
    arc(alarmX + 80, alarmY - 70, 100, 100, radians(220), radians(405));
    
    fill(197, 235, 225);
    ellipse(alarmX, alarmY, alarmSize * 1.1, alarmSize * 1.1);
    fill(255, 255, 255);
    ellipse(alarmX, alarmY, alarmSize, alarmSize);
    
    fill(130, 130, 130);
    ellipse(alarmX + 110, alarmY - 110, alarmSize / 15, alarmSize / 15);
    ellipse(alarmX - 110, alarmY - 110, alarmSize / 15, alarmSize / 15);
    
    fill(46, 46, 46);
    pushMatrix();
    translate(alarmX, alarmY);
    for (int i = 0; i < 12; i++) {
        rect(0, alarmSize/2.5, alarmSize / 25, alarmSize / 15);
        rotate(radians(30));
    }
    popMatrix();
    
    pushMatrix();
    translate(alarmX, alarmY);
    rotate(radians(40));
    fill(150, 150, 150);
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10);
    rotate(radians(-80));
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10);
    popMatrix();
    
};

void panicBg() {
    
    pushMatrix();
    
    rotate(radians(random(-5, 5)));
    
    background(237, 121, 121);

    fill(173, 88, 28);
    rect(width / 2, height * (5.0/6), width, height / 3.0);
    fill(219, 124, 57);
    rect(width / 2, height * (3.0/4), width, height / 6.0);
    
    noStroke();
    fill(0, 0, 0);
    ellipse(alarmX, alarmY, alarmSize * 1.1, alarmSize * 1.1);
    fill(255, 136, 0);
    ellipse(alarmX, alarmY, alarmSize, alarmSize);
    
    fill(57, 97, 150);
    arc(alarmX - 80, alarmY - 70, 100, 100, radians(135), radians(320));
    arc(alarmX + 80, alarmY - 70, 100, 100, radians(220), radians(405));
    fill(28, 28, 28);
    ellipse(alarmX + 110, alarmY - 110, alarmSize / 15, alarmSize / 15);
    ellipse(alarmX - 110, alarmY - 110, alarmSize / 15, alarmSize / 15);
    
    fill(46, 46, 46);
    pushMatrix();
    translate(alarmX, alarmY);
    for (int i = 0; i < 12; i++) {
        rect(0, alarmSize/2.5, alarmSize / 25, alarmSize / 15);
        rotate(radians(30));
    }
    popMatrix();
    
    pushMatrix();
    translate(alarmX, alarmY);
    rotate(radians(40));
    fill(61, 61, 61);
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10);
    rotate(radians(-80));
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10);
    popMatrix();
    
    popMatrix();
    
};

void drawCalm() {
    fill(255, 255, 255);
    ellipse(alarmX, alarmY, alarmSize / 1.5, alarmSize / 1.5);
    
    fill(82, 82, 82);
    text("rest time", alarmX, alarmY - 20);
    
    fill(0, 0, 0);
    ellipse(alarmX, alarmY, alarmSize / 40, alarmSize / 40);
    
    pushMatrix();
    translate(alarmX, alarmY);
    rotate(radians(millis()/10));
    ellipse(0, alarmSize/6.5, alarmSize / 20, alarmSize / 3);
    popMatrix();
    
    pushMatrix();
    translate(alarmX, alarmY);
    rotate(radians(millis()/600));
    ellipse(0, alarmSize/10, alarmSize / 20, alarmSize / 5);
    popMatrix();
    
};

void drawPanic() {
    fill(255, 136, 0);
    ellipse(alarmX, alarmY, alarmSize / 1.5, alarmSize / 1.5);
    
    fill(255, 0, 4);
    text("WAKE UP", alarmX, alarmY - 20);
    
    fill(0, 0, 0);
    ellipse(alarmX, alarmY, alarmSize / 40, alarmSize / 40);
    
    pushMatrix();
    translate(alarmX, alarmY);
    rotate(radians(random(0, 360)));
    ellipse(random(-5, 5), alarmSize/random(6,9), alarmSize / 20, alarmSize / 3);
    popMatrix();
    
    pushMatrix();
    translate(alarmX, alarmY);
    rotate(radians(random(0, 360)));
    ellipse(random(5, -5), alarmSize/random(6,8), alarmSize / 20, alarmSize / 5);
    popMatrix();
};
