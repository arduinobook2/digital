#include <SPI.h>

byte dataOut;
byte dataIn;

//Slave Select, active LOW
int pinSS = 10;  

void setup()
{
  //link to PC
  Serial.begin(115200);  
  
  pinMode(pinSS, OUTPUT);
  digitalWrite(pinSS, HIGH);
  SPI.begin();
}

void loop()
{
  while(Serial.available() > 0)
  {
    dataOut = Serial.read();
    dataIn = spiWriteAndRead(dataOut);
    
    Serial.write(dataIn);
  }
}

byte spiWriteAndRead(byte dout)
{
  byte din;
  
  digitalWrite(pinSS, LOW);
  delay(1);
  
  din = SPI.transfer(dout);
  
  digitalWrite(pinSS, HIGH);
  
  return din;
}




