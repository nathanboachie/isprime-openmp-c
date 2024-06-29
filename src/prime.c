#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main()
{
	double start = omp_get_wtime();
	int MAX = 200000000;
	int total = 2;
	int j = 0;
	#pragma omp parallel default(none) shared(MAX,total) private(j)
	{
	int local_total = 0;
	#pragma omp for schedule(guided,700)  
	for(int i=3; i<MAX ; i++)
	{
		int sqrt_i = (int)sqrt(i);
		j = 2;
		while(j < sqrt_i && (i%j)!= 0)
		{
			j+=1;
		}
		if(j < sqrt_i)
		{
			continue;
		}
		else
		{
			local_total++;
		}
	}
	#pragma omp atomic
	total += local_total;
	}
	printf("Finding all prime numbers under %d took %.2f seconds and %d total primes found\n",MAX,omp_get_wtime()-start,total); 
	return 0;
}
