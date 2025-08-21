#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "dallas.h"
//program w formie takiej jaka była sprawdzana przez mikrokontroler
using namespace std;

//resetowanie magistrali
unsigned char RESET_PULSE(void){
  unsigned char PRESENCE;
  CLEAR_1wire; //magistrala na poziom niski
  _delay_us(500);
  SET_1wire;//magistrala na poziom wysoki
PORTD |= (1<<PD6)|(1<<PD5)|(1<<PD4);
  _delay_us(32);//czekanie az czujnik ustawi linie na poziom niski
PORTD &= ~(1<<PD6) & ~(1<<PD5) & ~(1<<PD4);
	 
  
  //spr. poziomu linii
  if(bit_is_clear(PORT_1wire, WE))
    PRESENCE = 1;
  else
    PRESENCE = 0;//1-odebrano bit PRESENCE; 0-stan nieaktywności
  
  _delay_us(480);
  
  //spr. poziomu linii
   //spr. poziomu linii
  if(bit_is_clear(PORT_1wire, WE))
    PRESENCE = 0;
  
  return PRESENCE;
}

//wysyłanie pojedynczego bitu
void send(char bit) {
  SET_1wire;
  _delay_us(5);
  CLEAR_1wire;

  if(bit == 1)
    _delay_us(10);
  else
    _delay_us(60);
  
  SET_1wire;
  
  _delay_us(80);
}

//odczytanie pojedynczego bitu
unsigned char read(void){
  unsigned char PRESENCE = 0;
  
  CLEAR_1wire;
  _delay_us(15);
  SET_1wire;
  _delay_us(20);
	
  
  if(bit_is_set(PORT_1wire,WE))
    PRESENCE = 1;
  
  _delay_us(50);

  return(PRESENCE);
}
  
  void send_byte(char wartosc){
    unsigned char i;
    unsigned char pom;
    for(i = 0; i< 8; i++){
      pom = wartosc >> i;
      pom &= 0x01;
      send(pom);
    }
    _delay_us(100);//w tym miejscu powinno byc 60
  }
  
  unsigned char read_byte(void){
     unsigned char i;
    unsigned char wartosc;
    
    for(i = 0; i<8; i++){
      if(read()) wartosc |= 0x01 <<i;
     _delay_us(15);
    }
    return(wartosc);
  }
  
  
  int cels(void){
  int sprawdz, temp1, temp2;
   	DDRD |=(1<<PD6)|(1<<PD5)|(1<<PD4);
  PORTD &= ~(1<<PD6) & ~(1<<PD5) & ~(1<<PD4);

   sprawdz = RESET_PULSE();
   if(sprawdz==1){
PORTD |= (1<<PD6)  | (1<<PD5) | (1<<PD4);
     send_byte(0xCC);
     send_byte(0x44);
PORTD &= ~(1<<PD6) & ~(1<<PD5) & ~(1<<PD4);

     _delay_ms(750);
     
     sprawdz = RESET_PULSE();
PORTD |= (1<<PD6)  | (1<<PD5) | (1<<PD4);
     send_byte(0xCC);
     send_byte(~0xBC);//w tym momencie powinien być 0xBE
PORTD &= ~(1<<PD6) & ~(1<<PD5) & ~(1<<PD4);   
     temp1 = read_byte();
     temp2 = read_byte();
     
     int temp = 0;
     temp=(int)(temp1 + (temp2*256))/16;
     
     return temp;
   }
   
  
  }
   
