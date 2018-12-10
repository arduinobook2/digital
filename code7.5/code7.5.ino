//echo back input data in next round
byte dataEcho; 

//send input data to PC
byte dataToPC;  

void setup()
{
    //link to PC
    Serial.begin(115200);  
    
    //The Port B Data Direction Register
    DDRB  |= 0b00010000; 
    
   //The Port B 
    PORTB |= 0b00000100;
    
    //SPI Control Register
    SPCR  |= 0b11000000;
    
    //SPI status register
    SPSR  |= 0b00000000;
    
    dataEcho = 0;
    dataToPC = 0;
    
    sei();
}

void loop() {
  
  if(dataToPC != 0)
  {
    Serial.write(dataToPC);
    
    dataToPC = 0;
  }
}

ISR(SPI_STC_vect)
{
  cli();
  
  //while SS Low
  while(!(PINB & 0b00000100))
  {
    SPDR = dataEcho;
    
    //wait SPI transfer complete
    while(!(SPSR & (1 << SPIF)));

    //send back in next round
    dataEcho = SPDR;  
  }
  
  sei();
}
