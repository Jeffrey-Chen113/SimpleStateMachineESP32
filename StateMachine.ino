//State Machine
//By: Jeffrey Chen

const int pushButton = A0;

// Corresponds to the pins on RGB LED
const int redLED = 12;  //(pin 1)
const int greenLED = 27;  //(pin 3)
const int blueLED = 33;  //(pin 4)

//Settings for RGB LED
const int freq = 5000;
const int resolution = 8;
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup(){
  pinMode(pushButton, INPUT);

  //Setup Settings
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);

  ledcAttachPin(redLED, redChannel);
  ledcAttachPin(greenLED, greenChannel);
  ledcAttachPin(blueLED, blueChannel);

  //Serial.begin(9600);
}

void loop() {
  buttonState=digitalRead(pushButton);

  if (buttonState != lastButtonState){
    if (buttonState==HIGH){
      buttonPushCounter++;
    }
    delay(50);
  }
  lastButtonState=buttonState;

  if (buttonPushCounter==1){
    ledcWrite(redChannel, 255);
    ledcWrite(greenChannel, 0);
    ledcWrite(blueChannel, 0);
  }
  else if (buttonPushCounter==2){
    ledcWrite(redChannel, 0);
    ledcWrite(greenChannel, 255);
    ledcWrite(blueChannel, 0);
  }
  else if (buttonPushCounter==3){
    ledcWrite(redChannel, 0);
    ledcWrite(greenChannel, 0);
    ledcWrite(blueChannel, 255);
  }
  else if (buttonPushCounter==4){
    ledcWrite(redChannel, 0);
    ledcWrite(greenChannel, 0);
    ledcWrite(blueChannel, 0);
    buttonPushCounter=0;
  }
}
