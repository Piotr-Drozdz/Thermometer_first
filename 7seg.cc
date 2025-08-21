#include "7seg.h"

#include <avr/io.h>
#include <util/delay.h>
/*Pod³¹czamy
PA0 - A
PA1 - B
PA2- C
PA3 - D
PA4 - E
Pa5 - F
Pa6 - G

segmenty pod³aczamy zgodnie z numeracj¹ na port c
*/
int liczba[4];
int aktulna_cyfra;


void inicjalizuj(){
  aktualna_cyfra = 0;
  for(i = 0; i < 4; i++){
  liczba[i] = 0;
  }


}







void wyswietl_cyfre(int liczba, int pozycja) {
DDRA = 0xff;                                                                                   
  switch(liczba) {
 
   case 0: 
       PORTA = ~0x3f;
       break;
   case 1:
       PORTA = ~0x06;
       break;
   case 2:
       PORTA = ~ (0x5b );
       break; 
  case 3:
       PORTA = ~ (0x4f );
       break;
  case 4:
       PORTA = ~ (0x66 );
       break;
  case 5:
       PORTA = ~ (0x6D);
       break;
  case 6:
  PORTA = ~(0x7D);
  break;
  case 7:
  PORTA = ~(0x07);
  break;
  case 8:
  PORTA = ~(0x7f);
  break;
  case 9:
  PORTA = ~(0x6f);
  break;
	
  }
  DDRC = 0xff;
  PORTC = ~(1 << pozycja);
  
}


void zmien_cyfre() {
while(true){
	for(i = 0; i< 4; i++){
	aktualna_cyfra = liczba[i];
	wyswietl_cyfre(aktualna_cyfra, i);
	_delay_us(300);
  
}