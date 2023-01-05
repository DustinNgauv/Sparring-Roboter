#include <Servo.h>
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


int Rounds_btn;
int Speed_btn;
int Time_btn;
int Level_btn;
int Rest_btn;
int Volume_btn;
int Start_btn;
int StopSpar_btn;

int rounds = 2;
int speed = 75;
long time = 8000;
int level = 1;
long rest = 30000;
int volume = 2;

void drawHomeScreen();
void drawRoundsScreen();
void drawSpeedScreen();
void drawTimeScreen();
void drawLevelScreen();
void drawRestScreen();
void drawVolumeScreen();
void drawSparringScreen();

String millisToTimeStr(int milliseconds);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
}

void loop() {
  drawHomeScreen();
  //drawRoundsScreen();
  //drawSparringScreen();
}