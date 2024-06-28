#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main()
{	
	double start = omp_get_wtime();
	
	int MAX = 200000000;
	int total = 1;
	int j = 0;
	int chunk_size = MAX/72;
	#pragma omp parallel default(none) shared(MAX,total) private(j)
	{
	#pragma omp for reduction(+:total) schedule(guided,2777778)  
	for(int i=2; i<MAX ; ++i)
	{
		j = 2;
		while(j < (int)sqrt(i) && (i%j)!= 0)
		{
			j+=1;
		}
		if(j < (int)sqrt(i))
		{
			continue;
		}

		else
		{
			total+=1;
		}
	}
	}
	printf("Finding all prime numbers under %d took %.2f seconds and %d total primes found\n",MAX,omp_get_wtime()-start,total); 
	return 0;
}
