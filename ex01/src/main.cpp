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



/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  const int len = 5;

  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );

  return 0;
}


The difference in function calling of these two differents test confuse me. I call with only the function name while the other test calls
the function name with the specific type. I dont understand T& x 

why int& woudlnt work?
*/