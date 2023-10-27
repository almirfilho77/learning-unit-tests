#include <gtest/gtest.h>
#include "LibCode.hpp"

TEST(SumTests, SumOfTwoPositives)
{
    int s = sum(2, 4);
    ASSERT_EQ(6, s);
}

TEST(CountAllPositivesTests, VectorWith1Positive)
{
    std::vector<int> input_vector{0,1,-1,-2};
    
    int count_of_positives = count_all_positives(input_vector);
    
    ASSERT_EQ(2, count_of_positives);
}

TEST(CountAllPositivesTests, EmptyVector)
{
    std::vector<int> input_vector{};
    
    int count_of_positives = count_all_positives(input_vector);
    
    ASSERT_EQ(0, count_of_positives);
}

TEST(CountAllPositivesTests, AllNegatives)
{
    std::vector<int> input_vector{-1, -2, -3};
    
    int count_of_positives = count_all_positives(input_vector);
    
    ASSERT_EQ(0, count_of_positives);
}

TEST(StringToUpperTests, BasicTestCString)
{
    char str[] = "hello world";

    to_upper(str);

    ASSERT_STREQ("HELLO WORLD", str);
}

TEST(StringToUpperTests, BasicTestStdString)
{
    std::string str("hello world");

    to_upper(str);

    ASSERT_EQ("HELLO WORLD", str);
}

TEST(SquareRootTests, PositiveArgument)
{
    double input_value = 4;

    double result = my_sqrt(input_value);

    EXPECT_EQ(2, result);
}

TEST(SquareRootTests, NegativeArgument)
{
    double input_value = -1;
    
    ASSERT_THROW(my_sqrt(input_value), std::runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}