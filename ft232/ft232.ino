#include <NintendoSwitchControlLibrary.h>

const int byteMax = 4;
int byteIndex;
byte bytes [byteMax];
int leftX;
int leftY;
int rightX;
int rightY;

void setup() {
  
  /* Debug Log */
//  Serial.begin(9600);

  Serial1.begin(115200);
  byteIndex = 0;
  leftX = 128;
  leftY = 128;
  rightX = 128;
  rightY = 128;
  pushButton(Button::PLUS, 500, 5);
}

void setControllerStates(byte data[byteMax]) {

  /* Debug Log */
//  Serial.println(data[0]);
//  Serial.println(data[1]);

  if (data[0] == 0) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::B);
    else SwitchControlLibrary().releaseButton(Button::B);
  }
  else if (data[0] == 1) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::A);
    else SwitchControlLibrary().releaseButton(Button::A);
  }
  else if (data[0] == 2) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::Y);
    else SwitchControlLibrary().releaseButton(Button::Y);
  }
  else if (data[0] == 3) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::X);
    else SwitchControlLibrary().releaseButton(Button::X);
  }
  else if (data[0] == 4) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::L);
    else SwitchControlLibrary().releaseButton(Button::L);
  }
  else if (data[0] == 5) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::R);
    else SwitchControlLibrary().releaseButton(Button::R);
  }
  else if (data[0] == 6) {
    if(data[1] == 1)  SwitchControlLibrary().pressButton(Button::ZL);
    else SwitchControlLibrary().releaseButton(Button::ZL);
  }
  else if (data[0] == 7) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::ZR);
    else SwitchControlLibrary().releaseButton(Button::ZR);
  }
  else if (data[0] == 8) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::MINUS);
    else SwitchControlLibrary().releaseButton(Button::MINUS);
  }
  else if (data[0] == 9) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::PLUS);
    else SwitchControlLibrary().releaseButton(Button::PLUS);
  }
  else if (data[0] == 10) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::LCLICK);
    else SwitchControlLibrary().releaseButton(Button::LCLICK);
  }
  else if (data[0] == 11) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::RCLICK);
    else SwitchControlLibrary().releaseButton(Button::RCLICK);
  }
  else if (data[0] == 12) {
    if(data[1] == 1) SwitchControlLibrary().pressHatButton(Hat::UP);
    else SwitchControlLibrary().releaseHatButton(Hat::UP);
  }
  else if (data[0] == 13) {
    if(data[1] == 1) SwitchControlLibrary().pressHatButton(Hat::DOWN);
    else SwitchControlLibrary().releaseHatButton(Hat::DOWN);
  }
  else if (data[0] == 14) {
    if(data[1] == 1) SwitchControlLibrary().pressHatButton(Hat::LEFT);
    else SwitchControlLibrary().releaseHatButton(Hat::LEFT);
  }
  else if (data[0] == 15) {
    if(data[1] == 1) SwitchControlLibrary().pressHatButton(Hat::RIGHT);
    else SwitchControlLibrary().releaseHatButton(Hat::RIGHT);
  }
  else if (data[0] == 16) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::HOME);
    else SwitchControlLibrary().releaseButton(Button::HOME);
  }
  else if (data[0] == 17) {
    if(data[1] == 1) SwitchControlLibrary().pressButton(Button::CAPTURE);
    else SwitchControlLibrary().releaseButton(Button::CAPTURE);
  }
  else if (data[0] == 18) {
    leftX = data[1];
    SwitchControlLibrary().moveLeftStick(leftX, leftY);
  }
  else if (data[0] == 19) {
    leftY = data[1];
    SwitchControlLibrary().moveLeftStick(leftX, leftY);
  }
  else if (data[0] == 20) {
    rightX = data[1];
    SwitchControlLibrary().moveRightStick(rightX, rightY);
  }
  else if (data[0] == 21) {
    rightY = data[1];
    SwitchControlLibrary().moveRightStick(rightX, rightY);
  }
}


void loop() {
  /* When received signals */
  while (Serial1.available()) {
    int c = Serial1.read();
    
    /* Recieved "Start" signal */
    if ((char)c == 'S') byteIndex = 0;
    
    /* Recieved "End" signal */
    else if ((char)c == 'E') {
      setControllerStates(bytes);
    }
    
    /* Set a valid signal */
    else {
      bytes[byteIndex] = c;
      byteIndex++;
    }
  }
  /* Send Signal */
  SwitchControlLibrary().sendReport();
}
