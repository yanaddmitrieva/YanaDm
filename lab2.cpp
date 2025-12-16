#include <iostream>   
#include <iomanip>
#include <cmath>
using namespace std; 

int main() {
    int n;
    int num[n];
    int product=1;
    

    std::string answer;

    std::cout<<"do you want to make an array of random numbers?"<<std::endl;
    std::cout<<"yes or no? "<<std::endl;
    std::cin >> answer;
    std::cout <<" Enter n:  ";
    std::cin >> n;
    if(answer=="yes"){
        int max;
        int min;

        std::cout <<" Enter min:  ";
        std::cin >> min;
        
        std::cout <<" Enter max:  ";
        std::cin >> max;
        std::cout<<"array is ";

        for(int i=0;i<n;++i){

            num[i]= min+rand()%max;
            std::cout<<" "<< num[i]<<" ";
        }

    }
    else{
        for(int i =0; i<n; i++){
        std::cout<<"enter number "<< i+1<<": ";
        std::cin>>num[i];
        

    }

    std::cout<<"array is ";
    for(int i =0; i<n; i++){
        std::cout<<" "<< num[i]<<" ";
     }
    
    }
    std::cout<<std::endl;
 //четные числа 
    std::cout<<"even numbers: ";
    for(int i =0; i<n; i++){
        
        if (num[i]%2==0){
            
            product=product*num[i];
            std::cout<<num[i]<<" ";
            continue;
        }
        }
    std::cout<<std::endl;
    std::cout<<"product is  "<<product<<std::endl;
//сумма
    int k = n-2;
    int sum=num[1]+num[k];
    
    std::cout<<"sum is  "<<sum<<std::endl;

    for(int i =0; i<n; i++){
        if (num[i]<0){
            std::cout<<" "<< num[i]<<" ";
            continue;
        }
        }
    for(int i =0; i<n; i++){
            if (num[i]>0){
            std::cout<<" "<< num[i]<<" ";
            continue;

        }
     }
    
    
    
    
    return 0;

   }
 

