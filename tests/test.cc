#include <gtest/gtest.h>
#include <utils.hpp>

TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(sum(2, 3), 5);
}