#include "x64_256mc.h"

/**
 * This function calculates modular inverse of a given 256-bit number. Left to right k-ary
 * exponentiation is used in this implementation, where k is 4.
 *
 * <h3>Mask variable</h3>
 * The road that the <strong>mask</strong> variable follows is show in the following diagram. The first line
 * shows the binary value of 2<sup>256</sup> - c, where c is 189. Remaining rows shows the
 * content of the <strong>mask</strong> variable according to the value of <strong>i</strong> variable.
 * <pre>
 * [i ] 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 0100 0001
 * [0 ] 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
 * [4 ] 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
 * [8 ] 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
 * [12] 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
 * [26] 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
 * [20] 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000
 * [24] 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000
 * [28] 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000
 * [32] 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000
 * [36] 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000 0000
 * [42] 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000 0000
 * [44] 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000 0000
 * [48] 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000 0000
 * [52] 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 0000
 * [56] 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111
 * </pre>
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
	unsigned long mask = 0x0F00000000000000UL;
	int i;

	// Precomputation
	// g[0]
	g[0][0] = 1;
	g[0][1] = 0;
	g[0][2] = 0;
	g[0][3] = 0;

	// g[1]
	g[1][0] = a[0];
	g[1][1] = a[1];
	g[1][2] = a[2];
	g[1][3] = a[3];

	// g[2]
	x64_256mc_sqr_n(g[2], c, NOPARAM, a);

	// g[n]
	for(i=3; i<16; i++)
	{
		x64_256mc_mul_n(g[i], c, NOPARAM, g[i-1], g[1]);
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

	for(i=0; i<=56; i=i+4)
	{
		int t = ((P & (mask >> i)) >> (56-i));
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_sqr_n(r, c, NOPARAM, r);
		x64_256mc_mul_n(r, c, NOPARAM, r, g[t]);
	}
}
