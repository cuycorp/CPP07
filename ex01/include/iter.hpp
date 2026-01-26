#ifndef WE_HPP
# define WE_HPP

/**
    @brief iterates over an array of any type and applies a reading or wrting function.
*/

template <typename T, typename T2, typename Func>
void iter(T *array, const T2 len, Func anyFunc)
{
    for (T2 i = 0; i < len ; i++)
    {
        func(array[i]);
    }
}

#endif
