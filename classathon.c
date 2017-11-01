#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long factorialize(int num);
int sumFibs(int num);
int sumPrimes(int num);
int strContains(int num);

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
    printf("%lli\n",factorialize(num));
    printf("%d\n",sumFibs(num));
    printf("%d\n",sumPrimes(num));
    printf("%d\n",strContains(num));
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




/*
Create the following algorithm function:
Should print a result then return an integer code
Function name: strContains

Inputs: 2 strings

If the 2nd string does not exist inside the first stringz then print:
“The string does not exist”
Then return the integer 0
If the 2nd string exists inside the first string print:
“The string exists”
Then return the integer 1
Ignore case.

Hacker level:
If the string contains the word more than once print:
“This string is full of the word”
Then return the integer 2

Sample tests:

“endangered” “end” true
“endangered” “danger” true
“the dog sleeps in the dog house” “Jack” false
“the dog sleeps in the dog house” “dog” true (hacker multiple)
Hacker level 2: Confirm case
“The dog sleeps in the dog house” “The” single true
“The dog sleeps in the dog house” the” single true
“The dog sleeps in the dog house” “dog” multi true

***************************************************************************************

NOTE:  this solution was derrived from TutorialsPoint.com C library functino - strstr()
https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
That function was not covered yet in CS50 so I solved this problem through my own research.
I discovered through trial and error that I cannot pass two command-line string arguments argv[1] and argv[2]
to a function, they have to be string literals and that is beyond me at this time.
*/

int strContains(num)
{
    // Test 1
    char firstString[] = "endangered";
    char secondString[] = "end";
    char *test1;

    test1 = strstr(firstString, secondString);

    if(test1){
        printf("The string exists\n");
        // return 1;
    }
    else
    {
        printf("The string does not exist\n");
        // return 0;
    }

    // Test 2
    char firstString2[] = "endangered";
    char secondString2[] = "danger";
    char *test2;

    test2 = strstr(firstString2, secondString2);

    if(test2){
        printf("The string exists\n");
        // return 1;
    }
    else
    {
        printf("The string does not exist\n");
        // return 0;
    }

   // Test 3
    char firstString3[] = "the dog sleeps in the dog house";
    char secondString3[] = "Jack";
    char *test3;

    test3 = strstr(firstString3, secondString3);

    if(test3){
        printf("The string exists\n");
        // return 1;
    }
    else
    {
        printf("The string does not exist\n");
        // return 0;
    }

   // Test 4
    char firstString4[] = "the dog sleeps in the dog house";
    char secondString4[] = "dog";
    char *test4;

    test4 = strstr(firstString4, secondString4);

    if(test4){
        printf("The string exists\n");
        return 1;
    }
    else
    {
        printf("The string does not exist\n");
        return 0;
    }


    // Throw away the argument passed in because of the other functions need it
    // but this one does not
    int nnum = num;
    if(nnum == false){
        printf("%d",nnum);
    }
}
