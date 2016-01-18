/*

Sigh-mon
========

AUTHORS: Alex Matson, Dor Rondel

An arduino remake of of Hasbro's Simon.
see: [Simon &copy](http://www.hasbro.com/en-us/product/_:FA45E76C-5056-9047-F541-122FDDEF7288)
Uses <num> amount of different colored LEDs,
as well as buzzers, buttons, and a power-switch.
Made at Drexel University's IEEE DragonHacks 2016.

*/

char greenInputState;
int greenButton = 21;
int greenLed = 20;

char yellowInputState;
int yellowButton = 18;
int yellowLed = 17;

char redInputState;
int redButton = 15;
int redLed = 14;


char blueInputState;
int blueButton = 6;
int blueLed = 7;

int tonePin=9;

int colorArray[4] = {greenLed, yellowLed, redLed, blueLed};
int randomColors[100];
int userGuesses[100];

int counter = 0;
int clickCount = 0;

bool checkStates() {
    if(digitalRead(greenButton == LOW) && digitalRead(yellowButton == LOW) && digitalRead(redButton == LOW) && digitalRead(blueButton == LOW)) {
      return true;
    } else {
      return false;
    }
  }

bool currentState = checkStates();

void flashLights(int levels) {
  for (int i = 0; i <= levels; i++) {
      digitalWrite(randomColors[i], HIGH);
      delay(1000);
      digitalWrite(randomColors[i], LOW);
      delay(1000);
  }
}

void playerGo()
{
      //Test if green light's button is pushed
      greenInputState = digitalRead(greenButton); //Repeat code replacing "green" everywhere with other color pins.

      if (greenInputState == HIGH)
      {
        digitalWrite(greenLed, HIGH);  //Switch on LED
        tone(tonePin, 1318);
        clickCount++;
      }
      else
      {
        digitalWrite(greenLed, LOW);   //Switch off LED
        noTone(tonePin);
      }
     
      //Test if yellow light's button is pushed
      yellowInputState = digitalRead(yellowButton); //Repeat code replacing "yellow" everywhere with other color pins.

      if (yellowInputState == HIGH)
      {
        digitalWrite(yellowLed, HIGH);  //Switch on LED
        tone(tonePin, 554);
        clickCount++;
      }
      else
      {
        digitalWrite(yellowLed, LOW);   //Switch off LED
        noTone(tonePin);
      }

      //Test if red light's button is pushed
      redInputState = digitalRead(redButton); //Repeat code replacing "red" everywhere with other color pins.

      if (redInputState == HIGH)
      {
        digitalWrite(redLed, HIGH);  //Switch on LED
        tone(tonePin, 880);
        clickCount++;
      }
      else
      {
        digitalWrite(redLed, LOW);   //Switch off LED
        noTone(tonePin);
      }

      //Test if blue light's button is pushed
      blueInputState = digitalRead(blueButton); //Repeat code replacing "blue" everywhere with other color pins.

      if (blueInputState == HIGH)
      {
        digitalWrite(blueLed, HIGH);  //Switch on LED
        tone(tonePin,659);
        clickCount++;
      }
      else
      {
        digitalWrite(blueLed, LOW);   //Switch off LED
        noTone(tonePin);
      }
}

void setup()
{
  Serial.begin(9600);

  pinMode(greenLed, OUTPUT);
  pinMode(greenButton,INPUT);

  pinMode(yellowLed, OUTPUT);
  pinMode(yellowButton, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(redButton, INPUT);

  pinMode(blueLed, OUTPUT);
  pinMode(blueButton, INPUT);

  pinMode(tonePin,OUTPUT);

  for (int i = 0; i < 100; i++){
      randomColors[i] = colorArray[random(0,4)];
  }

}


void loop()
{
  clickCount = 0;
  flashLights(counter);
  counter++;
  while(true){
    playerGo();
    if(clickCount == 0) {
      continue;
    }
    else if(clickCount == counter + 1) {
      delay(1000);
      break;
    }
    else {
      continue;
    }
  }
    /*if(digitalRead(greenButton) == HIGH || digitalRead(yellowButton) == HIGH || digitalRead(redButton) == HIGH || digitalRead(blueButton) == HIGH){
      break;
    }*/
  
}
