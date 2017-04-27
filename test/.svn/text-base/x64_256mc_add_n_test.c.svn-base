#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/x64_256mc.h"

void x64_256mc_add_n_test()
{
	int i;
	unsigned long a[4], b[4], r[8];
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
		b[i] = (unsigned long)rand() * rand();
	}

	for(i=0; i<10000; i++)
	{
		sprintf(str, "a := 0x%016lx%016lx%016lx%016lx;\n", a[3], a[2], a[1], a[0]);
		fputs(str, file);
		fflush(file);

		sprintf(str, "b := 0x%016lx%016lx%016lx%016lx;\n", b[3], b[2], b[1], b[0]);
		fputs(str, file);
		fflush(file);

		x64_256mc_add_n(r, c, NULL, a, b);

		// sprintf(str, "r := 0x%016lx%016lx%016lx%016lx%016lx%016lx%016lx%016lx;\n", r[7], r[6], r[5], r[4], r[3], r[2], r[1], r[0]);
		sprintf(str, "r := 0x%016lx%016lx%016lx%016lx;\n", r[3], r[2], r[1], r[0]);
		fputs(str, file);
		fflush(file);

		// sprintf(str, "if (a*b) ne r then err := err + 1; end if;\n\n");
		sprintf(str, "if ( (a+b) mod P ) ne r then err := err + 1; print a:Hex; end if;\n\n");
		fputs(str, file);

		a[0] = a[0] + r[0] + r[7];
		a[1] = a[1] + r[1] + r[6];
		a[2] = a[2] + r[2] + r[5];
		a[3] = a[3] + r[3] + r[4];

		b[0] = a[3] + b[0] + r[4] + r[3];
		b[1] = a[2] + b[1] + r[5] + r[2];
		b[2] = a[1] + b[2] + r[6] + r[1];
		b[3] = a[0] + b[3] + r[7] + r[0];
	}
	sprintf(str, "err;");
	fputs(str, file);

	fclose(file);
}
