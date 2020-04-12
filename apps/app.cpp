#include <iostream>

#include <calculator/Calculator.h>

int main(int argc, char *argv[]) {
    Calculator calc;

    auto a = 25.0;
    auto b = 5.0;

    std::cout << a << " + " << b << " = " << calc.add(a, b) << "\n";
    std::cout << a << " - " << b << " = " << calc.subtract(a, b) << "\n";
    std::cout << a << " * " << b << " = " << calc.multiply(a, b) << "\n";
    std::cout << a << " / " << b << " = " << calc.divide(a, b) << "\n";

    return 0;
}
