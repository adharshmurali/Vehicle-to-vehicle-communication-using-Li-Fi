const int trigPin    = 2;
const int echoPin    = 3;
const int buttonPin  = 4;
const int analogInPin = A0; 

int sensorValue = 0;   
int buttonPushCounter = 0;
int buttonState = 0;         
int lastButtonState = 0;

    
void setup() 
{
  Serial.begin(1200);
  pinMode(buttonPin,INPUT);
}

void loop() 
{ 

  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)
    {
 
    if (buttonState == HIGH)
    {
     
      buttonPushCounter++;
//      Serial.println("on");
//      Serial.print("number of button pushes:  ");
//      Serial.println(buttonPushCounter);
    } 
//    else 
//    {   
//      Serial.println("off");
//    } 
    delay(50);
  }
  
  lastButtonState = buttonState;
  
      sensorValue = analogRead(analogInPin);
      long duration, inches, cm;
      pinMode(trigPin, OUTPUT);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      delay(100);      

      if(sensorValue > 400)
      {
        Serial.println('A'); 
      }

      else if(cm < 10)
      {
        Serial.println('C');
      }

      else if (buttonPushCounter > 10)
      {    
         Serial.println('B'); 
      }
    
      else if(buttonPushCounter > 25)
      {
        buttonPushCounter = 0;
      }      

//
//      else
//      {
//        Serial.println('D');
//      }
                  
}

long microsecondsToInches(long microseconds)
{
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}


