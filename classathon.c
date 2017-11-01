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
    // printf("21. num == %d\n", num);

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

    // Initialize variables
    int sum = 0;
    int isPrime = 0;

    // i is the dividend
    for (int i = 2; i <= num; i++)
    {
        // Reset isPrime = 0 after finding a prime number
        isPrime = 0;

        // j is the divisor
        for(int j = 2; j <= i/2; j++)
        {
            // Eliminate numbers that are divisible by a number between 1 and itself
            // if (i % j == 0) i is an even number so exit loop
            if (i % j == 0)
            {
                // Exit loop if a number is divisible by j
                isPrime = 1;
                break;
            }
        }

        // Sum the prime numbers before next iteration
        if (isPrime == 0 && num != 1)
        {
            sum = sum + i;
        }
    }

    // printf("sum == %d\n", sum);
    return sum;

}
