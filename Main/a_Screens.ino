void drawHomeScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Sparring Mode", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myButtons.setTextFont(GroteskBold24x48);
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, VGA_RED);

  Rounds_btn = myButtons.addButton(200, 100, 150, 60, "");
  Speed_btn = myButtons.addButton(450, 100, 150, 60, "");
  Time_btn = myButtons.addButton(200, 200, 150, 60, "");
  Level_btn = myButtons.addButton(450, 200, 150, 60, "");
  Rest_btn = myButtons.addButton(200, 300, 150, 60, "");
  Volume_btn = myButtons.addButton(450, 300, 150, 60, "");
  myButtons.drawButtons();

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  Start_btn = myButtons.addButton(300, 380, 200, 80, "START");
  myButtons.drawButton(Start_btn);


  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("Rounds", 253, 105);
  myGLCD.print("Speed", 506, 105);
  myGLCD.print("Time", 260, 205);
  myGLCD.print("Level", 509, 205);
  myGLCD.print("Rest", 262, 305);
  myGLCD.print("Strike Volume", 475, 305);

  myGLCD.setFont(BigFont);
  myGLCD.printNumI(rounds, 270, 125);
  myGLCD.print(String(speed) + "%", 508, 125);
  myGLCD.print(millisToTimeStr(time), 245, 225);
  myGLCD.printNumI(level, 521, 225);
  myGLCD.print(millisToTimeStr(rest), 245, 325);
  myGLCD.printNumI(volume, 520, 325);

  while (true) {
    if (myTouch.dataAvailable()) {
      int pressed = myButtons.checkButtons();

      if (pressed == Rounds_btn) {
        drawRoundsScreen();
      } else if (pressed == Speed_btn) {
        drawSpeedScreen();
      } else if (pressed == Time_btn) {
        drawTimeScreen();
      } else if (pressed == Level_btn) {
        drawLevelScreen();
      } else if (pressed == Rest_btn) {
        drawRestScreen();
      } else if (pressed == Volume_btn) {
        drawVolumeScreen();
      } else if (pressed == Start_btn) {
        drawSparringScreen();
      }
    }
  }
}

void drawRoundsScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Rounds", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myGLCD.setFont(SevenSeg_XXXL_Num);
  myGLCD.printNumI(rounds, CENTER, 200);
}

void drawSpeedScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Adjust Speed", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);
}

void drawTimeScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Time", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);
}

void drawLevelScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Level", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);
}

void drawRestScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Rest", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);
}

void drawVolumeScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Strike Volume", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);
}

void drawSparringScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);

  long initialseconds = millis() / 1000;
  long countdowntime; 
  long start_time = 0;

  myButtons.setTextFont(GroteskBold24x48);
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, VGA_RED);
  StopSpar_btn = myButtons.addButton(300, 380, 200, 80, "STOP");
  myButtons.drawButtons();
  

  for (int i = 0; i < rounds; i++) {
    myGLCD.print("Round " + String(i + 1) + "/" + String(rounds), CENTER, 50);
    myGLCD.setColor(255, 255, 255);
    myGLCD.fillRoundRect(100, 315, 700, 300);  
    

    while (true) {      
      countdowntime = (time / 1000) + initialseconds + start_time - (millis() / 1000);
      long countdown_minute = ((countdowntime / 60) % 60);
      long countdown_sec = countdowntime % 60;
      float progress = 1 - (countdowntime / float(time / 1000));
      myGLCD.print(String(countdown_minute) + ":" + String(countdown_sec), CENTER, 200);      
      myGLCD.setColor(0, 26, 255);
      myGLCD.fillRoundRect(100, 315, 100 + progress*600, 300);
      myGLCD.setColor(255, 255, 255);

      if (countdowntime == 0) {        
        break;
      }        
      delay(100);
    }  
      
    if (countdowntime == 0 && (i + 1) == rounds) {
      delay(1000);
      drawHomeScreen();
      break;
    }


    start_time = (time / 1000) * (i+1);      
  }    
}

String millisToTimeStr(long milliseconds) {
  String minutes = String(milliseconds / 60000);
  String seconds = String((milliseconds / 1000) % 60);
  if (seconds.length() < 2) {
    seconds = "0" + seconds;
  }
  return minutes + ":" + seconds;
}