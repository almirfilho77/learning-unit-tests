#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibCode3.hpp"

class MockedClass : public SimpleClass
{
public:
    MockedClass() = default;

    MOCK_METHOD0(SomeMethod, void());
};

TEST(TestSample, TestMock)
{
    MockedClass mc;
    EXPECT_CALL(mc, SomeMethod()).Times(1);
    mc.SomeMethod();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}