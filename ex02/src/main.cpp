#include "Array.hpp"

/* For std::cout*/
#include <iostream>


#define RESET     "\033[0m"
#define PINK      "\033[35m"
#define YELLOW    "\033[0;33m"
#define RED       "\033[0;31m"
#define GREEN     "\033[0;32m"




int main(void)
{
{
    //Concept review of default initializing
    //int * a = new int();
    //std::cout << a[0] << std::endl;
    //delete a;
    
    std::cout << PINK << "\n/* **************************************************************************/" << RESET << std ::endl;
	std::cout << PINK << "/*                                    TESTER                                  */" << RESET << std::endl;
	std::cout << PINK << "/* ***************************************************************************/\n" << RESET << std ::endl;
	std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
	std::cout << PINK << "/*                                   EMPTY                                     */" << RESET << std ::endl;
	std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

    //Testing empty array
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl; 

    // Copy empty
    Array<int> copyEmpty(empty);
    std::cout << "Copy empty size: " << copyEmpty.size() << std::endl;  // 0
    
    // Try out of bounds
    try {
        empty[0] = 5;  // Should throw
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
	std::cout << PINK << "/*                                   INT                                     */" << RESET << std ::endl;
	std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

    std::cout << PINK <<  "Testing subscript operator reading" <<  RESET << std::endl;
    Array<int> intArray(3);

    try
    {
        for(int i = 0; i < 3; i++)
            std::cout << intArray[i] << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Caught reading exception: " <<  e.what() << std::endl;
    }

    std::cout << PINK <<  "Testing subscript operator writing" <<  RESET << std::endl;
    try
    {
        for(int i = 0; i < 3; i++)
            intArray[i] = 127;
    }
    catch(std::out_of_range &e)
    {
        std::cout << "Caught writing exception: " <<  e.what() << std::endl;
    }
    for(int i = 0; i < 3; i++)
        std::cout << intArray[i] << std::endl;
}

std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
std::cout << PINK << "/*                               COPY CONSTRUCTOR                                */" << RESET << std ::endl;
std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

{
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = i * 10;  // 0, 10, 20, 30, 40

    // Use copy constructor
    Array<int> copy(original);

    std::cout << "Original array: ";
    for (unsigned int i = 0; i < original.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;

    std::cout << "Copied array:   ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    // Modify the copy and check original stays the same
    copy[2] = 999;

    std::cout << "After modifying copy[2] = 999" << std::endl;
    std::cout << "Original array: ";
    for (unsigned int i = 0; i < original.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;

    std::cout << "Copied array:   ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
std::cout << PINK << "/*                             ASSIGNMENT OPERATOR                               */" << RESET << std ::endl;
std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;
    Array<int> assignTest(3);
    for (unsigned int i = 0; i < assignTest.size(); i++)
        assignTest[i] = i + 1; // 1, 2, 3

    std::cout << YELLOW << "Before assignment:" << RESET <<std::endl;
    std::cout << "assignTest: ";
    for (unsigned int i = 0; i < assignTest.size(); i++)
        std::cout << assignTest[i] << " ";
    std::cout << std::endl;

    // Assign original array to assignTest
    assignTest = original;

    std::cout << YELLOW << "After assignment assignTest = original:" << RESET << std::endl;
    std::cout << "assignTest: ";
    for (unsigned int i = 0; i < assignTest.size(); i++)
        std::cout << assignTest[i] << " ";
    std::cout << std::endl;

    // Modify assignTest and check original stays the same
    assignTest[0] = 555;

    std::cout << YELLOW << "After modifying assignTest[0] = 555" << RESET << std::endl;
    std::cout << "assignTest: ";
    for (unsigned int i = 0; i < assignTest.size(); i++)
        std::cout << assignTest[i] << " ";
    std::cout << std::endl;

    std::cout << "Original array: ";
    for (unsigned int i = 0; i < original.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;
}
    return 0;
}

