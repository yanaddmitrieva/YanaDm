#include <iostream>    
#include <iomanip>
#include <cmath>

using namespace std;           
 
double taylor_exp(double x, double eps)
{
    double row=2*x;
    double sum=row;
    int n=0;
    while (row >=eps){
        sum=sum+row;
        n++;
        row=2*(x+(std::pow(x,2*n+1)/(2*n+1)));

    }
    return sum;

}

int main()  {
    double x; double eps;
     int k;
    std::cout <<"Введите х: ";
    std::cin >> x;
    std::cout <<"Введите eps: ";
    std::cin >>eps;
    std::cout <<"Введите k : ";
    std::cin >> k;
    double taylor_res=taylor_exp(x,eps);
    double res=log((1+x)/(1-x));
    //вывод
    std::cout<<std::fixed << setprecision(k);
    std::cout<<"результат по тэйлору: "<< taylor_res << std::endl;
    std::cout<<"результат по логарифму : "<< res << std::endl;
    std::cout<<"разница: "<< std::abs(taylor_res-res) << std::endl;

    

    return 0;  
}                                                         
      
                         
      



//clang++ /Users/yanadmitrieva/Desktop/sss.cpp -o sss 