#include "7seg.h"
#include <avr/io.h>
#include <util/delay.h>
using namespace std;

//A - port1
//B - port2
//c - port3
//D - port4
//E - port5
//F - port6
//G - port7

void wyswietl_cyfre(int liczba) {
DDRB = 0xff;
switch(liczba){
case 0:
  PORTB = 0b0111111;
break;
case 1: 
  PORTB = 6;
 break;
case 2:
  PORTB = 91;
  break;
case 3:
  PORTB = 0b1001111; 
 break;
case 4:
  PORTB = 102;
  break;
case 5:
 PORTB = 0x6d;
 break;
case 6:
  PORTB = 0x7d;
  break;
case 7:
  PORTB = 0x07;
  break;
case 8:
  PORTB = 0xff;
  break;
case 9:
  PORTB = 0x6f;
  break;
}

}
