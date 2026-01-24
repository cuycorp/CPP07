#include "iter.hpp"
#include <iostream>

void increaseOne(int &n)
{
    n++;
}

void readArray(const int &n)
{
    std::cout << n << std::endl;
}

int main()
{
    int len = 3;
    int arr[3] = {0, 1, 2};
    std::cout << "const reference test" << std::endl;
    iter(&arr[0], len, readArray);
    std::cout << std::endl;
    
    std::cout << "reference test" << std::endl;
    iter(&arr[0], len, increaseOne);
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
}