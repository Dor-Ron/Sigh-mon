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

//Pushbutton switch demo: LED is connected to digital pin 8 and Pushbutton is connected to digital pin 12.
//The LED glows when the button is pressed.

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

//char order[100];
char bufffer[20];

int counter = 1;

void flashLights(int levels) {
  for (int i = 0; i < levels; i++) {
      digitalWrite(randomColors[i], HIGH);
      delay(1000);
      digitalWrite(randomColors[i], LOW);
      delay(1000);
  }
}

void playerGo(int rounds)
{
  for (int i = 0; i < rounds; i++) {
  //Test if green light's button is pushed
  greenInputState = digitalRead(greenButton); //Repeat code replacing "green" everywhere with other color pins.

  if (greenInputState == HIGH)
  {
    digitalWrite(greenLed, HIGH);  //Switch on LED
    tone(tonePin,1318);

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
    tone(tonePin,554);
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
    tone(tonePin,880);
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
  }
  else
  {
    digitalWrite(blueLed, LOW);   //Switch off LED
    noTone(tonePin);
  }
  }
  delay(1000);
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

}

void loop()
{
  for (int i = 0; i < 100; i++){
  randomColors[i] = colorArray[random(0,4)];
  }
  flashLights(counter);
  
  while(digitalRead(greenButton == LOW) && digitalRead(yellowButton == LOW) && digitalRead(redButton == LOW) && digitalRead(blueButton == LOW)){
      playerGo(counter);
      if(greenInputState == HIGH || yellowInputState == HIGH || redInputState == HIGH || blueInputState == HIGH) {
        break;
      }
    };
    
  for (int i = 0; i < 1; i++)
  {
    counter++;
    i++;
  };
  
  
  /*for (int i = 0; i < 2; i++){
  randomColors[i] = colorArray[random(0,4)];
  flashLights(3);
  delay(5000);
 }*/

  /*strcat(order, itoa(randomColor,bufffer,10));
  int randNumber = random(10, 20);
  Serial.println(colorArray[random(0,4)]);*/

}
