const int button = 2;
const int ledR=9,ledB=10,ledG=11;

bool buttonPressed = LOW;
int mode = 0;
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
    delay(10);
    buttonState = digitalRead(button);
    if(buttonState == LOW)
    {
      mode++;
    }
  }
  if(buttonState == HIGH && buttonPressed == HIGH)
  {
    buttonPressed = !buttonPressed;
  }
  switch(mode % 4)
  {
    case 0:
      digitalWrite(ledR,LOW);
      digitalWrite(ledB,LOW);
      digitalWrite(ledG,LOW);
      break;
    case 1:
      digitalWrite(ledR,LOW);
      digitalWrite(ledB,LOW);
      digitalWrite(ledG,LOW);
      delay(100);
      digitalWrite(ledR,HIGH);
      digitalWrite(ledB,HIGH);
      digitalWrite(ledG,HIGH);
      delay(100);
      break;
    case 2:
      digitalWrite(ledR,LOW);
      digitalWrite(ledB,LOW);
      digitalWrite(ledG,LOW);
      delay(50);
      digitalWrite(ledR,HIGH);
      digitalWrite(ledB,HIGH);
      digitalWrite(ledG,HIGH);
      delay(50);
      break;
    case 3:
      digitalWrite(ledR,LOW);
      digitalWrite(ledB,LOW);
      digitalWrite(ledG,LOW);
      delay(20);
      digitalWrite(ledR,HIGH);
      digitalWrite(ledB,HIGH);
      digitalWrite(ledG,HIGH);
      delay(20);
      break;
  }
  
}
