#include "Rational.h"
#include <iostream>

using namespace std;

int main() {
    try {
      
        Rational r1(3, 4);
        Rational r2(1, 2);
        Rational r3(-2, 3);
        Rational r4(5, -6); 
        
        cout << "Дроби:" << endl;
        cout << "r1 = "; r1.print();
        cout << "r2 = "; r2.print();
        cout << "r3 = "; r3.print();
        cout << "r4 = "; r4.print();
        cout << endl;
        
        // Тестирование get-методов
        cout << "Числитель r1: " << r1.getNumerator() << endl;
        cout << "Знаменатель r1: " << r1.getDenominator() << endl;
        cout << endl;
        
      
        cout << "Арифметические операции:" << endl;
        
        Rational sum = r1.add(r2);
        cout << "r1 + r2 = "; sum.print();
        
        Rational product = r1.multiply(r2);
        cout << "r1 * r2 = "; product.print();
        
        Rational quotient = r1.divide(r2);
        cout << "r1 / r2 = "; quotient.print();
        cout << endl;
        
      
        cout << "Работа с отрицательными числами:" << endl;
        Rational sumNeg = r1.add(r3);
        cout << "r1 + r3 = "; sumNeg.print();
        
        Rational productNeg = r3.multiply(r4);
        cout << "r3 * r4 = "; productNeg.print();
        cout << endl;
        
       
        Rational r5(r1);
        cout << "Копия r1 (r5) = "; r5.print();
        
        try {
            Rational zero(0, 1);
            Rational error = r1.divide(zero);
        } catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        
        try {
            Rational error(1, 0);
        } catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        
    } catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    
    return 0;
}