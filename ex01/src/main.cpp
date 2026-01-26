#include "iter.hpp"
#include <iostream>

/*                Test functions           */
/**
  @brief write function, increses by one the int variable received.
*/
void increaseOne(int &n)
{
    n++;
}

/**
  @brief read function, prints the int variable received.
*/
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


    std::cout << PINK << "\n/* **************************************************************************/" << RESET << std ::endl;
		std::cout << PINK << "/*                                    TESTER                                  */" << RESET << std::endl;
		std::cout << PINK << "/* ************************************************************************** */\n" << RESET << std ::endl;

		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                    ARRAY OF INTS                           */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

		std::cout << MAGENTA << "TEST WITH CHAR" << RESET << std::endl;

		/* Test swap with chars */
		int x1 = 'a', y1 = 'Z';
		::swap(x1, y1);
		ASSERT_TEST(x1 == 'Z' && y1 == 'a', "swap(int): x = " + std::string(1, static_cast<char>(x1)) + ", y = " + std::string(1, static_cast<char>(y1)));
        
        
    std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                              ARRAY OF CLASS VARIABLES                      */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

		std::cout << MAGENTA << "TEST WITH REGULAR INTEGER" << RESET << std::endl;
}

//add test with non function call to proove validity

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