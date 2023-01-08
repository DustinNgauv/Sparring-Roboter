void SparringMode() {    

  // executes set of strikes based on the strike volume settings
  for (int i = 0; i < volume; i++) {  

    // stops servos if a round has ended
    if (countdowntime <= 1 || countdowntime > 4000000000) {              
      break;
    }
    
    // chooses a random value between 1-4
    int servo = random(1,5);

    // moves a servo based on chosen value
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

// functions to move each servo based on the speed settings

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

// function wich calculates the rough time a servo needs to execute a strike based off the speed setting
unsigned long servoDuration(int servoSpeed) {
  return (-410.2 * log(0.2 * servoSpeed - 3) + 1445.5);
}