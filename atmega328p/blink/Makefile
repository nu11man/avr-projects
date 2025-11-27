build: main.c
	@echo "Building sources"
	avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -O1 main.c -o main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

flash:
	@echo "Flashing microcontroller..."
	avrdude -c usbasp -P usb -p m328p -U flash:w:main.hex:i

read_fuses:
	avrdude -c usbasp -P usb -p m328p -U lfuse:r:-:h -U hfuse:r:-:h -U efuse:r:-:h

clean:
	@echo "Cleaning..."
	rm main.elf main.hex
