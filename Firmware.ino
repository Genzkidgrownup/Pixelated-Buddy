#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink; // bluetooth speaker object 

#define TFT_CS  15 
#define TFT_DC  2 
#define TFT_RST 4 
// tft colours lol
#define GRAY      0xFF7D
#define GREENISH  0x473A
#define BLUEISH   0x2986
#define BLACK     0x0000

//pins for i2s
#define BCLK 26
#define LRC 25
#define DIN 22
#define SD 21

#define Touch_front 13
#define Touch_right 14
#define Touch_left 12


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// Shapes properties
uint16_t eyeSize;
uint16_t eyeIris;
uint16_t topSection;

uint16_t shapesYPos;
uint16_t irisRandomPos;

void setup() {

  tft.begin();
  pinMode(Touch_front,INPUT);
  pinMode(Touch_right,INPUT);
  pinMode(Touch_left, INPUT);

  initData();
  tft.setRotation(1);

  tft.fillScreen(BLACK);
  
  auto cfg = a2dp_sink.default_config();
  cfg.pin_bck = BCLK; 
  cfg.pin_ws = LRC;  
  cfg.pin_data = DIN;
  
  a2dp_sink.start("Pixelated Buddy"); 

  

  delay(100);
}


void initData() {
  eyeSize = tft.width() / 6;
  eyeIris = eyeSize / 4;
  topSection = eyeSize * 2;

  shapesYPos = tft.height() / 3;
}

void loop() {
  if(digitalRead(Touch_front) == 0 && digitalRead(Touch_right) == 0 && digitalRead(Touch_left) == 0){
  tft.fillRect((tft.width() / 2) - eyeSize / 2, tft.height() - eyeSize, eyeSize, eyeSize / 4, GRAY);

  randomIrisPosGenerate();
  baseEyes();
  delay(2500);
  randomIrisPosGenerate();
  lookingAround();
  randomIrisPosGenerate();
  baseEyes();
  delay(2500);
  randomIrisPosGenerate();
  suspiciousEyes();
  }
  else if(digitalRead(Touch_front) == 1 && digitalRead(Touch_right) == 0 && digitalRead(Touch_left) == 0)
  {
     randomIrisPosGenerate();
  baseEyes();
  delay(2500);
  randomIrisPosGenerate();
  angryEyes();
  randomIrisPosGenerate();
  angryEyes();
  randomIrisPosGenerate();
  angryEyes();
  }
  else if(digitalRead(Touch_front) == 0 && digitalRead(Touch_right) == 1 && digitalRead(Touch_left) == 0)
  {
  
  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize, GRAY);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize, GRAY);

  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize - 2, BLACK);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize - 2, BLACK);
    while (true)
    {

      
      if(digitalRead(Touch_left) == 1)
      {
        
  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, 15, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, 15, BLACK);
        tft.fillScreen(BLACK);
        delay(1000);
        break;
      }
    }
  }
  

  
  
  
}

void randomIrisPosGenerate() {
  irisRandomPos = random(eyeIris, eyeSize * 2 - eyeIris);
}

void baseEyes() {
  
  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize, GRAY);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize, GRAY);
  tft.fillCircle(((tft.width() / 4) - eyeSize) + irisRandomPos, shapesYPos, eyeIris, BLUEISH);
  tft.fillCircle(((tft.width() - tft.width() / 4) - eyeSize) + irisRandomPos, shapesYPos, eyeIris, BLUEISH);
}

void lookingAround() {
  baseEyes();
  
  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);

  delay(5000/2);
}

void sleepyFace() {
  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize, GRAY);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize, GRAY);

  tft.fillCircle(tft.width() / 4, shapesYPos, eyeSize - 2, BLACK);
  tft.fillCircle(tft.width() - tft.width() / 4, shapesYPos, eyeSize - 2, BLACK);

  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, 15, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, 15, BLACK);

  
  tft.fillRect((tft.width() / 2) - eyeSize / 2, tft.height() - eyeSize, eyeSize, eyeSize / 4, GRAY);
  delay(2500);
  
}

void angryEyes() {
  baseEyes();

  tft.fillTriangle(tft.width() / 4 - eyeSize, tft.height() / 6, tft.width() / 2, 0, tft.width() / 2, shapesYPos, BLACK);
  tft.fillTriangle(tft.width() - tft.width() / 4 + eyeSize, tft.height() / 6, tft.width() / 2, 0, tft.width() / 2, shapesYPos, BLACK);

  delay(5000/2);
}

void sadEyes() {
  baseEyes();

  tft.fillTriangle(tft.width() / 4 - eyeSize, shapesYPos, tft.width() / 4 - eyeSize, 0, tft.width() / 2, 0, BLACK);
  tft.fillTriangle(tft.width() - tft.width() / 4 + eyeSize, shapesYPos, tft.width() - tft.width() / 4 + eyeSize, 0, tft.width() / 2, 0, BLACK);

  delay(5000/2);
}

void suspiciousEyes() {
  baseEyes();

  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos - eyeSize, topSection, eyeSize / 2, BLACK);

  tft.fillRect(tft.width() / 4 - eyeSize, shapesYPos + eyeSize / 2, topSection, eyeSize / 2 + eyeSize / 4, BLACK);
  tft.fillRect(tft.width() - tft.width() / 4 - eyeSize, shapesYPos + eyeSize / 2, topSection, eyeSize / 2 + eyeSize / 4, BLACK);

  delay(5000/2);
}
