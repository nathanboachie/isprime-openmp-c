#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main()
{	
	double start = omp_get_wtime();
	
	int MAX = 200000000;
	int total = 0;
	double sqrt_val = 0;
	int j = 0;
	#pragma omp parallel default(none) shared(MAX,sqrt_val,j,total)
	{
	#pragma omp for reduction(+:total) 
	for(int i=1; i<MAX ; ++i)
	{
		sqrt_val =(int) sqrt(i);
		j = 2;
		while(j < sqrt_val && (i%j)!= 0)
		{
			j+=1;
		}
		if(j < sqrt_val)
		{
			continue;
		}

		else
		{
			total+=1;
		}
	}
	}
	double elapsed_time = omp_get_wtime() - start;
	printf("Finding all prime numbers under %d took %.2f seconds and %d total primes found\n",MAX,elapsed_time,total); 
	return 0;
}
