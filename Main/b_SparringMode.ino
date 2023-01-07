void SparringMode() {   
  unsigned long time1 = 0;  
  unsigned long initialTime = millis();
    
  for (int i = 0; i < volume; i++) {         
    if (countdowntime <= 1 || countdowntime > 4000000000) {              
      break;
    }
    
    int servo = random(1,5);

    switch (servo) {
    case 1:
    leftHook();
    break;

    case 2:
    leftStraight();
    break;

    case 3:
    rightStraight();
    break;

    case 4:
    rightHook();
    break;
    }               
  }               
}

void rightStraight() {
  servo3.write(180, (255 * speed / 100), true);
  servo3.write(90, (255 * speed / 100), true);
}

void leftStraight() {
  servo2.write(0, (255 * speed / 100), true);
  servo2.write(90, (255 * speed / 100), true);
}

void rightHook() {
  servo4.write(180, (255 * speed / 100), true);
  servo4.write(90, (255 * speed / 100), true);
}

void leftHook() {
  servo1.write(0, (255 * speed / 100), true);
  servo1.write(90, (255 * speed / 100), true);
}

unsigned long servoDuration(int servoSpeed) {
  return (-410.2 * log(0.2 * servoSpeed - 3) + 1445.5);
}

void measurespeed(int s) {
  long x = millis();
  servo3.write(180, s, true);
  servo3.write(90, s, true);
  long y = millis();

  float z = s *100 / 255;
  myGLCD.print(String(y-x), 20, 20);  
  myGLCD.print(String(-410.2 * log(0.2 * z - 3) + 1445.5), 20, 50);
}