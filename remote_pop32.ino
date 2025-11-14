#include <Servo.h>
#include <POP32.h>
#include <PsxLib.h>
Psx Psx;
#define dataPin PA0
#define commandPin PA1
#define selectPin PA2
#define clockPin PA3
int FLeftSpeed,FRightSpeed;
int BLeftSpeed,BRightSpeed;
int speed = 50;
int speedservo = 10;
int time = 20;
unsigned int data = 0;  
void setup() {
  Psx.setupPins(dataPin, commandPin, selectPin, clockPin, 10);
  oled.textSize(5);
  oled.text(0, 0, " %d  ", speed);
  oled.display();
  Serial.begin(9600);
  while (!Serial);
}
void loop() {
  data = Psx.read();
  if (data & 512) {
    speed = speed + 10;
    speed = constrain(speed, 10, 100);
    oled.text(0, 0, " %d  ", speed);
    oled.display();
    beep();
    delay(250);
    Psx.read();
  }
  if (data & 256) {
    speed = speed - 10;
    speed = constrain(speed, 10, 100);
    oled.text(0, 0, " %d  ", speed);
    oled.display();
    beep();
    delay(250);
    Psx.read();
  }
  if (data == 16) {
    Forward(speed,time);
  }else if (data == 64) {
    Backward(speed,time);
  }else if (data == 32) {
    DapRight(speed,time);
  }else if (data == 128) {
    DapLeft(speed,time);
  }else if (data == 48) {
    Dap_on_Right(speed,time);
  }else if (data == 144) {
    Dap_on_Left(speed,time);
  }else if (data == 96) {
    Dap_down_Right(speed,time);
  }else if (data == 192) {
    Dap_down_Left(speed,time);
  }else if (data & 8192) {
    TureRight(speed,time);
  }else if (data & 32768) {
    TureLeft(speed,time);
  } else {
    AO();
  }
  data = Psx.read();  
  Serial.print("key=");
  Serial.print(data);
  Serial.print("\tAnLx=");
  Serial.print(Psx.AnLx);
  Serial.print("\tAnLy=");
  Serial.print(Psx.AnLy);
  Serial.print("\tAnRx=");
  Serial.print(Psx.AnRx);
  Serial.print("\tAnRy=");
  Serial.println(Psx.AnRy);
  delay(2);
}