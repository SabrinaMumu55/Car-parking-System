#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
#include <Servo.h> //includes the servo library
#include <Keypad.h>
#define len 10
/////for keypad//////////////////////////////////////////////////////////////////////////////////////
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','D'},
  {'4','5','6','M'},
  {'1','2','3','S'},
  {'C','0','=','A'}
};
byte rowPins[ROWS] = {22,23,24,25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26,27,28,29}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
char user[len];
char password[len]="160205108";
byte count;
char key;

//////////////////////////////////////////////////////////////////////////////////////////////////////////

 

 

void setup() {
   

   

  lcd.begin(16, 2);
  lcd.setCursor (0, 0);
  lcd.print("  wait ");
  
  delay (1000);
  lcd.clear();

  
}

void loop() {
  lcd.setCursor (0, 0);
  lcd.print("Enter password");
  key=customKeypad.getKey();
  if(key)
        {user[count]=key;
        lcd.setCursor(count,1);
        lcd.print(user[count]);
        count++;
      }
      
  if (count==len-1)
      {
          if (!strcmp(user,password)) {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("R8 Password"); 
          delay(1000);
          count=0;
          }
          
          else{
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("wrng Password"); 
            delay(1000);
            count=0;
        }
      }
}
     
