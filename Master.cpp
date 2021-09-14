//Master
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal.h>
#include <Servo.h> 
Servo ServoMotor;
LiquidCrystal LCD(13, 12, 11, 10, 9, 8); 

char customKey;
const byte ROWS = 4;
const byte COLS = 4;
int x=0;
int y=0;
int position = 0;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7,6,5,4}; 
byte colPins[COLS] = {3,2,1,0}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);
	
  
  void setup()
{
  	Serial.begin(9600);
    LCD.begin(16,2);
  	LCD.print("Dzien dobry!");
  	Wire.begin();
    pinMode(A0, INPUT);
    pinMode(A1, OUTPUT);
    ServoMotor.attach(A3);
  	ServoMotor.write(0);
}
  
void loop()
{
  
  if((digitalRead(A0)) == HIGH){
    digitalWrite(A1, HIGH);
	LCD.clear();
    LCD.print("Otwarte");
    ServoMotor.write(90);
    delay(2000);
    digitalWrite(A1, LOW);
    ServoMotor.write(0);
    LCD.clear();
    LCD.print("Dzien dobry!");
  }
  char Key = keypad.getKey();
  switch(Key) 
  {
  case '1' ... '4': 
    if(x==0){
    x = (Key - '0');
    LCD.clear();
    LCD.print(x);
    }
    break;
  case '5' ... '9': 
    LCD.clear();
    LCD.print("Dzien dobry!");
    x=0;
    break;
  case '*':
    if(x!=0){
    LCD.print(" Calling");
    Wire.beginTransmission(4);
  	Wire.write(x);}
    Wire.endTransmission();
    x=0;
    break;
  case '#': 
    LCD.clear();
    LCD.print("Dzien dobry!");
    x=0;
    break;
  
  }
}


