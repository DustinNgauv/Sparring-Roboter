#include <math.h>

// library to control the servos
#include <VarSpeedServo.h>

// libraries for the touchdisplay
#include <UTFT.h>
#include <URTouch.h>
#include <UTFT_Buttons.h>

// create display object with the chip parameters
UTFT myGLCD(CTE50, 38, 39, 40, 41);

// create touch object with calibration parameters
URTouch myTouch(6, 5, 4, 3, 2);      

// create button object
UTFT_Buttons myButtons(&myGLCD, &myTouch);

// create servo objects
VarSpeedServo servo1;
VarSpeedServo servo2;
VarSpeedServo servo3;
VarSpeedServo servo4;

// declares the different fonts
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegment96x144Num[];
extern uint8_t GroteskBold24x48[];

// default settings for the Sparring Mode
int rounds = 3;
int speed = 75;
unsigned long time = 180000;
int level = 3;
unsigned long rest = 30000;
int volume = 2;

// holds the current value of the countdown clock
unsigned long countdowntime;

// function prototypes
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
unsigned long servoDuration(int servoSpeed);

// function converting milliseconds into a string in the time format m:ss
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
  
void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  // assigns the servo objects to a pin on the arduino board
  servo1.attach(8); 
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);    
}

void loop() {  
  drawHomeScreen();         
}