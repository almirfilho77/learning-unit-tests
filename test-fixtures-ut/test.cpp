#include <gtest/gtest.h>
#include "LibCode2.hpp"

TEST(AccountTestSuite, NewlyCreateAccountIsEmpty)
{
    Account account;
    double balance = account.GetBalance();
    ASSERT_EQ(0, balance);
}

TEST(AccountTestSuite, DepositPositiveValue)
{
    Account account;

    account.Deposit(10.5);

    double balance = account.GetBalance();
    ASSERT_EQ(10.5, balance);
}

class AccountTestFixture : public testing::Test
{
public:
    AccountTestFixture();
    virtual ~AccountTestFixture();
    virtual void SetUp() override;
    virtual void TearDown() override;
    static void SetUpTestCase();
    static void TearDownTestCase();
protected:
    Account t_account;
};

AccountTestFixture::AccountTestFixture()
{
    std::cout << "C'tor\n";
}

AccountTestFixture::~AccountTestFixture()
{
    std::cout << "D'tor\n";
}

void AccountTestFixture::SetUp()
{
    std::cout << "SetUp\n";
    t_account.Deposit(10.5);
}

void AccountTestFixture::TearDown()
{
    std::cout << "TearDown\n";
}

void AccountTestFixture::SetUpTestCase()
{
    std::cout << "SetUpTestCase\n";
}

void AccountTestFixture::TearDownTestCase()
{
    std::cout << "TearDownTestCase\n";
}

TEST_F(AccountTestFixture, DepositNegativeValue)
{
    std::cout << "Test body\n";
    
    t_account.Deposit(-10.5);

    double balance = t_account.GetBalance();
    ASSERT_EQ(10.5, balance);
}

TEST_F(AccountTestFixture, WithdrawSuccess)
{
    t_account.Withdraw(3);

    double balance = t_account.GetBalance();
    ASSERT_EQ(7.5, balance);
}

TEST_F(AccountTestFixture, WithdrawError)
{
    ASSERT_THROW(t_account.Withdraw(300), std::runtime_error);
}

TEST_F(AccountTestFixture, TransferSuccess)
{
    Account to;

    t_account.Transfer(to, 3);

    ASSERT_EQ(7.5, t_account.GetBalance());
    ASSERT_EQ(3, to.GetBalance());
}

TEST_F(AccountTestFixture, TransferError)
{
    Account to;

    ASSERT_THROW(t_account.Transfer(to, 300), std::runtime_error);
}

// Unit test Validator class

class ValidatorFixture : public testing::TestWithParam<std::tuple<int, bool>>
{
public:
protected:
    Validator t_validator{5, 10};
};

TEST_P(ValidatorFixture, TestInRange)
{
    std::tuple<int, bool> tuple = GetParam();

    int param = std::get<0>(tuple);
    bool expectedResult = std::get<1>(tuple);

    std::cout << "param = " << param << " / expected: " << (expectedResult ? "True" : "False") << '\n';

    bool isInsideRange = t_validator.inRange(param);

    ASSERT_EQ(expectedResult, isInsideRange);
}

INSTANTIATE_TEST_CASE_P(InRange, ValidatorFixture, testing::Values(
            std::make_tuple(-50, false), 
            std::make_tuple(-0, false), 
            std::make_tuple(4, false), 
            std::make_tuple(5, true), 
            std::make_tuple(6, true), 
            std::make_tuple(7, true), 
            std::make_tuple(9, true), 
            std::make_tuple(10, true),
            std::make_tuple(11, false), 
            std::make_tuple(100, false)
    ));

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}