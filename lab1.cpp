#include <iostream>
#include <cmath>

double taylor(double x,double eps){
    //int n;
    //std::cout << "Enter n : ";
    //std::cin >> n;
    //std::cout<<n<<std::endl;
    double first=x;
    //double taylor_dif=(pow(x,(2*i)+1))/(2*i+1);
    double taylor_res =x;
    int i =0;
     while (first >= eps) {
        i++; 
        //double taylor_dif=(pow(x,(2*i)+1))/(2*i+1);
        first= (pow(x,(2*i)+1))/(2*i+1);
        taylor_res += first;
    }

    double finish=2*taylor_res;
    std::cout<<finish<<std::endl;

    return finish;
}


int main(){
    int k;
    double x;
    double eps;
    double difference;
    std::cout << "Enter k (k ∈ N, k > 1): ";
    std::cin >> k ;

    std::cout << "Enter x (-1<x<1): ";
    std::cin >> x ;
    
    
    eps=pow(10, -k);
    std::cout<<"eps: "<<eps<<std::endl;
       
    double hand = taylor(x, eps); 
    std::cout<<"taylor res: "<<hand<<std::endl;
    double res = std::log((1+x)/(1-x));
    std::cout<<"exact res: "<<res<<std::endl;
    difference=hand-res;
    std::cout<<"difference: "<<difference<<std::endl;



}//у меня чет не работает(((((