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

        //Operator overload
        T &operator [](unsigned int index);
        const T &operator [](unsigned int index) const;
        //member function
        unsigned int size(void) const;
};

#include  "Array.tpp"
#endif

