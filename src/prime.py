import time
import  math

def main():
    start = time.time()
    MAX = 200000
    total = 0
    
    for i in range(1,MAX):
        sqroot = int(math.sqrt(i))
        j = 2
        while j < sqroot and (i % j) != 0:
            j+=1
        if j < sqroot: 
            #i is not prime
            pass 
        else:   
            total +=1
            #i is prime
    end = time.time()
    print(f"Finding all prime numebrs under {MAX} took {end-start} seconds, {total} primes found")
if __name__ == "__main__":
    main()
