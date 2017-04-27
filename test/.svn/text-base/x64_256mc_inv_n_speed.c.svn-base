#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../src/x64_256mc.h"
#include "../cpucycles.h"

#define TRIAL 10000000

float get_msec(struct timeval t, int trial, int accuracy)
{
	return (float)((float)(t.tv_sec * 1000 + t.tv_usec / 1000)) / (trial * accuracy);
}

void x64_256mc_inv_n_speed()
{
	// CPU Cycles
	long long st, fn;
	struct timeval t_start, t_end, t_diff;

	int i;
	unsigned long a[4], r[8];
	unsigned long c = 189;

	for(i=0; i<4; i++)
	{
		a[i] = (unsigned long)rand() * rand();
	}

	gettimeofday(&t_start, NULL);
	st = cpucycles();
	for(i=0; i<TRIAL; i++)
	{
		x64_256mc_inv_n(r, c, NULL, a);

		a[0] = a[3] + r[0];
		a[1] = a[2] + r[1];
		a[2] = a[1] + r[2];
		a[3] = a[0] + r[3];
	}
	fn = cpucycles();
	gettimeofday(&t_end, NULL);
	timersub(&t_end, &t_start, &t_diff);
	printf("Cycles: %lld\n", (fn - st)/TRIAL);
	printf("Time: %.3f msec\n", get_msec(t_diff, TRIAL, 1));
	fflush(stdout);
}
