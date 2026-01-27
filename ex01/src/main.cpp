#include "iter.hpp"

/* For std::cout*/
#include <iostream>
/* std::numeric_limits library for edge case test*/
#include <limits>


#define RESET     "\033[0m"
#define PINK      "\033[35m"
#define MAGENTA   "\033[0;35m"
#define RED       "\033[0;31m"
#define GREEN     "\033[0;32m"

/*                Test functions           */
/**
  @brief write function, increses by one the int variable received.
*/
void increaseOne(int &n)
{
  std::cout<< "executing write array function: \n";  
  n++;
}

/**
  @brief read function, prints the int variable received.
*/
void readArray(const int &n)
{
  std::cout<< "executing read array function: \n";
  std::cout << n << std::endl;
}


/**
 *  @brief Macro for asserting test results and displaying appropriate messages
 */

#define ASSERT_TEST(expectedResultCondition, expectedResultMessage) \
	if (expectedResultCondition) \
        { std::cout << GREEN << "[TEST PASSED]" << RESET << " " << expectedResultMessage << std::endl; } \
	else \
        { std::cout << RED << "[TEST FAILED]" << RESET << " " << expectedResultMessage << std::endl; }




/**
 * @brief Template function to test iter function
 */
template <typename T, typename T2, typename Func>
void testIter(T *array, T2 length, Func func, T *expectedArray) 
{
    ::iter(array, length, func); //call iter
    bool passed = true; //value default to true
    for (T2 i = 0; i < length; ++i) { //loop over string passed to the function
        if (array[i] != expectedArray[i]) {
            passed = false; //checking for difference between expected result, if different, set false and assert.
            break;
        }
    }
    ASSERT_TEST(passed, "iter function works correctly.");
}


/* definitons needed for class test*/
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream &o, Awesome const &rhs)
{
  o << rhs.get();
  return o;
};

template< typename T >
void print( T& x )
{
  std::cout<< "executing write array function: \n";  
  std::cout << x << std::endl;
  return;
};

int main()
{

    std::cout << PINK << "\n/* **************************************************************************/" << RESET << std ::endl;
		std::cout << PINK << "/*                                    TESTER                                  */" << RESET << std::endl;
		std::cout << PINK << "/* ************************************************************************** */\n" << RESET << std ::endl;

		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                   INT                                      */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

		std::cout << MAGENTA << "TEST WITH ARRAY ON INTS" << RESET << std::endl;

		/* const reference test */
    std::cout << "const reference test" << std::endl;
    unsigned int len = 3;
    const int in_arr_const[3] = {0, 1, std::numeric_limits<int>::max()};
    testIter(in_arr_const, len, readArray, in_arr_const);

    /* reference test */
    std::cout << "reference test" << std::endl;
    int in_arr[3] = {0, 1, 4};
    int expected_arr[3] = {1, 2, 5};
    testIter(in_arr, len, increaseOne, expected_arr);
             
    std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                    CLASS                                   */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

		std::cout << MAGENTA << "TEST WITH ARRAY OF CLASS INSTANCES" << RESET << std::endl;
  
    /* test */
    Awesome classTable[5];
    testIter(classTable, 5, print<Awesome>, classTable);

    //std::cout << MAGENTA << "template test" << RESET << std::endl;
    //::iter(classTable, 5, 3);
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