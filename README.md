# CPP07

* Concepts covered

    * Function template: reduces duplicated code.
        * template <typename T> : is a placeholder for an item
        * template <typename T> & void f1(T a){}; are in joint a template
        * These functions can be called with any type of argument. The only requirement is that the two arguments must have the same type and must support all the comparison operators.
        * .tpp file: for putting the logic of code associated to template, called in .hpp with include 
        * Function pointer vs function pointer
            * Template function pointer: defined to limit the scope of possible functions.
            * Specific function signature: flexible to any function valid for the logic inside the function template.

    * Resources
        * function templates: https://www.youtube.com/watch?v=XgGEJylsWsQ 

        * class templates: https://www.youtube.com/watch?v=mQqzP9EWu58
            * defines class with a particular type and template on compile type.
            * instantiates the class at run time. 
        * overloading function templates: https://youtu.be/l0Tg_95OKWw?si=TLxshIOewFvuq3b-

    * Other definitions
        * Preventive allocation: allocate with margin, just in case allocation.
        * Copy constructor: creates from scratch a new instance from already existing class, it makes a copy of the existing one.
        * Assignment operator: copy to an already existing isntance of a class.
    

    * Note on delete: 
        1. new T[n] → delete[] arr, new T[n], allocates enough contiguous memory to store n.
        2. new T → delete ptr

    * Note on const reference, and non const reference
        * non cost reference i.e. int const &, allows reading the value.
        * const reference i.e. int &, allows modifying the value persistingly.

* Resources
    * Assert test  https://github.com/raveriss/cpp07 

