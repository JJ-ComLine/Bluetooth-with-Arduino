#include <SoftwareSerial.h>
 
int rxPin = 3;
int txPin = 2;
SoftwareSerial bluetooth(rxPin, txPin);
 
String message; //string that stores the incoming message
int Led = 13;
 
void setup()
{
  Serial.begin(9600); //set baud rate
  bluetooth.begin(9600); //set baud rate
  pinMode(Led,OUTPUT);
}
 
void loop()
{
  while(bluetooth.available()){
    message+=char(bluetooth.read());
  }
  if(!bluetooth.available())
  {
    if(message!="")
    {//if data is available
      if(message == "H"){
          digitalWrite(Led, HIGH);
          Serial.println("Led ON"); //show the data
          delay(20);
          message=""; //clear the data
       }
       else if(message == "L"){
          digitalWrite(Led, LOW);
          Serial.println("Led OFF"); //show the data
          delay(20);
          message=""; //clear the data
       }
    }
  }
}
