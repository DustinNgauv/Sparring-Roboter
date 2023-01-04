void drawHomeScreen() {
  myGLCD.setBackColor(0, 0, 0);
  myButtons.setTextFont(BigFont);
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, 0xE800, VGA_WHITE, 0xE800);

  int Sparring_btn;
  int Practice_btn;

  Sparring_btn = myButtons.addButton(250, 150, 300, 50, "Sparring Mode");
  Practice_btn = myButtons.addButton(250, 250, 300, 50, "Practice Mode");

  myButtons.drawButtons();

  while (true) {
    if (myTouch.dataAvailable()) {
      int pressed = myButtons.checkButtons();

      if (pressed == Sparring_btn) {        

        myGLCD.clrScr();
        myButtons.deleteAllButtons();  
        drawSparringScreen();           
      }
    }
  }
}


void drawSparringScreen() {
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold24x48);
  myButtons.setTextFont(GroteskBold24x48);
  myButtons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_BLACK, VGA_WHITE, VGA_RED);
    
  myGLCD.print("Sparring Mode", CENTER, 15); //draws title
  myGLCD.drawLine(0, 80, 800, 80);
  

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
  myGLCD.setBackColor(235, 0, 0);
  myGLCD.print("Rounds", 253, 105);
  myGLCD.print("Speed", 506, 105);
  myGLCD.print("Time", 260, 205);
  myGLCD.print("Level", 509, 205);
  myGLCD.print("Rest", 262, 305);
  myGLCD.print("Strike Volume", 475, 305);

  myGLCD.setFont(BigFont);
  myGLCD.print("", 270, 125);

  while (true) {
    if (myTouch.dataAvailable()) {
      int pressed = myButtons.checkButtons();

      if (pressed == Rounds_btn) {                    
        myGLCD.clrScr();
        myButtons.deleteAllButtons();
        drawHomeScreen();
        
      }
    }
  }
}