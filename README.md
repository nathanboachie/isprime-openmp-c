# Prime Number Counter

## Introduction
Program to check how many prime numbers exist under a specified value.  
Includes an OpenMP implementation for multithreading.  
Will be continuously improved with respect to both serial and parallel implementation.

## Prime Number Implentation
Works on naive prime counting, better algorithms exist but this is easy to parallelise

## Parallelisation
1. MPI - Numbers divided into chunks and primes calculated 
2. OpenMP - Pragma for, its not good. I don't know why.

## Makefile
For parallel implementation, change prime.c to mpi_prime.c 

## Python code
Can just be ran as is, requrires time and math libraries
