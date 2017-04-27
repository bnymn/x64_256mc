#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/x64_256mc.h"

void x64_256mc_sqr_n_test()
{
	int i;
	unsigned long a[4],r[8];
	unsigned long c = 189;
	char str[100];
	FILE *file;

	file = fopen("debug.log", "w");

	sprintf(str, "c := %lu;\n", c);
	fputs(str, file);

	sprintf(str, "err := 0;\n");
	fputs(str, file);

	sprintf(str, "P := 2^256 - c;\n\n");
	fputs(str, file);

	srand(time(NULL));
	for(i=0; i<4; i++)
	{
		a[i] = (unsigned long)rand() * rand();
	}
	/*
	a[0] = 0xffffffffffffffffL;
	a[1] = 0xffffffffffffffffL;
	a[2] = 0xffffffffffffffffL;
	a[3] = 0xffffffffffffffffL;
	*/
	for(i=0; i<10000; i++)
	{
		sprintf(str, "a := 0x%016lx%016lx%016lx%016lx;\n", a[3], a[2], a[1], a[0]);
		fputs(str, file);
		fflush(file);

		x64_256mc_sqr_n(a, c, NULL, a);

		// sprintf(str, "r := 0x%016lx%016lx%016lx%016lx%016lx%016lx%016lx%016lx;\n", r[7], r[6], r[5], r[4], r[3], r[2], r[1], r[0]);
		sprintf(str, "r := 0x%016lx%016lx%016lx%016lx;\n", a[3], a[2], a[1], a[0]);
		fputs(str, file);
		fflush(file);

		// sprintf(str, "if (a*a) ne r then err := err + 1; end if;\n\n");
		sprintf(str, "if ( (a*a) mod (P) ) ne r then err := err + 1; end if;\n\n");
		fputs(str, file);

		a[0] = r[4] + a[0] + r[0];
		a[1] = r[5] + a[1] + r[1];
		a[2] = r[6] + a[2] + r[2];
		a[3] = r[7] + a[3] + r[3];
	}
	sprintf(str, "err;");
	fputs(str, file);

	fclose(file);
}
