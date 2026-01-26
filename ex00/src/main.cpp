#include "whatever.hpp"

/* For std::cout*/
#include <iostream>
/* std::numeric_limits library for edge case test*/
#include <limits>
/* for strcmp*/
#include <string.h>
/* for the library std::ostringstream */
#include <sstream>

#define RESET   "\033[0m"
#define PINK    "\033[35m"
#define MAGENTA  "\033[0;35m"
#define RED     "\033[0;31m"
#define GREEN       "\033[0;32m"

/**
 *  @brief Macro for asserting test results and displaying appropriate messages
 */
#define ASSERT_TEST(expectedResultCondition, expectedResultMessage) \
	if (expectedResultCondition) \
        { std::cout << GREEN << "[TEST PASSED]" << RESET << " " << expectedResultMessage << std::endl; } \
	else \
        { std::cout << RED << "[TEST FAILED]" << RESET << " " << expectedResultMessage << std::endl; }


/**
 * @brief Util function for testing, convert std::os compatible variables to string
 */
template <typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;  //create empty string stream
	oss << value;            // put value to the stream
	return oss.str();        //extract accumulated string content in the stream and returns it
}

/**
 * @brief class to Test template functions min, max and swap
 */
class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    //overlo
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};

int main(int argc, char **av) 
{
    if (argc == 1)
    {
        std::cout << PINK << "\n/* ************************************************************************** */" << RESET << std ::endl;
		std::cout << PINK << "/*                                 MANDATORY                                  */" << RESET << std::endl;
		std::cout << PINK << "/* ************************************************************************** */" << RESET << std ::endl;
        
        int a = 2;
        int b = 3;
        ::swap( a, b ); //:: to use implemented swap, not already available c++ implementations
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        return 0;
    }
    else if (argc == 2 && strcmp(av[1], "moreTests") == 0)
    {
        std::cout << PINK << "\n/* ************************************************************************** */" << RESET << std ::endl;
		std::cout << PINK << "/*                                 TESTER PART                                */" << RESET << std::endl;
		std::cout << PINK << "/* ************************************************************************** */\n" << RESET << std ::endl;

		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                    CHAR                                    */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

		std::cout << MAGENTA << "TEST WITH CHAR" << RESET << std::endl;

		/* Test swap with chars */
		int x1 = 'a', y1 = 'Z';
		::swap(x1, y1);
		ASSERT_TEST(x1 == 'Z' && y1 == 'a', "swap(int): x = " + std::string(1, static_cast<char>(x1)) + ", y = " + std::string(1, static_cast<char>(y1)));
        
        
        std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                   INTEGERS                                 */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;

		std::cout << MAGENTA << "TEST WITH REGULAR INTEGER" << RESET << std::endl;

		/* Test swap with integers */
		int x = 1, y = 2;
		::swap(x, y);
		ASSERT_TEST(x == 2 && y == 1, "swap(int): x = " + toString(x) + ", y = " + toString(y));

		/* Test min with integers */ 
		ASSERT_TEST(::min(3, 4) == 3, "min(int): min(3, 4) == 3");
		
		/* Test max with integers */
		ASSERT_TEST(::max(3, 4) == 4, "max(int): max(3, 4) == 4");

		/* Test INT_MIN and INT_MAX */
		std::cout << MAGENTA << "\nTEST WITH INT_MIN AND INT_MAX" << RESET << std::endl;

		/* Test swap INT_MIN and INT_MAX */
		int int_min = std::numeric_limits<int>::min();
		int int_max = std::numeric_limits<int>::max();
		::swap(int_min, int_max);
		ASSERT_TEST(int_min == std::numeric_limits<int>::max() && int_max == std::numeric_limits<int>::min(), 
					"swap(int): int_min = " + toString(int_min) + ", int_max = " + toString(int_max));
		
		ASSERT_TEST(::min(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::min(), 
					"min(int): min(INT_MIN, INT_MAX) == INT_MIN");
		ASSERT_TEST(::max(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::max(), 
					"max(int): max(INT_MIN, INT_MAX) == INT_MAX");

        /* Test min below INT_MIN and max above INT_MAX */
		std::cout << MAGENTA << "\nTEST WITH INT_MIN-1 AND INT_MAX+1" << RESET << std::endl;
		long long int min_below = static_cast<long long int>(std::numeric_limits<int>::min()) - 1;
		long long int max_above = static_cast<long long int>(std::numeric_limits<int>::max()) + 1;
		ASSERT_TEST(::min(min_below, max_above) == min_below, 
					"min(long long): min(INT_MIN-1, INT_MAX+1) == INT_MIN-1");
		ASSERT_TEST(::max(min_below, max_above) == max_above, 
					"max(long long): max(INT_MIN-1, INT_MAX+1) == INT_MAX+1");

		/* Test swap INT_MIN-1 and INT_MAX+1 */
		::swap(min_below, max_above);
		ASSERT_TEST(min_below == static_cast<long long int>(std::numeric_limits<int>::max()) + 1 && max_above == static_cast<long long int>(std::numeric_limits<int>::min()) - 1, 
					"swap(long long): min_below = " + toString(min_below) + ", max_above = " + toString(max_above));

		long long large_pos = std::numeric_limits<long long>::max();
		long long large_neg = std::numeric_limits<long long>::min();
		::swap(large_pos, large_neg);
		ASSERT_TEST(large_pos == std::numeric_limits<long long>::min() && large_neg == std::numeric_limits<long long>::max(), 
        "swap(long long min, max): large_pos = min, large_neg = max");

		::swap(large_pos, large_neg);
		ASSERT_TEST(::min(large_pos, large_neg) == large_neg, "min(long long max, min) == min");		
		ASSERT_TEST(::max(large_pos, large_neg) == large_pos, "max(long long max, min) == max");
        

        std::cout << PINK << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                    STRING                                  */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;
		
		/* Test swap with strings */
		std::string str1 = "hello", str2 = "world";
		::swap(str1, str2);
		ASSERT_TEST(str1 == "world" && str2 == "hello", "swap(string): str1 = " + str1 + ", str2 = " + str2);

		/* Test min with strings */
		ASSERT_TEST(::min(std::string("apple"), std::string("banana")) == "apple", "min(string): min('apple', 'banana') == 'apple'");

		/* Test max with strings */
		ASSERT_TEST(::max(std::string("apple"), std::string("banana")) == "banana", "max(string): max('apple', 'banana') == 'banana'");

		/* Test swap with equal strings */
		std::string str3 = "equal", str4 = "equal";
		::swap(str3, str4);
		ASSERT_TEST(str3 == "equal" && str4 == "equal", "swap(string): str3 = " + str3 + ", str4 = " + str4);

        std::cout << PINK << "\n/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */" << RESET << std ::endl;
		std::cout << PINK << "/*                                   CLASSES                                  */" << RESET << std ::endl;
		std::cout << PINK << "/* -'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'-,-'- */\n" << RESET << std ::endl;
		
		/* Test swap with classes */ 
        Awesome instance2(2);
        Awesome instance3(3);

		::swap(instance2, instance3);
		ASSERT_TEST(instance3 == 2 && instance2 == 3, "swap(int): instance2 = " + toString(instance2.get_n()) + ", instance3 = " + toString(instance3.get_n()));

        /* Test min with integers */ 
        Awesome instance1(1);
        Awesome instance11(1);
		ASSERT_TEST(::min(instance1, instance11) == 1, "min(int): min(instance, instance11) == 3");
	
		///* Test max with integers */
        Awesome instance7(7);
        Awesome instance8(8);
		ASSERT_TEST(::max(instance7, instance8) == 8, "max(int): max(instance7, instance8) == 8");
        return 0;
    }
    else
    {
        std::cout << RED << "Run the program with the following: ./whatever or ./whatever moreTests" << RESET << std::endl;
        return 1;
    }
}