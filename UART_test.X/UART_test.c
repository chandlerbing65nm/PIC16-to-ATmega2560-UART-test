#include <UART_test.h>

int8 handshake =  0;

void main(){
	delay_ms(2000);
	/*sending handshake to ATmega*/
	fputc(0x54,ATmega); 
	
	/*If the ack from ATmega is received, turn on LED B5*/
	while(TRUE){
		
		if(kbhit(ATmega)){
			handshake = fgetc(ATmega);
			if(handshake == 0x61){
				TRISB5 = 0; RB5 = 1;
			}
		}
	}
}