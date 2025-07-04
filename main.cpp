#include <iostream>
#include <cmath>


double divide(double numerator, double denominator) {
    if (denominator == 0) throw std::invalid_argument("Division by zero");
    double quotient = 0.0;
    double sign = ((numerator < 0) ^ (denominator < 0)) ? -1 : 1;
    numerator = std::abs(numerator);
    denominator = std::abs(denominator);
    int tens = 0;
    while (numerator != 0) {
        if (numerator < denominator) {
            tens += 1;
            numerator *= 10;
        }
        if (tens > 19) {
            break;
        }
        numerator -= denominator;
        quotient += 1/std::pow(10, tens);
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