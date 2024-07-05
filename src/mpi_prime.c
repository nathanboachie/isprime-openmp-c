#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <omp.h>
#include <time.h>

int prime_calc(int n,int rank,int size);

int main(int argc, char *argv[])
{
	//Initalise MPI Program
	MPI_Init(&argc, &argv);

	//Define rank and size for MPI
	int rank;
	int size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	//Define Timing and prime variables
	int primes_loc = 0;
	clock_t t;
	double time;
	int primes;
	int isprime;

	//Loop variables
	int sqrt_idx;
	int j;
	int MAX = 20000000;
	int MIN = 2;
	int total_iter;
	int base_iter;
	int rem;
	int start_idx;
	int end_idx;
	float t_start;
	//Printing timing
	if(rank == 0)
	{
		printf("About to begin timing\n");
		t_start=MPI_Wtime();
	}

	//Preliminary calculations
	total_iter=MAX-MIN+1;
	base_iter=(int)floor(total_iter/size);
	rem=total_iter%size;
	//Assign work based on chunks
	if(rank<rem)
	{
		start_idx=MIN+rank*(base_iter+1);
		end_idx=start_idx+base_iter;
	}
	else
	{
		start_idx=MIN+(rank*base_iter)+rem;
		end_idx=start_idx+base_iter-1;
	}

	//Calculation Loop
	#pragma omp parallel for private(j, sqrt_idx, isprime) reduction(+:primes_loc) schedule(auto)
	for(int i = start_idx; i < end_idx ; ++i)
	{
		sqrt_idx = (int)(sqrt(i))+1;
		j=2;
		isprime=1;
		while(j < sqrt_idx)
		{
			if((i%j) == 0)
			{
				isprime = 0;
				break;
			}
			j+=1;
		}
		if(isprime == 1)
		{
			primes_loc +=1;
		}
	}

	MPI_Reduce(&primes_loc,&primes,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	//Reducing values and printing on main rank

	if(rank == 0)
	{	
		printf("The number of primes %d took %f seconds to calculate\n",primes,MPI_Wtime()-t_start);
		printf("Program finished...\n");
	}
	//Finalising program and exiting
	MPI_Finalize();
	return 0;
}