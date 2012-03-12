//****************************
// Chris Engstrom            *
// Project Euler - Problem 3 *
//*******************************************************************
// What is the largest prime factor of the number 600851475143 ?    *
//*******************************************************************

#include <iostream>
#include <time.h>

using namespace std;

// CONSTANTS //
const bool TIMED_RUN = false;       // Whether or not you want to see how long the program took to run

// FUNCTION PROTOTYPES //
bool checkForPrime(__int64 possiblePrime);                  // Check to see if the number passed in is a prime number
template <typename type> type intSqrt (type remainder);     // Find the integer square root of any positive number

int main() {
    // Variables to track how long the program took to run
    clock_t timeStart,
            timeEnd;

    if(TIMED_RUN)
    {
        // Get the time when the program starts
        timeStart = clock();
    }

    bool found = false;                     // Flag for when the largest prime factor is found
    __int64 number = 600851475143,          // Number to find the largest prime factor of
            divisor = intSqrt(number);      // Holds the possible prime factors as the loop is run,
                                            //	starts at the square root of the initial number

    // Introduce the program
    cout << "This program finds the largest prime factor of a number." << endl << endl;

    // Starting with the largest possible prime factor, work our way down checking numbers as we go
    do {
        // Check to see if the divisor goes into the number without a remainder
        if(!(number % divisor)) {
            // Check if the divisor is a prime number, if it is we have found the largest prime factor
            found = checkForPrime(divisor);
        }
        
        divisor--;      // Decrement the possible prime factor for the next run

    } while ( divisor > 1 && !found );      // Continue as long as the divisor is greater than one,
                                            //  and we haven't found the largest prime factor

    // Report the results
    cout << "The largest prime factor of " << number << " is: " << divisor + 1 << endl;

    if(TIMED_RUN)
    {
        // Get the time when the program is done
        timeEnd = clock();

        // Tell the user how long the program took to finish it's job
        cout << endl << "The program took " << ((double)timeEnd - (double)timeStart) / CLOCKS_PER_SEC << " seconds to run" << endl << endl;
    }

    return 0;
}

//*******************************************************************************
// FUNCTION: bool checkForPrime(int possiblePrime)                              *
//  int possiblePrime - Number that will be checked to see if it is prime       *
//                                                                              *
// RETURNS - Whether or not the number passed in is prime                       *
//*******************************************************************************
bool checkForPrime(__int64 possiblePrime)
{
    bool isPrime = true;

    // Search for a number that goes into the possiblePrime without a remainder
    for (int i = 2; i < possiblePrime; i++) {
        if(!(possiblePrime % i)) {
            // If such a number is found, the possiblePrime is not a prime number
            isPrime = false;
        }
    }

    return isPrime;
}

//***********************************************************************************
// TEMPLATE: type intSqrt (type remainder)                                          *
//  type remainder - number to find the square root of                              *
//																					*
// RETURNS - the integer square root of a positive number of any type               *
//                                                                                  *
// Found on http://www.codecodex.com/wiki/Calculate_an_integer_square_root#C.2B.2B  *
//***********************************************************************************
template <typename type>
type intSqrt (type remainder)  
{  
    if (remainder < 0) // if type is unsigned this will be ignored = no runtime  
        return 0; // negative number ERROR  
  
    type place = (type)1 << (sizeof (type) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000  
    while (place > remainder)  
        place /= 4; // optimized by complier as place >>= 2  
  
    type root = 0;  
    while (place)  
    {  
        if (remainder >= root+place)  
        {  
            remainder -= root+place;  
            root += place * 2;  
        }  
        root /= 2;  
        place /= 4;  
    }  
  return root;  
}  