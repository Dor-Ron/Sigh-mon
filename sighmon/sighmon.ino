/*

Sigh-mon
========

AUTHORS: Alex Matson, Dor Rondel

An arduino remake of of Hasbro's Simon.
see: [Simon &copy;](http://www.hasbro.com/en-us/product/_:FA45E76C-5056-9047-F541-122FDDEF7288)
Uses <num> amount of different colored LEDs,
as well as buzzers, buttons, and a power-switch.
Made at Drexel University's IEEE DragonHacks 2016.

*/

//Pushbutton switch demo: LED is connected to digital pin 8 and Pushbutton is connected to digital pin 12. 
//The LED glows when the button is pressed.
 
char greenInputState;
int greenButton = 2;
int greenLed = 3;

char yellowInputState;
int yellowButton = 5;
int yellowLed = 6;

char redInputState;
int redButton = 8;
int redLed = 9;


char blueInputState;
int blueButton = 12;
int blueLed = 13;

void setup()   
{                
  pinMode(greenLed, OUTPUT);      
  pinMode(greenButton,INPUT);
  
  pinMode(yellowLed, OUTPUT);
  pinMode(yellowButton, INPUT);
  
  pinMode(redLed, OUTPUT);
  pinMode(redButton, INPUT);

  pinMode(blueLed, OUTPUT);
  pinMode(blueButton, INPUT);
  
}
 
 
void loop()                     
{
  //Test if green light's button is pushed
  greenInputState = digitalRead(greenButton); //Repeat code replacing "green" everywhere with other color pins.
  
  if (greenInputState == HIGH) 
  {     
    digitalWrite(greenLed, HIGH);  //Switch on LED
    
  } 
  else 
  {
    digitalWrite(greenLed, LOW);   //Switch off LED
   
  }

  //Test if yellow light's button is pushed
  yellowInputState = digitalRead(yellowButton); //Repeat code replacing "yellow" everywhere with other color pins.
 
  if (yellowInputState == HIGH) 
  {     
    digitalWrite(yellowLed, HIGH);  //Switch on LED
  } 
  else 
  {
    digitalWrite(yellowLed, LOW);   //Switch off LED
  }

  //Test if red light's button is pushed
  redInputState = digitalRead(redButton); //Repeat code replacing "red" everywhere with other color pins.
 
  if (redInputState == HIGH) 
  {     
    digitalWrite(redLed, HIGH);  //Switch on LED
  } 
  else 
  {
    digitalWrite(redLed, LOW);   //Switch off LED
  }

  //Test if blue light's button is pushed
  blueInputState = digitalRead(blueButton); //Repeat code replacing "blue" everywhere with other color pins.
 
  if (blueInputState == HIGH) 
  {     
    digitalWrite(blueLed, HIGH);  //Switch on LED
  } 
  else 
  {
    digitalWrite(blueLed, LOW);   //Switch off LED
  }

}
