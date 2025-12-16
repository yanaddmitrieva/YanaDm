#include "Rational.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;


Rational::Rational(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw invalid_argument("Знаменатель не может быть равен 0!");
    }
    reduce();
}

Rational::Rational(const Rational& other) 
    : numerator(other.numerator), denominator(other.denominator) {
    reduce();
}


int Rational::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void Rational::reduce() {
 
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

// методы
int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

// операции
Rational Rational::add(const Rational& other) const {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Rational(newNum, newDen);
}


Rational Rational::multiply(const Rational& other) const {
    int newNum = numerator * other.numerator;
    int newDen = denominator * other.denominator;
    return Rational(newNum, newDen);
}


Rational Rational::divide(const Rational& other) const {
    if (other.numerator == 0) {
        throw invalid_argument("Деление на ноль!");
    }
    int newNum = numerator * other.denominator;
    int newDen = denominator * other.numerator;
    return Rational(newNum, newDen);
}

// Вывод
void Rational::print() const {
    if (denominator == 1) {
        cout << numerator;
    } else if (numerator == 0) {
        cout << 0;
    } else {
       
        if (abs(numerator) > denominator) {
            int whole = numerator / denominator;
            int remainder = abs(numerator % denominator);
            if (whole < 0 && remainder != 0) {
                cout << whole << " " << remainder << "/" << denominator;
            } else if (remainder != 0) {
                cout << whole << " " << remainder << "/" << denominator;
            } else {
                cout << whole;
            }
        } else {
            cout << numerator << "/" << denominator;
        }
    }
    cout << endl;
}