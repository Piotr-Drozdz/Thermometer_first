# Thermometer_first

This is an old student project from 2011. It is a thermometer based on the ATMega8 microcontroller and the Dallas 18B20 temperature sensor.
The device reads the temperature from the sensor and displays it on a 7-segment display.

The project will be updated and expanded in the near future, including photos and circuit diagrams.

## Project Structure

Thermometer_first/
├── src/        # Source files (.cc)
├── include/    # Header files (.h)
├── build/      # Binary files (.o, .hex)
├── Makefile
├── test        # Test file
└── .gitignore

## Source Files

- 7-seg.cc, 7seg.cc – 7-segment display handling
- dallas2.cc, dallas.cc – Dallas 18B20 sensor handling
- term_test.cc – Test file

## Compilation

The project uses a Makefile. To compile, run:

    make

The resulting .hex file will be saved in the build/ directory.

## Flashing to the Microcontroller

The .hex file can be uploaded to the ATMega8 using any AVR-compatible programmer.

## Notes

- Binary files, editor backups, and preprocessed files are ignored via .gitignore.
- Circuit diagrams and photos will be added later.

## License

Add your license information here if desired.
