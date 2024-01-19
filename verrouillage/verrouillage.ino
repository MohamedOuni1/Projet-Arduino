
// Code : 2022
#include<LiquidCrystal.h>

#include <Keypad.h>


LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

const byte ROWS = 4; 

const byte COLS = 4; 


char hexaKeys[ROWS][COLS] = {

{'7','8','9','/'},

{'4','5','6','*'},

{'1','2','3','-'},

{'C','0','=','+'}

};

byte rowPins[ROWS] = {3, 2, 19, 18}; 

byte colPins[COLS] = {17, 16, 15, 14}; 


Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

const int LED_RED=10; 

const int LED_GREEN=11; 

const int RELAY=12; 

char keycount=0;

char code[4]; 


void setup(){

pinMode(LED_RED,OUTPUT);

pinMode(LED_GREEN,OUTPUT);

pinMode(RELAY,OUTPUT);


lcd.begin(16, 2);


lcd.print("DONNER LE CODE  :");

lcd.setCursor(0,1);

// Turn on the cursor

lcd.cursor();

digitalWrite(LED_GREEN,HIGH);  

digitalWrite(LED_RED,LOW);     

digitalWrite(RELAY,LOW);      

}


void loop(){

char customKey = customKeypad.getKey();

if (customKey && (keycount<4) && (customKey !='=') && (customKey !='C')){

//lcd.print(customKey);

lcd.print('*');    

code[keycount]=customKey;

keycount++;

}

if(customKey == 'C')     

{

Lock();    

}

if(customKey == '=')  

{

if((code[0]=='2') && (code[1]=='0') && (code[2]=='2') && (code[3]=='2'))  //Mot de passe 

{

digitalWrite(LED_GREEN,LOW);  

digitalWrite(LED_RED,HIGH);    

digitalWrite(RELAY,HIGH);     

lcd.setCursor(0,1);

lcd.print("PORTE OUVERTE ");


delay(4000);    

Lock();

}

else

{

lcd.setCursor(0,1);

lcd.print("CODE ERONNEE");  

delay(3000); //Message delay

Lock();

}

}

}



void Lock()

{

lcd.setCursor(0,1);

lcd.print("PORTE FERMEE    ");

delay(1500);

lcd.setCursor(0,1);

lcd.print("                "); 

lcd.setCursor(0,1);

keycount=0;

digitalWrite(LED_GREEN,HIGH);  

digitalWrite(LED_RED,LOW);     

digitalWrite(RELAY,LOW);      

}
