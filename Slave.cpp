 //Slave
#include <Wire.h>   

int firstBuzz= 13;
int secondBuzz = 12;
int thirdBuzz = 11;
int fourthBuzz = 10;
int firstBUTT = 8;
int secondBUTT = 7;
int thirdBUTT = 6;
int fourthBUTT = 5;
bool calling1 = false;
bool calling2 = false;
bool calling3 = false;
bool calling4 = false;

void setup()
{
  	Wire.begin(4);
	pinMode(13,OUTPUT);
  	pinMode(12,OUTPUT);
  	pinMode(11,OUTPUT);
  	pinMode(10,OUTPUT);
 	pinMode(8, INPUT);
  	pinMode(7, INPUT);
  	pinMode(6, INPUT);
  	pinMode(5, INPUT);
  	pinMode(A0, OUTPUT);
  	pinMode(A1, OUTPUT);
  	pinMode(A2, OUTPUT);
  	pinMode(A3, OUTPUT); 
  	Wire.onReceive(receiveEvent);
  	 
}      
int x;
void receiveEvent(int howMany){
  	float S=Wire.read();  	
  	if(S == 1)
  	{
      	digitalWrite(A0, HIGH);
      	x=13;
      	calling1 = true;
  	}
  	else if(S == 2)
  	{
      	digitalWrite(A1, HIGH);
     	x=12;
      	calling2 = true;       	
  	}
  	else if(S == 3)
  	{
      	digitalWrite(A2, HIGH);
      	x=11;
      	calling3 = true;
  	}
  	else if(S == 4)
  	{
      	digitalWrite(A3, HIGH);
      	x=10;
      	calling4 = true;
  	}
}

void loop()
{   if(x!=0){
 	tone(x ,5000,100);
 	delay(200);
	}
    if((digitalRead(8)) == HIGH && calling1 == true)
    {
            tone(13,2000,500);
    		calling1 = false;
      		digitalWrite(A0, LOW); 
     		x=0;
    }
    if((digitalRead(7)) == HIGH && calling2 == true)
    {
            tone(12,2000,500);
    		calling2 = false;
      		digitalWrite(A1, LOW);
      		x=0;
    }
    if((digitalRead(6)) == HIGH && calling3 == true)
    {
            tone(11,2000,500);
    		calling3 = false;
      		digitalWrite(A2, LOW);
      		x=0;
    }
    if((digitalRead(5)) == HIGH && calling4 == true)
    {
            tone(10,2000,500);
    		calling4 = false;
      		digitalWrite(A3, LOW);
      		x=0;
    }
}
