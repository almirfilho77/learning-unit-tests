#pragma once

#include <iostream>

class SimpleClass
{
public:
    SimpleClass() = default;
    
    virtual void SomeMethod()
    {
        std::cout << "Say something\n";
    }
};