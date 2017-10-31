#include <stdio.h>
#include <cs50.h>

long long factorialize(int num);
int sumFibs(int num);
int sumPrimes(int num);

// classathon 1:
// Create 4 functions to solve the following Algorithms:
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // Error message if no argument or too many arguments
        printf("You must provide an argument. \n");
        return 1;
    }

    // Convert input to int
    int num = atoi(argv[1]);
    printf("21. num == %d\n", num);
    printf("22. %c\n", num);

    // Output
    // printf("%lli\n",factorialize(num));
    // printf("%d\n",sumFibs(num));
    printf("%d\n",sumPrimes(num));

}

// Function should return an long long
long long factorialize(int num)
{
    if (num == 0)
        return 1;

    return (num * factorialize(num-1));

    // This way also works, but one-liner above works more efficiently
    // int prevNum = 1;
    // for (int i=1; i <= num; i++)
    // {
    //     prevNum = prevNum * i;
    // }
    // num = prevNum;

    // long long longnum = (long) num;
    // return longnum;
}


// Return the sum of all odd Fibonacci numbers that are less than or equal to num
// Function should return an int
int sumFibs(int num)
{
    // Formula from Wikipedia
    // https://en.wikipedia.org/wiki/Fibonacci_number
    // F[n] = F[n-1] + F[n-2]

    // Create an array to hold the numbers
    long long F[num];

    // Seed values for F[0]=1, F[1]=1
    F[0]=1;
    F[1]=1;

    // Sum the odd Fibonacci numbers <= num
    int sum = F[0] + F[1];
    for (int i = 2; i < num; i++)
    {
        F[i] = F[i-1] + F[i-2];

        if((F[i] % 2 > 0) && (F[i] <= num))
        {
            sum = sum + F[i];
        }
    }
    return sum;
}

// Sum all the prime numbers up to and including the provided number
// Function should return an int
int sumPrimes(int num) {
    // Sum prime numbers

    int primes[num];

    int p = sizeof(primes);
    printf("95. p == %d\n", p);

    int sum = 0;

    // 1 is not a prime, 2 is a prime number
    // 2 mod 2 == 0 so it won't pass the mod test
    // So push it onto the array because it is a prime
    primes[0] = 2;
    printf("92. primes[0] == %d\n", primes[0]);
    // printf("92. primes[1] == %d\n", primes[1]);
    // printf("92. primes[2] == %d\n", primes[2]);


    for (int h = 0; h < p; h++)
    {
        printf("103. h == %d\n", h);
        // Loop through numbers from 2 to num
        for (int i = 1; i <= num; i++)
        {
            // printf("108. i == %d\n",i);
            // if(i % 2 !== 0) then i is not an even number so test for prime
            if(i % 2 != 0){

                // Loop through each number from 2 to num
                for(int j = 2; j <= i; j++)
                {
                    // printf("115. j == %d\n",j);
                    // Eliminate numbers that are divisible by a number between 1 and itself
                    if ((i != j) && (i % j == 0))
                    {
                        // Exit loop if a number is divisible by j
                        break;
                    }
                    else if(i == j)
                    {
                        printf("118 inside else if(%d)\n", j);
                        // Push the number onto the array if it passes tests and is not already in the array
                        // if(primes.indexOf(i) == -1)

                        // for (int q = 0; q < p; q++)
                        // {
                        //     printf("116. primes[%d] = %d\n", q, primes[q]);
                        // }

                        primes[h] = j;

                        // for (int m = 0; m < p; m++)
                        // {
                        //     printf("128. %d - %d\n", m, primes[m]);
                        //     if (primes[m] == i)
                        //     {
                        //       printf("130. %d\n", primes[m]);
                        //       return true;
                        //     }
                        //     else
                        //     {
                        //       primes[m] = i;
                        //     }
                        // }
                    }
                }
            }
        }
    }

    for (int q = 0; q < p; q++)
    {
        printf("149. primes[%d] = %d\n", q, primes[q]);
    }

    //console.log("26. there are " + primes.length + " primes up to " + num);
    for (int k = 0; k < p; k++)
    {
        sum = sum + primes[k];
    }
    printf("sum == %d", sum);
    return sum;
}
