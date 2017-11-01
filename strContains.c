#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int strContains(char firstString[], char secondString[])
{

    char *test1;

    test1 = strstr(firstString, secondString);

    if(test1){
        printf("The string exists\n");
        return 1;
    }
    else
    {
        printf("The string does not exist\n");
        return 0;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        // Error message if no argument or too many arguments
        printf("You must provide two arguments. \n");
        return 1;
    }

    strContains(argv[1], argv[2]);

}