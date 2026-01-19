#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
    public:
        T *arr;
        unsigned int _size;
        //OCF
        Array(void); //empty array, only pointer?
        Array(unsigned int n); //create array, initialized by defualt
        Array(const Array& other);
        Array &operator=(const Array &other);
        ~Array();
        //member function
        T &operator [](unsigned int index) const;
        unsigned int size(void) const;
};

#include  "Array.tpp"
#endif

