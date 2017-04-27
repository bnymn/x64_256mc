#include "x64_256mc.h"

/**
 * Modular invertion of a 256-bit number
 *
 * Left to right binary exponentiation is used in this implementation.
 *
 * @param r	Contains the result
 * @param c	The constant number in which 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	The number of which we find the inverse
 */
void x64_256mc_inv_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a)
{
	unsigned long P = 0xFFFFFFFFFFFFFFFFUL -c -1;
	r[0] = a[0];
	r[1] = a[1];
	r[2] = a[2];
	r[3] = a[3];
	unsigned long mask = 0x8000000000000000UL;
	int i;
	//mul_n(r, c, NOPARAM, r, a);
	for(i=1; i<192; i++)
	{
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_mul_n(r, c, NOPARAM, r, a);
	}
	for(i=0; i<64; i++)
	{
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		if( (P & (mask >> i)) != 0)
		{
			x64_256mc_mul_n(r, c, NOPARAM, r, a);
		}
	}
}
