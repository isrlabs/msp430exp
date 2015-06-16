#include <msp430g2553.h>

/*
 * This is a circuit to turn on the onboard LED1.
 */

#define LED	BIT0
#define LED_OUT	P1OUT
#define LED_DIR	P1DIR


int
main(void)
{
	/* Disable watchdog. */
	WDTCTL = WDTPW + WDTHOLD;

	/* Set LED as output. */
	LED_DIR |= LED;

	/*
	 * The MSP430g2253 on the Launchpad is clocked at 16MHz, so
	 * delay for 1 secondish and blink the LED.
	 */
	while (1) {
		LED_OUT ^= LED;
		__delay_cycles(1600000);
	}

	return 0;
}
