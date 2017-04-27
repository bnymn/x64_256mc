#include <stdio.h>
#include <stdlib.h>
#include "../src/x64_256mc.h"

void x64_256mc_main_n_speed()
{
	int i;
	unsigned long a[4], b[4], r[8];
	unsigned long c = 189;

	for(i=0; i<4; i++)
	{
		a[i] = (unsigned long)rand() * rand();
		b[i] = (unsigned long)rand() * rand();
	}

	for(i=0; i<10000; i++)
	{
		x64_256mc_mul_n(r, c, NULL, a, b);

		a[0] = b[3] + a[0] + r[0];
		a[1] = b[2] + a[1] + r[1];
		a[2] = b[1] + a[2] + r[2];
		a[3] = b[0] + a[3] + r[3];

		b[0] = a[3] + b[0] + r[4];
		b[1] = a[2] + b[1] + r[5];
		b[2] = a[1] + b[2] + r[6];
		b[3] = a[0] + b[3] + r[7];
	}
}
