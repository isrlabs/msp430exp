TARGET =	bare
CPP =		msp430-g++
# not sure why this is a 2231 and not the 2253 that I'm using
MCU =		msp430g2231
CXXFLAGS =	-Os -Wall -Werror -mmcu=$(MCU) -nostdlib # -std=c++11
SOURCES =	bare.cc

# rf2500 for launchpad
PROG_DRIVER =	rf2500

all: $(TARGET).elf

$(TARGET).elf: $(SOURCES)
	$(CPP) $(CXXFLAGS) -o $@ $(SOURCES)

prog: $(TARGET).elf
	mspdebug -q $(PROG_DRIVER) 'prog $(TARGET).elf'

clean:
	rm -f *.elf *.o tags
