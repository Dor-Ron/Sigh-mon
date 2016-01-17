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

/* MUSIC BUZZER TESTING CODE */
#define NOTE_D0 98
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556
#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278
#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112
 
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.625

int tune[] =
{
    NOTE_D0,NOTE_D1,NOTE_D2,NOTE_D3,NOTE_D4,NOTE_D5,NOTE_D6,NOTE_D7,
    NOTE_DL1,NOTE_DL2,NOTE_DL3,NOTE_DL4,NOTE_DL5,NOTE_DL6,NOTE_DL7,
    NOTE_DH1,NOTE_DH2,NOTE_DH3,NOTE_DH4,NOTE_DH5,NOTE_DH6,NOTE_DH7,
};

float duration[]=
{1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
int length;   
int tonePin=9;
/* MUSIC BUZZER TESTING CODE */

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

  // MUSIC TESTING STUFF
  Serial.begin(9600);
    pinMode(tonePin,OUTPUT);   //  initialize the digital pin as an output
    length = sizeof(tune)/sizeof(tune[0]);
  // MUSIC TESTING STUFF
  
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

  //MUSIC TESTING STUFF
  for(int x=1;x<length;x++)
    {tone(tonePin,tune[x]);
        delay(400*duration[(x%100)]);    // to distinguish the notes, set a minimum time between them.
 
        noTone(tonePin); // stop the tone playing:
    }
  //MUSIC TESTING STUFF

}
