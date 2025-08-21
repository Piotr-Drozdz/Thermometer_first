#include <avr/io.h>
#include <stdlib.h>

#define WE 5
#define PORT_1wire PINC
#define SET_1wire { DDRC &=~_BV(WE); PORTC |= _BV(WE); }
#define CLEAR_1wire { PORTC &= ~_BV(WE); DDRC|=_BV(WE); }

//char buf[8];

