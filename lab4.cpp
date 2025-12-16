#include <iostream>
using namespace std;

int _atoi( char *string) {
    int i = 0;
    int sign = 1;
    int result = 0;
    while (string[i] == ' ') i++;
    if (string[i] == '-') {
        sign = -1;
        i++;
    } else if (string[i] == '+') {
        i++;
    }
    while (string[i] >= '0' && string[i] <= '9') {
        result = result * 10 + (string[i] - '0');//0 в чар=48
        i++;
    }
    int numb=result*sign;
    return numb;
}
int letters(char *word){
    int i=0;

    while (word[i] == ' ') i++;
}

int main() {
    std::cout << "atoi " << std::endl;
    char* num1 = "   -12345";
    char* num2 = " +375";
    char* num3 = "666abc";
    char* num4 = "kiwi";
   


    std::cout << "char: " << num1 << "  int: " << atoi(num1) << std::endl;
    std::cout << "char: " << num2 << "  int: " << atoi(num2) << std::endl;
    std::cout << "char: " << num3 << "  int: " << atoi(num3) << std::endl;
    std::cout << "char: " << num4 << "  int: " << atoi(num4) << std::endl;
  
    std::cout << "------------------------"<< std::endl;


    int max = 301; 
    char line[max];   
    std::cout << "enter line: "<< std::endl;
    cin.getline(line, max); 
    int len = strlen(line); 
    int i = 0; 

    char best[max]; 
    int repeats = 0;       

    while (i < len) {
       
        while (line[i] == ' ') i++;

        char word[max];//выделянм слово 
        int wordlen = 0;
        while (line[i] != ' ') {
            word[wordlen++] = line[i];
            i++;
        }
        word[wordlen] = '\0'; // конец слова

        int countletters[256] = {0};
        for (int j = 0; j < wordlen; j++) {
            char count = word[j];
            countletters[count]++;
        }

        int wordmax = 0;
        for (int j = 0; j < 256; j++) {
            if (countletters[j] > wordmax)
                wordmax = countletters[j];
        }

   
        if (wordmax > repeats) {
            repeats = wordmax;
            strcpy(best, word); 
        }
        if (i >= len) {
            break;}
    }

    
    std::cout << " word with most repeats is : "<<best<< std::endl;
   

    return 0;
}

