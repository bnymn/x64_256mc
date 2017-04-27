#include "x64_256mc.h"

/**
 * Modular invertion of a 256-bit number
 *
 * Sliding window exponentiation is used in this implementation, where k is 4.
 *
 * @param r	Contains the result
 * @param c	The constant number in which 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	The number of which we find the inverse
 */
void x64_256mc_inv_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a)
{
	unsigned long g[16][4];
	unsigned long P = 0xFFFFFFFFFFFFFFFFUL -c -1;
	unsigned long mask = 0x8000000000000000UL;
	int i;

	// Precomputation
	g[0][0] = 1;
	g[0][1] = 0;
	g[0][2] = 0;
	g[0][3] = 0;

	g[1][0] = a[0];
	g[1][1] = a[1];
	g[1][2] = a[2];
	g[1][3] = a[3];

	x64_256mc_sqr_n(g[2], c, NOPARAM, a);

	for(i=1; i<8; i++)
	{
		x64_256mc_mul_n(g[2*i+1], c, NOPARAM, g[2*i-1], g[2]);
	}

	r[0] = g[15][0];
	r[1] = g[15][1];
	r[2] = g[15][2];
	r[3] = g[15][3];

	for(i=0; i<192; i=i+4)
	{
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_mul_n(r, c, NOPARAM, r, g[15]);
	}

	for(i=4; i<64;)
	{
		if((P & (mask >> i)) == 0)
		{
			x64_256mc_sqr_n(r, c, NOPARAM, r);
			i++;
			continue;
		}

		int j, t = 0, s = i + 3;

		for(;;)
		{
			if((P & (mask >> s)) != 0)
			{
				break;
			}
			else
			{
				s--;
			}
		}

		for(j=i; j<=s; j++)
		{
			unsigned long bit = P & (mask >> j);
			if(bit != 0)
			{
				bit = 1;
			}
			t = t*2 + bit;
			x64_256mc_sqr_n(r, c, NOPARAM, r);
		}
		x64_256mc_mul_n(r, c, NOPARAM, r, g[t]);
		i = s+1;
	}
}
