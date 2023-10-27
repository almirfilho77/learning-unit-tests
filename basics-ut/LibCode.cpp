#include "LibCode.hpp"

#include <algorithm>
#include <string.h>

int sum(int a, int b)
{
    return a+b;
}

int count_all_positives(const std::vector<int> &v)
{
    return count_if(v.begin(), v.end(), [](int n){
        return n>=0;
    });
}

void to_upper(char *s)
{
    for (size_t i=0; i<strlen(s); i++)
    {
        s[i] = toupper(s[i]);
    }
}

void to_upper(std::string &s)
{
    for (size_t i=0; i<s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
}

double my_sqrt(double n)
{
    if (n < 0)
    {
        throw std::runtime_error("Cannot calculate the square root of a negative number!");
    }

    return sqrt(n);
}