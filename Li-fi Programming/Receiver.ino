#include <LiquidCrystal.h>
String inputString = "";  
boolean stringComplete = false;

int sensorValue = 0;    
const int LED = 13; 

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
      
void setup() 
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  lcd.begin(16, 2);
  lcd.print("VtoV communication");
  Serial.begin(1200);
  inputString.reserve(200);
  for (int thisPin = 2; thisPin < 6; thisPin++) 
  {
    pinMode(thisPin, OUTPUT);
  }
}

int Flag=0,sequence=0,robot_start=0;

void loop() 
{ 
      if(sequence == 1)
      {
          sequence = 0;  
          digitalWrite(LED,HIGH); 
          lcd.setCursor(0, 1);
          lcd.print("Gas LeakageDetected");  
          delay(1000);
          digitalWrite(LED,LOW);        
      }
    
      if(sequence == 2)
      {
          sequence = 0;  
          digitalWrite(LED,HIGH);         
          lcd.setCursor(0, 1);
          lcd.print("DrowsinessDetected");          
          delay(1000);
          digitalWrite(LED,LOW);        
      }

     if(sequence == 3)
      {
          sequence = 0;  
          digitalWrite(LED,HIGH);         
          lcd.setCursor(0, 1);
          lcd.print("Obstacle Detected");          
          delay(1000);
          digitalWrite(LED,LOW);        
      }

      if(sequence == 4)
      {
          sequence = 0;  
          digitalWrite(LED,HIGH);         
          lcd.setCursor(0, 1);
          lcd.print("                ");          
          delay(1000);
          digitalWrite(LED,LOW);                  
      }     
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar == 'A') {
      sequence = 1;
    }
    if (inChar == 'B') {
      //stringComplete = true;
      sequence = 2;
    }
    if (inChar == 'C') {
      //stringComplete = true;
      sequence = 3;
    }    
    if (inChar == 'D') {
      //stringComplete = true;
      sequence = 4;
    }  
  }
}



