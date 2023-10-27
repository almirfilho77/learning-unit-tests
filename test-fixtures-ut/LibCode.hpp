#pragma once

class Account
{
public:
    Account();
    void Deposit(double sum);
    void Withdraw(double sum);
    double GetBalance() const;
    void Transfer(Account& to, double sum);

private:
    double m_balance;
};

class Validator
{
public:
    Validator(int low, int high);
    bool inRange(int value_to_test);

private:
    int m_low, m_high;
};