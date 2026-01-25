#ifndef WE_HPP
# define WE_HPP

template <typename T, typename T2, typename Func>
void iter(T *array, const T2 len, Func anyFunc)
{
    for (T2 i = 0; i < len ; i++)
    {
        func(array[i]);
    }
}

#endif
