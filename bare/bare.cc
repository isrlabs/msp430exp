namespace std {
#include <stdint.h>
}

// Isn't working; complains about libc++ not being found. The GCC
// is probably old and crusty.

namespace {
	const std::uint8_t	DDR = 0x22;
	const std::uint8_t	PORT1 = 0x21;
	const std::uint8_t	LED = (1 << 6);	// P1.6

	const std::uint16_t	WDTCTL  = 0x120;
	const std::uint16_t	WDTPW   = 0x5A00;
	const std::uint16_t	WDTHOLD = 0x80;
}


int
main(void)
{
	/*
	 * Disable the watchdog timer.
	 */
	*reinterpret_cast<volatile std::uint16_t *>(WDTCTL) = WDTPW | WDTHOLD;

	/*
	 * Turn on the LED.
	 */
	*reinterpret_cast<volatile std::uint8_t *>(DDR) |= LED;
	*reinterpret_cast<volatile std::uint8_t *>(PORT1) |= LED;

	/*
	 * For..ev..er...
	 */
	while (true) ;
}
