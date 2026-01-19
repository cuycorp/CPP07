#include "Array.hpp"
#include <exception>

// Default constructor
template <typename T>
Array<T>::Array(void) : arr(NULL), _size(0)
{ 
    std::cout << "Default constructor called" << std::endl;
    return ;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    arr = new T[n];
    _size = n;
    return;     
}

template <typename T>
Array<T>::Array(const Array &other)
{
    std::cout << "Copy constructor called" << std::endl;
    _size = other._size;
    arr = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++)
        arr[i] = other.arr[i];
    return ;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        _size = other._size;
        delete[] arr;
        arr = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++)
            arr[i] = other.arr[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator [](unsigned int index)
{
    if(index < _size)
        return (arr[index]);
    else
        throw std::out_of_range("Index out of range");
}

template <typename T>
const T &Array<T>::operator [](unsigned int index) const
{
    if(index < _size)
        return (arr[index]);
    else
        throw std::out_of_range("Index out of range");
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] arr; //explore
    std::cout << "Destructor called" << std::endl;
    return ;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (_size);
}

