#include "Array.hpp"

int main(void)
{
    std::cout << "Testing default initialization" << std::endl;
    //default initializing
    int * a = new int();
    std::cout << a[0] << std::endl;
    
    //class test
    std::cout << "Template class test" << std::endl;
    Array<int> intArray(3);

    try
    {
    for(int i = 0; i < 10; i++)
        std::cout << intArray[i] << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Caught execption: " <<  e.what() << std::endl;
    }
}