#include <iostream>
#include <cmath> 
using namespace std;

int get(int** arr, int i, int j) {
    return arr[i][j];
}

int abssum(int** arr, int rows, int col) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
        bool has = false;
        for (int i = 0; i < rows; i++) {
            if (arr[i][j] < 0) {
                has = true;
                break;
            }
        }
//если правда перебираем сумму
        if (has) {
            for (int i = 0; i < rows; i++) {
               sum += arr[i][j];
            }
        }
    }
    return sum;

}
int charact(int** matrix, int rows, int col) {
    int abssum = 0;
    for (int i = 0; i < rows; i++) {
        int val = get(matrix, i, col);
        if (val < 0 && val % 2 != 0) {
            abssum += abs(val);
        }
    }
    return abssum;
}
void sort(int** matrix, int rows, int cols) {
    int* chval = new int[cols];
    for (int j = 0; j < cols; j++) {
        chval[j] = charact(matrix, rows, j);
    }


    for (int j = 0; j < cols - 1; j++) {
        for (int k = 0; k < cols - j - 1; k++) {
            if (chval[k] > chval[k + 1]) {
                
                int temp= chval[k];
                chval[k] = chval[k + 1];
                chval[k + 1] = temp;

                for (int i = 0; i < rows; i++) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }

    delete[] chval;
}







int main(){
    int rows;
    int col;
    std::cout <<" enter rows count :"<< std::endl;
    std::cin>>rows;
    std::cout <<" enter columns count :"<< std::endl;
    std::cin>>col;
    
    int **arr=new int *[rows];

    for (int i=0;i<rows;i++){

        arr[i]=new int[col];
    }
//создание матрицы
    for (int i = 0;i<rows;i++){
        for (int j = 0;j<col;j++){
            //res= i+j;
            if((i+j)%2==0){
                arr[i][j]=0;
            }
            
            else{
                std::cout<<"enter number with coordinates("<<i<<","<<j<<"): ";
                std::cin>>arr[i][j];
            }
        }

    }
    arr[rows-1][col-1]=0;

    std::cout<<"The original matrix \n"<<std::endl;
//вывод матрицы
    for (int i = 0;i<rows;i++){
        for (int j = 0;j<col;j++){
            std::cout<<arr[i][j]<<"\t";

        }
            std::cout<<std::endl;

    }
    sort(arr, rows, col);
    std::cout<<std::endl;
    std::cout<<"The new matrix \n"<<std::endl;
//вывод матрицы
    for (int i = 0;i<rows;i++){
        for (int j = 0;j<col;j++){
            std::cout<<arr[i][j]<<"\t";

        }
            std::cout<<std::endl;

    }

    int sum = abssum(arr, rows, col);
    std::cout<<std::endl;
    std::cout<<"sum of absolute values of negative numbers is "<<sum<<std::endl;
    

    for (int i=0;i<rows;i++){
        
        delete[] arr[i];
    }
    delete[] arr;
    return 0;

}