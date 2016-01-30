#include <SD.h>                      
#include <TMRpcm.h>
#include <SPI.h>

#define SD_ChipSelectPin 4  
TMRpcm tmrpcm;  

const int buttonPin = 7;  
int led = 13;               
int sensor = 2;              
int state = LOW;            
int val = 0;
int buttonState = 0; 

void setup(){
  delay(1000);
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  tmrpcm.speakerPin = 9;
  
  Serial.begin(115200);
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");  
    return;

  }
  else{   
    Serial.println("SD ok");   
  }
  }

int counter=0;

void loop(){  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)  
    counter++;
  val = digitalRead(sensor);   
  if (val == HIGH) {           
    if((counter%2)==0){
    digitalWrite(led, HIGH);   
    tmrpcm.play("hawk.wav");
    delay(2500);                
  }
  else if((counter%2)==1)
    /*{
    digitalWrite(led, HIGH);   
    tmrpcm.play("darkside.wav");
    delay(4050); 
    }
    else if((counter%3)==2)
    {*/
    digitalWrite(led, HIGH);   
    tmrpcm.play("dog_bark.wav");
    delay(6296); 
    }
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       
    }
  } 
  else {
      digitalWrite(led, LOW); 
      delay(200);             
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       
    }
  }
}
