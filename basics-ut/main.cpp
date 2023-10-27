/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

#include "LibCode.hpp"

int main()
{
    std::cout << "Main application\n";
    
    int s = sum(2,3);
    std::cout << "Sum = " << s << '\n'; 

    std::vector<int> v = {-1, 0, 1, 2, 3};
    std::cout << "There are " << count_all_positives(v) << " positive numbers in the vector\n";

    std::string str("hello world");
    std::cout << str << " in uppercase is ";
    to_upper(str);
    std::cout << str << '\n';
    
    double square_root;
    try
    {
        double input_val;
        std::cout << "Type a value and press enter to find its square root: ";
        std::cin >> input_val;
        square_root = my_sqrt(input_val);
        std::cout << "The square root of " << input_val << " is " << square_root << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}