#include <math.h>
#include <VarSpeedServo.h>
#include <UTFT.h>
#include <URTouch.h>
#include <UTFT_Buttons.h>

UTFT myGLCD(CTE50, 38, 39, 40, 41);  //display chip parameters
URTouch myTouch(6, 5, 4, 3, 2);      //touch calibration parameters
UTFT_Buttons myButtons(&myGLCD, &myTouch);

//declares the font used
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSeg_XXXL_Num[];
extern uint8_t SevenSegment96x144Num[];
extern uint8_t GroteskBold24x48[];


int rounds = 3;
int speed = 75;
unsigned long time = 180000;
int level = 3;
unsigned long rest = 30000;
int volume = 3;

void drawHomeScreen();
void drawRoundsScreen();
void drawSpeedScreen();
void drawTimeScreen();
void drawLevelScreen();
void drawRestScreen();
void drawVolumeScreen();
void drawSparringScreen();

void SparringMode();
void rightStraight();
void leftStraight();
void rightHook();
void leftHook();
void measurespeed(int s);
unsigned long servoDuration(int servoSpeed);

unsigned long countdowntime;

String millisToTimeStr(unsigned long milliseconds) {
  String minutes = String(milliseconds / 60000);
  String seconds = String((milliseconds / 1000) % 60);
  if (seconds.length() < 2) {
    seconds = "0" + seconds;
  }

  if (minutes.length() < 2) {
    minutes = " " + minutes;
  }
  return minutes + ":" + seconds;
}
  
VarSpeedServo servo1;
VarSpeedServo servo2;
VarSpeedServo servo3;
VarSpeedServo servo4;


void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

    //assigns the servo objects to a pin on the arduino
  servo1.attach(8); 
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);  
}

void loop() {
  drawHomeScreen();  
  //drawSparringScreen();     
}