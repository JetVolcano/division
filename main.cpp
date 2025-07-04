#include <iostream>


double divide(double numerator, double denominator) {
    if (denominator == 0) throw std::invalid_argument("Division by zero");
    double sign = ((numerator < 0) ^ (denominator < 0)) ? -1 : 1;
    numerator = std::abs(numerator);
    denominator = std::abs(denominator);

    double quotient = 0.0;
    double factor = 1.0;

    // Integer part
    while (numerator >= denominator) {
        numerator -= denominator;
        quotient += 1.0;
    }

    // Decimal part
    for (int i = 0; i < 10 && numerator != 0; ++i) {
        numerator *= 10;
        factor /= 10;
        int digit = static_cast<int>(numerator / denominator);
        quotient += digit * factor;
        numerator -= digit * denominator;
    }

    return sign * quotient;
}


int main() {
    double a, b;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "Enter another number: ";
    std::cin >> b;
    std::cout << "Result: " << divide(a, b) << std::endl;
    return 0;
}