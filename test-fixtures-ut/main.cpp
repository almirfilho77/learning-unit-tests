#include <iostream>

#include "LibCode.hpp"

int main(int argc, char **argv)
{
    Account acc_1;
    acc_1.Deposit(1000);
    std::cout << "Balance of Accout 1: BRL " << acc_1.GetBalance() << '\n';

    Validator validator(5, 10);
    std::cout << "Type a value to see if it is in the range 5 to 10\n";
    int value_to_test;
    std::cin >> value_to_test;
    std::cout << value_to_test << " is " << ( validator.inRange(value_to_test) ? "in range\n" : "not in range\n" );
}