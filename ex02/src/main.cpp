#include "Array.hpp"

int main(void)
{
    //default initializing
    //int * a = new int();
    //class test
    Array<int> intArray(3);


    for(int i = 0; i < 4; i++)
        std::cout << intArray.arr[i] << std::endl;

}