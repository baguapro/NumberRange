#include <gtest/gtest.h>

#include <NumberRange.hpp>

namespace NR = NumberRange;

class TestNumberRange : public ::testing::Test { };

TEST_F(TestNumberRange, testRangeFor)
{
    NR::NumberRange range{10};
    long long count = 0;

    for(auto value : range)
        EXPECT_EQ(value, count++);
}

TEST_F(TestNumberRange, testReverseRangeFor)
{
    NR::NumberRange range{10};
    long long count = 9;

    for(auto value : NR::ReverseIterator{range})
        EXPECT_EQ(value, count--);
}

TEST_F(TestNumberRange, testRangeForStartAt5)
{
    NR::NumberRange range{10,5};
    long long count = 5;

    for(auto value : range)
        EXPECT_EQ(value, count++);
}

TEST_F(TestNumberRange, testReverseRangeForStartAt5)
{
    NR::NumberRange range{10,5};
    long long count = 9;

    for(auto value : NR::ReverseIterator{range})
        EXPECT_EQ(value, count--);
}

TEST_F(TestNumberRange, testRangeStepSize2)
{
    NR::NumberRange range{10,0,2};
    long long count = 0;

    for(auto value : range)
    {
        EXPECT_EQ(value, count);
        count += 2;
    }
}

TEST_F(TestNumberRange, testReverseRangeStepSize2)
{
    NR::NumberRange range{10,0,2};
    long long count = 9;

    for(auto value : NR::ReverseIterator{range})
    {
        EXPECT_EQ(value, count);
        count -= 2;
    }
}

TEST_F(TestNumberRange, DISABLED_testRangeNegitiveToPositive)
{
    NR::NumberRange range{-10,10};
    long long count = -10;

    for(auto value : range)
        EXPECT_EQ(value, count++);
}

TEST_F(TestNumberRange, DISABLED_testReverseRangePositiveToNegitive)
{
    NR::NumberRange range{10,-10};
    long long count = 9;

    for(auto value : NR::ReverseIterator{range})
        EXPECT_EQ(value, count--);
}

TEST_F(TestNumberRange, testRangeWithChar)
{
    NR::NumberRange range{'Z','A'};
    char count = 'A';

    for(auto value : range)
        EXPECT_EQ(value, count++);
}

TEST_F(TestNumberRange, testReverseRangeWithChar)
{
    NR::NumberRange range{'A','Z'};
    char count = 'Z';

    for(auto value : NR::ReverseIterator{range})
        EXPECT_EQ(value, count--);
}
