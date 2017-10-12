
// The '../' in the include statment for 'Varg.h' means to include some 
// file name Varg.h in the parent directory of the folder so that I can 
// access in contents to test my code


#include "Varg.h"
#include <stdio.h>
#include <stdarg.h>

// This define statement was to test my code for in failures or faults
// and print them out. If DEBUG is 1 it's off, but if 0 it's on.
#define DEBUG 1

// mostFrequentChar() takes any numbers of intergers as its argument within
// its restrictions. The first argument "int n" must be a number of integers.
// For Example, 
//
//          mostFrequentChar( 1, 2, 3);
// 
// Also, letters or characters are integers that following the standard
// ASCII code values, For example, 
// 
//          mostFrequentChar(a, b, c, d);
//
//          a = 97, b = 98, c = 99, d = 100
// If you were to printf these characters without the equals signs that I
// I gave them, they would still print those same numbers because of the 
// ASCII or American Standard Code for Information Interchange.


char mostFrequentChar(int n, ...)
{

    // Int f[] = {0}, this array of f has a frequency that starts at zero or
    // which basically says that each integer in this array will start at zero.
    // The variables i, j, k are not intialized but max is initialzed, because 
    // in the for loop function to "i, j, k," hold integers while max hold the sum.
    int f[26] = {0};
    int i, j, k, max = 0;

    // Declaring a variable of type va_list, called "argp." Basically, argp, is going to hold our list of
    // arguments to this function! To be clear: va_list is a data type, 
    //just like int, char, float, and so on.
    va_list argp;

    // This is how we initialize argp. The line basically means that argp is
    // a list of arguments to this function. It starts with the first variable passed to this function named "n".
    // If we had captured that variable under a different name, we would use that name below.
    va_start(argp, n);

    // For reasons necessary, so that program doesn't crash or have a so-called
    // "crap-attack". In the case that we run in a null terminator or the end 
    // of the program or at the beginning, middle, or end we put this here for
    // major insurance to not end the program even though there is more inside the program.
    if (n == 0)
        return '\0';

    // Arguments one by one will go into this loop but the variable "n" tells
    // how many arguments there are, so that it loops "n" that number of time. 
    for(i= 0; i < n; i++)
    {

        // Remember how we didn't initialize "i, j, k" because they are going to hold integers.
        // Except that j will be intialize to "va_arg(argp, int);" to store the values
        // from the numbers in "va_arg(argp, n);". In the va_arg function, the "argp" look for arguments
        // stored in variable and "int" tells va_arg function what data types were dealing with
        // or reading into the function. 
        // The resulting values are stored in j.
        j = va_arg(argp, int);

        // The is a frequency checkpoint or that's what I call it. The first argument
        // in va_arg is being pulled out which means its not being counted.
        // This code counts the first integer in va_arg and updates the frequency and sum.     
        f[j - 'a'] ++;

        if(max < f[j - 'a'])
        {
            max = f[j - 'a'];
            k = j;
        }
    }

    // This frees up lingering memory addocaited with the argo variable
    // and ensures no memory leaks in the arpg function. 
    va_end(argp);
    
    // The for loop in terminated and the return value fo "k" should be 
    // the sum of all the arguments passed to mostFrequentChar()
    // even the first argument from the frequency checkpoint.
    return k;
}

char fancyMostFrequentChar(char c, ...)
{
    // This is a same approach I did in mostFrequentChar() function
    // except this time the function called fancyMostFrequentChar() is having
    // characters values passed through it.
    //
    // Characters are also integers but you must know the ASCII values
    // Search for the ASCII values on any search engine
    int f[26] = {0};
    int i, j, k, max = 0;

    va_list argp; 

    // The setup is the same as before
    if( c == '\0')
        return '\0';

    // The list setup is the same as before.
    va_start(argp, c);

    // so-called Frequency checkpoint
    f[c - 'a'] ++;

    // The is just like a for loop before unlike the for loop from before
    // this actually checks to see if the next integer or character in the 
    // va_list argp is a null terminator or end of program. AS long as it's not
    // the program continutes to run unil it reaches the end of the program.
    // The va_arg() function is passing an integer data type through because chars and ints
    // are the same but int is easier to pass throug without a conversion code in the middle.
    while((j = va_arg(argp, int)) != '\0')
    {

        f[j - 'a'] ++;

        if(max < f[j - 'a'])
        {
            max = f[j - 'a'];
            k = j;
        }
    }

    // This frees up lingering memory addocaited with the argo variable
    // and ensures no memory leaks in the arpg function.
    va_end(argp);

    // The while loop is terminated and return value of "k" is  
    // sum of the arguments passed through fancyMostFrequentChar(),
    // even the first value that was pulled is passed through.
    // The return "k" is an integer, so I typecast the return value
    // to a character. Depending on the returned sum value, 
    // it convert it into a character,
    return (char) k;

}

double difficultyRating()
{
    // The reasons for my difficulty rating is because I had one semester
    // where I didn't take any coding classes and forgot some
    // of the material but this brought most of my skills back.
    // #saltyandsavory

    return 4.0;
}

double hoursSpent()
{
    // I don't have much of a life plus I struggle with coding
    // problems and understanding. 
    // Quote: "Don't wish it was easier, strive to do better."
    return 30.2;
}

