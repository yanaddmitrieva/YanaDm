#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
    int numerator;   // числитель
    int denominator; // знаменатель
   
    void reduce();
    
   
    int gcd(int a, int b) const;

public:
   
    //Rational() = delete;
    
    //  параметры
    Rational(int num, int den);
    
    
    Rational(const Rational& other);
    
    // методы
    int getNumerator() const;
    int getDenominator() const;
    
    // операции
    Rational add(const Rational& other) const;
    Rational multiply(const Rational& other) const;
    Rational divide(const Rational& other) const;
    
    // Вывод дроби
    void print() const;
};

#endif 