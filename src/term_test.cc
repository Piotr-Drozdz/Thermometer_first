#include "7seg.h"
#include "7-seg.cc"
#include "dallas2.cc"
#include "dallas.h"
#include <avr/io.h>
#include <util/delay.h>
using namespace std;

void pakazi(int m){

  DDRC |= (1 << PC1) | (1 << PC2) | (1 << PC3); 
  DDRB = 255;
 
  bool w =0;
  if(m <0){
    m= -m;
    w = 1;
  }
 
  for(int k = 0; k<10; k++){
     int jed, des;
      
      jed = m%10;
      des = m/10;

      //~ //gasimy wszystko
      PORTC |= ( 1 << PC3);
      DDRD &= ~(1 << PD7);
	PORTC &= ~( 1 << PC3);

      wyswietl_cyfre(jed);
      PORTC |= (1 << PC2) | (1 << PC3); // zapalamy jednosci
      _delay_ms(5);
      PORTC &= ~(1 << PC2); // gasimy jednosci
	

      PORTC = (1<<PC3);
      wyswietl_cyfre(des);
	PORTC |= (1 << PC1) | (1 << PC3);
      _delay_ms(5);
       PORTC &= ~(1<<PC1); //gasimy dziesiatki

if(w){
	DDRD |= (1 << PD7);
        PORTD &= ~(1 << PD7); 
	wyswietl_cyfre(8);
	_delay_ms(5);
   DDRD &= ~(1<<PD7);     
}
  }
DDRD |= ~(1<<PD7);
}

int main(){
 DDRC |= (1 << PC1) | (1 << PC2);
 DDRD = 0xff;
  
      while(1){
      pakazi(cels());
     // _delay_ms(500);
    }
  
}

 
