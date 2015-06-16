TARGET =	hello
CC =		msp430-gcc
# not sure why this is a 2231 and not the 2253 that I'm using
MCU =		msp430g2231
CFLAGS =	-Os -Wall -Werror -mmcu=$(MCU)
SOURCES =	hello.c

# rf2500 for launchpad
PROG_DRIVER =	rf2500

all: $(TARGET).elf

$(TARGET).elf: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

prog: $(TARGET).elf
	mspdebug -q $(PROG_DRIVER) 'prog $(TARGET).elf'

clean:
	rm -f *.elf *.o tags
