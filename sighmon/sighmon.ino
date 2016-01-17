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
 
char redInputState;
int redButton = 0;
int redLed = 1;

char blueInputState;
int blueLed = 4;
int blueButton = 5;

char greenInputState;
int greenLed = 8;
int greenButton = 9;

char yellowInputState;
int yellowLed = 12;
int yellowButton = 13;

void setup()   
{                
  pinMode(redLed, OUTPUT);        // Initialize Arduino Digital Pins 8 as output for connecting LED
  pinMode(redButton,INPUT);         // Initialize Arduino Digital Pins 12 as input for connecting Pushbutton
  
  pinMode(blueLed, OUTPUT);
  pinMode(blueButton, INPUT);
  
  pinMode(greenLed, OUTPUT);
  pinMode(greenButton, INPUT);

  pinMode(yellowLed, OUTPUT);
  pinMode(yellowButton, INPUT);
}
 
 
void loop()                     
{
  redInputState = digitalRead(redButton); //Repeat code replacing "red" everywhere with other color pins.
 
  if (redInputState == HIGH) 
  {     
    digitalWrite(redLed, HIGH);  //Switch on LED
  } 
  else 
  {
    digitalWrite(redLed, LOW);   //Switch off LED
  }
 
}
