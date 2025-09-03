PROJECT=test
SOURCES=term_test.cc

F_CPU=8000000L

CC=avr-gcc
CXX=avr-g++
CFLAGS=-mmcu=atmega8 -Wall -O1 -DF_CPU=$(F_CPU) -gstabs
CXXFLAGS=$(CFLAGS)
LDFLAGS=-mmcu=atmega8 -O1 -DF_CPU=$(F_CPU)
OBJECTS=$(SOURCES:.cc=.o)
OBJCOPY=avr-objcopy
AVRPROG=avrdude -p m8 -c usbasp -e 

%.hex: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PROJECT)
	$(OBJCOPY) -O ihex $(PROJECT) $@

.PHONY: all
all: $(SOURCES) $(PROJECT).hex

.PHONY: upload
upload:	$(PROJECT).hex
	$(AVRPROG) -U flash:w:$(PROJECT).hex

.PHONY: clean
clean:
	rm -f *.hex *.o $(PROJECT)

.SECONDARY: $(OBJECTS)
