#ifndef WE_HPP
# define WE_HPP

template <typename T, typename Func>
void iter(T *array, const T len, Func func)
{
    for (int i = 0; i < len ; i++)
    {
        func(array[i]);
    }
}

#endif
