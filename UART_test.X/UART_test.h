#include <16F1789.h>                                                               //Libreria del dispositivo
#fuses NOWDT, NOBROWNOUT, NOPROTECT                                              //Fusibles: Sin WatchDog Timer, sin brownout, sin proteccion de memoria de programa
#include <PIC16F1789_registers.h>                                                                 //Selecciona conversion A/D de 8 bits
#use delay(crystal=16MHz,clock=16MHz) 

#use rs232(baud=9600,parity=N,xmit=PIN_D4,rcv=PIN_D5,bits=8,stream=ATmega,ERRORS)          //UART PIC16 to ATmega