#include "Array.hpp"

#define RESET   "\033[0m"
#define PINK    "\033[35m"


int main(void)
{
{
    std::cout << PINK << "Testing default initialization" << RESET << std::endl;
    //default initializing
    int * a = new int();
    std::cout << a[0] << std::endl;
    delete a;
    
    //class test
    std::cout << PINK <<  "Template class test" <<  RESET << std::endl;
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


std::cout << PINK <<  "Copy constructor and assigment operator tests" <<  RESET << std::endl;
{
std::cout << "===== Copy Constructor Test =====" << std::endl;

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

    std::cout << "\n===== Assignment Operator Test =====" << std::endl;

    Array<int> assignTest(3);
    for (unsigned int i = 0; i < assignTest.size(); i++)
        assignTest[i] = i + 1; // 1, 2, 3

    std::cout << "Before assignment:" << std::endl;
    std::cout << "assignTest: ";
    for (unsigned int i = 0; i < assignTest.size(); i++)
        std::cout << assignTest[i] << " ";
    std::cout << std::endl;

    // Assign original array to assignTest
    assignTest = original;

    std::cout << "After assignment assignTest = original:" << std::endl;
    std::cout << "assignTest: ";
    for (unsigned int i = 0; i < assignTest.size(); i++)
        std::cout << assignTest[i] << " ";
    std::cout << std::endl;

    // Modify assignTest and check original stays the same
    assignTest[0] = 555;

    std::cout << "After modifying assignTest[0] = 555" << std::endl;
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

