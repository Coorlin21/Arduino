const int button = 2;
const int ledR=9,ledB=10,ledG=11;

bool analogMode = HIGH,buttonPressed = LOW;
int mode = 0,colorMode = 0;
int analogColor = 255;
int color[7][3] = {{0,0,0},{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1}};
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);

  if(buttonState == LOW && buttonPressed == LOW)
  {
    buttonPressed = !buttonPressed;
    delay(500);
    buttonState = digitalRead(button);
    if(buttonState == LOW)
    {
      mode++;
    }
    else
    {
      colorMode++;
    }
  }
  if(buttonState == HIGH && buttonPressed == HIGH)
  {
    buttonPressed = !buttonPressed;
  }
  
  if(mode % 3 == 0)
  {
    digitalWrite(ledR,color[colorMode % 7][0]);
    digitalWrite(ledB,color[colorMode % 7][1]);
    digitalWrite(ledG,color[colorMode % 7][2]);
  }
  if(mode % 3 == 1)
  {
    digitalWrite(ledR,color[colorMode % 7][0]);
    digitalWrite(ledB,color[colorMode % 7][1]);
    digitalWrite(ledG,color[colorMode % 7][2]);
    delay(20);
    digitalWrite(ledR,HIGH);
    digitalWrite(ledB,HIGH);
    digitalWrite(ledG,HIGH);
    delay(20);
  }
  if(mode % 3 == 2)
  {
    switch(colorMode % 7)
    {
      case 0:
        analogWrite(ledR,analogColor);
        analogWrite(ledB,analogColor);
        analogWrite(ledG,analogColor);
        break;
      case 1:
        analogWrite(ledR,255);
        analogWrite(ledB,analogColor);
        analogWrite(ledG,analogColor);
        break;
      case 2:
        analogWrite(ledR,analogColor);
        analogWrite(ledB,255);
        analogWrite(ledG,analogColor);
        break;
      case 3:
        analogWrite(ledR,analogColor);
        analogWrite(ledB,analogColor);
        analogWrite(ledG,255);
        break;
      case 4:
        analogWrite(ledR,255);
        analogWrite(ledB,255);
        analogWrite(ledG,analogColor);
        break;
      case 5:
        analogWrite(ledR,analogColor);
        analogWrite(ledB,255);
        analogWrite(ledG,255);
        break;
      case 6:
        analogWrite(ledR,255);
        analogWrite(ledB,analogColor);
        analogWrite(ledG,255);
        break;
      }
    delay(5);
    if(analogMode)
    {
      analogColor--;
      if(analogColor == 0)
      {
        analogMode = !analogMode;
      }
    }
    else
    {
      analogColor++;
      if(analogColor == 255)
      {
        analogMode = !analogMode;
      }
    }
  }
}
