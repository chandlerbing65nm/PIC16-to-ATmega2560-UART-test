int handshake = 0;

void setup() {
  noInterrupts();
  CLKPR = 0x80;                                                                                     /*Enabling the clock prescaler function*/
  CLKPR = 0x00;                                                                                     /*Setting the prescaler to div by 1*/
  interrupts();
  
  pinMode(16, OUTPUT);

  Serial.begin(9600);                                                                               /*UART with PC Terminal*/
  Serial1.begin(9600);                                                                              /*UART with PIC MCU*/

  Serial.println("UART Communication test\n");
}

void loop() {

  digitalWrite(16, HIGH); 
  delay(500);                      
  digitalWrite(16, LOW);   
  delay(500);                       

  /*test code for serial communication with PIC MCU*/
  if (Serial1.available()){
    handshake = Serial1.read();
    Serial.println (handshake, HEX);
      if (handshake == 0x54){
        Serial.println("0x54 handshake Received from PIC MCU\n");
        delay(500);
        Serial1.write(0x61);
        Serial.println("Sending Ack 0x61 to PIC MCU\n");
      }
  }
}
