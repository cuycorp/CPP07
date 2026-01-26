#ifndef WE_HPP
# define WE_HPP

template <typename T>

/**
    @brief swaps the value of two variables of any type
*/

void swap(T &param1, T &param2)
{
    T temp = param1;
    param1 = param2;
    param2 = temp; 
}

/**
    @brief findd the minium value between two variables of any type
*/

template <typename T>
T min(T param1, T param2)
{
    if (param1 < param2)
        return (param1);
    return (param2);
}

/**
    @brief find the maximum value between two variables of any type
*/

template <typename T>
T max(T param1, T param2)
{
    if (param1 > param2)
        return (param1);
    return (param2);
}

#endif
