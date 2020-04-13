#include <gtest/gtest.h>

#include <calculator/Calculator.h>

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorTest, testAdd) {
    EXPECT_EQ(calc.add(2, 4), 6);
    EXPECT_EQ(calc.add(1, 2), 3);
}

TEST_F(CalculatorTest, testSubtract) {
    EXPECT_EQ(calc.subtract(4, 2), 2);
    EXPECT_EQ(calc.subtract(2, 3), -1);
}

TEST_F(CalculatorTest, testMultiply) {
    EXPECT_EQ(calc.multiply(5, 2), 10);
    EXPECT_EQ(calc.multiply(4, -4), -16);
}

TEST_F(CalculatorTest, testDivide) {
    EXPECT_EQ(calc.divide(20, 4), 5);
    EXPECT_EQ(calc.divide(40, -10), -4);
}
