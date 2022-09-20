#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
#include <Servo.h> //includes the servo library
#include <Keypad.h>
#define len 5
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
char password[len]="2021";
byte count;
char key;

//////////////////////////////////////////////////////////////////////////////////////////////////////////

Servo myservo1;

int ir_s1 = 2;
int ir_s2 = 4;
const int trigPin = 49; //trig pin connection 
const int echoPin = 50;  //echopin connection 
long duration;
int distance;
 
int Space;

 

void setup() {
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo1.attach(3);
  myservo1.write(100);

  lcd.begin(16, 2);
  lcd.setCursor (0, 0);
  lcd.print("  Car  Parking  ");
  lcd.setCursor (0, 1);
  lcd.print("     System     ");
  delay (500);
  lcd.clear();

  Space = 5;
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2; 

if (digitalRead (ir_s1) == LOW && digitalRead(ir_s2) == HIGH) {
  if (Space>0) {
    if(distance<500){
        lcd.setCursor(0,0);
        lcd.print("Distance:");
        lcd.print(distance);
        lcd.print(" Cm ");
        lcd.setCursor(0,1);                                                 
        lcd.print("go back");
        delay(200);
        lcd.clear();
    }
    else
    {
      lcd.setCursor (0, 0);
      lcd.print("Enter password");
      key=customKeypad.getKey();
      if(key)
       {  user[count]=key;
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
            delay(500);
            count=0;
            myservo1.write(0);
            Space = Space - 1;
            }
            
            else{
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("wrng Password"); 
              delay(500);
              count=0;
          }
        }
      
      }
    }
    
    
      
  
  else {
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print(" Sorry no Space ");
    lcd.setCursor (0, 1);
    lcd.print("    Available    ");
    delay (1000);
    }
  
}

            
if (digitalRead (ir_s2) == LOW && digitalRead (ir_s1) == HIGH) {
     
      
      if(Space<5){
      Space = Space + 1;
      
      lcd.setCursor (0, 0);
      lcd.print("Total Space: ");
      lcd.print("5");
    
      lcd.setCursor (0, 1);
      lcd.print("Have  Space: ");
      lcd.print(Space);
      delay(1000);
      lcd.clear();
       
      }
      }
    
  

if (digitalRead (ir_s2) == HIGH && digitalRead (ir_s1) == HIGH) {
   
      
     lcd.setCursor (0, 0);
     lcd.print("Total Space: ");
     lcd.print("5");

     lcd.setCursor (0, 1);
     lcd.print("Have  Space: ");
     lcd.print(Space);
     delay(500);
     lcd.clear();             
  }
 
    
                                                                    
  
  
  }

 
 
