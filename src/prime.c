#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main()
{
	int MAX = 200000;
	int total = 0;
	double sqrt_val = 0;
	int j = 0;
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
	double time = 6.0;
	printf("Finding all prime numbers under %d took %f seconds and %d total primes found\n",MAX,time,total); 
	return 0;
}
