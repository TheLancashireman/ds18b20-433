/* ds18b20-433.c - a remote temperature sensor
 *
 * (c) David Haworth
 *
 *  This file is part of ds18b20-433.
 *
 *  ds18b20-433 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ds18b20-433 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ds18b20-433.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 *                             |--v--|
 *                    PB5/Rst -|1   8|- Vcc
 *          (ds18b20 I/O) PB3 -|2   7|- PB2
 *           (serial out) PB4 -|3   6|- PB1
 *                        Gnd -|4   5|- PB0/PCINT0
 *                             |-----|
*/

#include "ds18b20-433.h"
#include "tinylib.h"
#include "tinyspi.h"
#include "rfm64w.h"
#include <avr/pgmspace.h>

#define DBG	1
#if DBG
#include "tinyio.h"			/* For early debugging; printf(), putc() etc. */
#endif

int main(void)
{
	u16_t temp = DS18B20_INVALID_TEMP;

	spi_masterinit();

#if DBG
	timing_init();
	async_init();
	delay_ms(500);				/* 0.5 s delay */
	printf(PSTR("Hello, world!\n"));
#endif

	delay_ms(500);				/* 0.5 s delay */
	for (;;)
	{
		r64_select(R64_SEL_CFG);
		for (u8_t a = 0; a < 32; a++ )
		{
			u8_t v = r64_readreg(a);
			printf(PSTR("Register %2d = 0x%04x\n"), a, v);
		}
		r64_select(R64_SEL_NONE);

		temp = ds18b20_read_temp();

#if DBG
		printf(PSTR("Temperature 0x%04x\n"), temp);
		delay_ms(5000);			/* 5 s delay */
#endif
	}

	return 0;
}
