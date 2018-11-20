#include <Keypad.h>

int ledgreen = 3;
int ledred = 4;
int ledyellow = 2;
int i = 0;


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 10, 11, 12}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char inputArray[4]; //array to gather user keypad presses
char Main[4] = {'0','0','0','0'}; //array to hold keypad password


void setup(){
   Serial.begin(9600);
   pinMode(ledgreen, OUTPUT);
   pinMode(ledred, OUTPUT);
}

int checkCode()
{                                             
 {
   //match input array to password array

   if ((inputArray[0] == Main[0] &&
   inputArray[1] == Main[1] &&
   inputArray[2] == Main[2] &&
   inputArray[3] == Main[3])) 
   {
     open();
   }else{
     digitalWrite(ledred, HIGH); //turn on registerPin led
   delay(5000);
   digitalWrite(ledred, LOW); //turn on registerPin led
    }
 }
};

int open()
{
 digitalWrite(ledgreen, HIGH); //turn on registerPin led
 delay(5000);
  digitalWrite(ledgreen, LOW); //turn on registerPin led

 digitalWrite(ledyellow, LOW); //turn on registerPin led
 delay(5000);
  digitalWrite(ledgreen, HIGH); //turn on registerPin led
 
 return 0;
};
  
void loop(){
char key = keypad.getKey();
   digitalWrite(ledyellow, HIGH);
 //if a key is presseds
 if(key)
 {

   
   inputArray[i] = key; //store entry into array
   i++;
   Serial.println(key); //print keypad character entry to serial port

   if (key=='*')
   {
     Serial.println("Reset");
     i=0; //reset i
   }

   if (i == 4) //if 4 presses have been made
   {
     checkCode();
     {
      i=0;
     }
   } 
}
}
