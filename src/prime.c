
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "mpi.h"

int main()
{
    int MAX;
    // Prompt user to enter MAX value
    printf("Enter a value for MAX (greater than 2): ");
    scanf("%d", &MAX);

    if (MAX <= 2) {
        printf("Invalid input. Please enter a value greater than 2.\n");
        return 1;
    }
    int total = 2;
    int j = 0;
    {
        int local_total = 0;
        for(int i=3; i<MAX ; i++)
        {
            int sqrt_i = (int)sqrt(i);
            j = 2;
            while(j < sqrt_i && (i % j) != 0)
            {
                j += 1;
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
        total += local_total;
    }

    printf("Finding all prime numbers under %d and %d total primes found\n", MAX, total);
    return 0;
}
