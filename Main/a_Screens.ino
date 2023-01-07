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

  int Rounds_btn = myButtons.addButton(200, 100, 150, 60, "");
  int Speed_btn = myButtons.addButton(450, 100, 150, 60, "");
  int Time_btn = myButtons.addButton(200, 200, 150, 60, "");
  int Level_btn = myButtons.addButton(450, 200, 150, 60, "");
  int Rest_btn = myButtons.addButton(200, 300, 150, 60, "");
  int Volume_btn = myButtons.addButton(450, 300, 150, 60, "");
  myButtons.drawButtons();

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  int Start_btn = myButtons.addButton(300, 380, 200, 80, "START");
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
  myGLCD.printNumI(rounds, 250, 125, 2);
  myGLCD.print(String(speed) + "%", 508, 125);
  myGLCD.print(millisToTimeStr(time), 230, 225);
  myGLCD.printNumI(level, 521, 225);
  myGLCD.print(millisToTimeStr(rest), 230, 325);
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

  myGLCD.setFont(GroteskBold24x48);
  myGLCD.printNumI(rounds, CENTER, 220, 2);  

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_BLACK, VGA_BLACK);
  int plus_btn = myButtons.addButton(500, 190, 100, 100, "+", BUTTON_NO_BORDER);
  int minus_btn = myButtons.addButton(200, 190, 100, 100, "-", BUTTON_NO_BORDER);
  myButtons.drawButtons();
  
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  int ok_btn = myButtons.addButton(300, 380, 200, 80, "OK");
  myButtons.drawButton(ok_btn);

  while (true) {     
    if (myTouch.dataAvailable()) {
    int pressed = myButtons.checkButtons();
      if (pressed == ok_btn) {
        drawHomeScreen();
        break;
      }
      else if (pressed == plus_btn && rounds < 15) {
        rounds += 1;         
        myGLCD.printNumI(rounds, CENTER, 220, 2);
      }

      else if (pressed == minus_btn && rounds > 1) {
        rounds -= 1;           
        myGLCD.printNumI(rounds, CENTER, 220, 2);
      }
    }
  }
}

void drawSpeedScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Adjust Speed", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myGLCD.setFont(GroteskBold24x48);
  myGLCD.printNumI(speed, CENTER, 220, 3);  
  myGLCD.print("%", 450, 220);

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_BLACK, VGA_BLACK);
  int plus_btn = myButtons.addButton(500, 190, 100, 100, "+", BUTTON_NO_BORDER);
  int minus_btn = myButtons.addButton(200, 190, 100, 100, "-", BUTTON_NO_BORDER);
  myButtons.drawButtons();
  
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  int ok_btn = myButtons.addButton(300, 380, 200, 80, "OK");
  myButtons.drawButton(ok_btn);

  while (true) {     
    if (myTouch.dataAvailable()) {
    int pressed = myButtons.checkButtons();
      if (pressed == ok_btn) {
        drawHomeScreen();
        break;
      }
      else if (pressed == plus_btn && speed < 100) {
        speed += 5;         
        myGLCD.printNumI(speed, CENTER, 220, 3);
      }

      else if (pressed == minus_btn && speed > 25) {
        speed -= 5;           
        myGLCD.printNumI(speed, CENTER, 220, 3);
      }
    }
  }
}

void drawTimeScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Time", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print(millisToTimeStr(time), CENTER, 220);  

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_BLACK, VGA_BLACK);
  int plus_btn = myButtons.addButton(500, 190, 100, 100, "+", BUTTON_NO_BORDER);
  int minus_btn = myButtons.addButton(200, 190, 100, 100, "-", BUTTON_NO_BORDER);
  myButtons.drawButtons();
  
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  int ok_btn = myButtons.addButton(300, 380, 200, 80, "OK");
  myButtons.drawButton(ok_btn);

  while (true) {     
    if (myTouch.dataAvailable()) {
    int pressed = myButtons.checkButtons();
      if (pressed == ok_btn) {
        drawHomeScreen();
        break;
      }
      else if (pressed == plus_btn && time < 600000) {
        time += 15000;         
        myGLCD.print(millisToTimeStr(time), CENTER, 220); 
      }

      else if (pressed == minus_btn && time > 30000) {
        time -= 15000;           
        myGLCD.print(millisToTimeStr(time), CENTER, 220); 
      }
    }
  }
}

void drawLevelScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Level", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myGLCD.setFont(SevenSegment96x144Num);
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, VGA_RED);
  int Lvl1_btn = myButtons.addButton(120, 190, 100, 100, "1");
  int Lvl2_btn = myButtons.addButton(350, 190, 100, 100, "2");
  int Lvl3_btn = myButtons.addButton(580, 190, 100, 100, "3");

  myButtons.drawButtons();

  while (true) {     

    if (myTouch.dataAvailable()) {
    int pressed = myButtons.checkButtons();
      if (pressed == Lvl1_btn) {
        level = 1;
        drawHomeScreen();
        break;
      }
      else if (pressed == Lvl2_btn) {
        level = 2;
        drawHomeScreen();
        break;
      }
      else if (pressed == Lvl3_btn) {
        level = 3;
        drawHomeScreen();
        break;
      }
    }
  }
}

void drawRestScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Rest", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print(millisToTimeStr(rest), CENTER, 220);  

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_BLACK, VGA_BLACK);
  int plus_btn = myButtons.addButton(500, 190, 100, 100, "+", BUTTON_NO_BORDER);
  int minus_btn = myButtons.addButton(200, 190, 100, 100, "-", BUTTON_NO_BORDER);
  myButtons.drawButtons();
  
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  int ok_btn = myButtons.addButton(300, 380, 200, 80, "OK");
  myButtons.drawButton(ok_btn);

  while (true) {     
    if (myTouch.dataAvailable()) {
    int pressed = myButtons.checkButtons();
      if (pressed == ok_btn) {
        drawHomeScreen();
        break;
      }
      else if (pressed == plus_btn && rest < 300000) {
        rest += 10000;         
        myGLCD.print(millisToTimeStr(rest), CENTER, 220); 
      }

      else if (pressed == minus_btn && rest > 10000) {
        rest -= 10000;           
        myGLCD.print(millisToTimeStr(rest), CENTER, 220); 
      }
    }
  }
}

void drawVolumeScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myGLCD.print("Choose Strike Volume", CENTER, 15);  //draws title
  myGLCD.drawLine(0, 80, 800, 80);

  myGLCD.setFont(GroteskBold24x48);
  myGLCD.printNumI(volume, CENTER, 220);  

  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_BLACK, VGA_BLACK);
  int plus_btn = myButtons.addButton(500, 190, 100, 100, "+", BUTTON_NO_BORDER);
  int minus_btn = myButtons.addButton(200, 190, 100, 100, "-", BUTTON_NO_BORDER);
  myButtons.drawButtons();
  
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, 0x04A7);
  int ok_btn = myButtons.addButton(300, 380, 200, 80, "OK");
  myButtons.drawButton(ok_btn);

  while (true) {     
    if (myTouch.dataAvailable()) {
    int pressed = myButtons.checkButtons();
      if (pressed == ok_btn) {
        drawHomeScreen();
        break;
      }
      else if (pressed == plus_btn && volume < 4) {
        volume += 1;         
        myGLCD.printNumI(volume, CENTER, 220);
      }

      else if (pressed == minus_btn && volume > 1) {
        volume -= 1;           
        myGLCD.printNumI(volume, CENTER, 220);
      }
    }
  }
}

void drawSparringScreen() {
  myGLCD.clrScr();
  myButtons.deleteAllButtons();
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SevenSegment96x144Num);

  unsigned long initialseconds = millis() / 1000;   
  unsigned long duration;   
  unsigned long added_time = 0;  
  int currentRound = 1;
  float progress = 0.0;
  String TimeString;

  unsigned long delaybetween; 
  unsigned long time1 = 0;
  unsigned long time2 = 0;         

  myGLCD.setFont(GroteskBold24x48);
  myButtons.setTextFont(GroteskBold24x48);
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, VGA_RED);
  int StopSpar_btn = myButtons.addButton(300, 380, 200, 80, "QUIT");

  
  for (int i = 0; i < (2 * rounds); i++) {
    if (i != 0) {
      myButtons.drawButtons();
      myGLCD.print("Round " + String(currentRound) + "/" + String(rounds), CENTER, 50);
      myGLCD.fillRoundRect(100, 315, 700, 300);
    }

    if (i % 2 == 1) {            
      duration = time;
      myGLCD.print("   FIGHT!   ", CENTER, 120);         
    }

    else if (i % 2 == 0 && i != 0){
      currentRound += 1;
      duration = rest;     
      myGLCD.print("Resting", CENTER, 120);               
    }

    while (true) { 
      switch (level) {
        case 1:
        delaybetween = volume * servoDuration(speed) + 2500;
        break;

        case 2:    
        delaybetween = volume * servoDuration(speed) + 1500;
        break;

        case 3:    
        delaybetween = volume * servoDuration(speed) + random(500, 4000);
        break;
      }

      if (millis() >= delaybetween + time1 + initialseconds * 1000) {
        time1 += delaybetween;  
        if (i % 2 == 1) {
          //myGLCD.print(String(delaybetween), 20, 20);
          SparringMode();           
        }                                           
      }     

      if (myTouch.dataAvailable()) {
      int pressed = myButtons.checkButtons();
        if (pressed == StopSpar_btn) {
          drawHomeScreen();
          break;
        }
      }             

      if (millis() >= 100 + time2 + initialseconds * 1000) {
        time2 += 100;
        if (i == 0) {
          countdowntime = 5 + initialseconds + added_time - (millis() / 1000);  
          TimeString = countdowntime % 60;    
          myGLCD.setFont(SevenSegment96x144Num);
          myGLCD.print(TimeString, CENTER, 150);
          myGLCD.setFont(GroteskBold24x48);
        }              
        
        else {
          countdowntime = (duration / 1000) + initialseconds + added_time - (millis() / 1000);
          progress = 1 - (countdowntime / float(duration / 1000));
          
          unsigned long countdown_minute = ((countdowntime / 60) % 60);
          unsigned long countdown_sec = countdowntime % 60;
                  
          if (countdown_sec < 10) {
            TimeString = String(countdown_minute) + ":" + "0" + String(countdown_sec);
          }

          else {
            TimeString = String(countdown_minute) + ":" + String(countdown_sec);
          }

          myGLCD.print(TimeString, CENTER, 200);      
          myGLCD.setColor(0, 26, 255);
          myGLCD.fillRoundRect(100, 315, 100 + progress * 600, 300);            
          myGLCD.setColor(255, 255, 255);
        }                  

        if (countdowntime == 0 || countdowntime > 4000000000) { 
          myGLCD.clrScr();      
          break;
        }
      }            
    }

    if ((countdowntime == 0 || countdowntime > 4000000000) && (i + 1) == (2 * rounds)) {
      delay(1000);
      drawHomeScreen();
      break;
    } 

    added_time = (millis() / 1000) - initialseconds;
  } 
}