#ifndef WE_HPP
# define WE_HPP

//function 

int lenPowerTwo(int a)
{
    return (a * a);
}

int doubleLen(int len)
{
    return (a * 2);
}

int readLen(cons int &len)
{
    std::cout << "reading len: " << len << std::endl;
}


template <typename T, typename Func>
void iter(T *addres, const T len, Func func)
{
    T nC = len;
    std::cout << "elem 1 of array: " << addres[0] << std::endl
    std::cout << "len: " << len << std::endl
    func() //calling const
(len) << std::endl;
}

#endif

