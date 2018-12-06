#include <Wire.h>

void setup() 
{
  // join i2c bus with address #8
  Wire.begin(8);   
               
  // register event
  Wire.onRequest(requestEvent); 
}

void loop() 
{
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()

void requestEvent()
{  
  // respond with message of 6 bytes
  // as expected by master
  
  Wire.write("hello "); 
}
