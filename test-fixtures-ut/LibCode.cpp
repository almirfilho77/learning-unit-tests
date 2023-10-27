#include "LibCode2.hpp"

#include <stdexcept>

Account::Account()
    :   m_balance(0)
{
}

void Account::Deposit(double sum)
{
    if (sum <= 0)
    {
        return;
    }

    m_balance += sum;
}

void Account::Withdraw(double sum)
{
    if (sum <= 0)
    {
        return;
    }

    if (m_balance < sum)
    {
        throw std::runtime_error("Insufficient funds!");
    }
    
    m_balance -= sum;
}

double Account::GetBalance() const
{
    return m_balance;
}

void Account::Transfer(Account &to, double sum)
{
    if (sum <= 0)
    {
        return;
    }

    Withdraw(sum);
    to.Deposit(sum);
}

Validator::Validator(int low, int high)
{
    if (low <= high)
    {
        m_low = low;
        m_high = high;
    }
    else
    {
        m_low = high;
        m_high = low;
    }
}

bool Validator::inRange(int value_to_test)
{
    return m_low <= value_to_test && m_high >= value_to_test;
}