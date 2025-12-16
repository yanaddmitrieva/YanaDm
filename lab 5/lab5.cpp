#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;


bool pal(string word) {
    string newS = "";
    for (char c : word) {
        if (isalpha(c))
            newS+= c;
    }
    if (newS.empty()) return false;
    string rev = string(newS.rbegin(), newS.rend());
    return newS == rev;
}

int main() {

    string infile, outfile1, outfile2;
    cout << "enter name of input file(palin): ";
    getline(cin, infile);
    
    cout << "enter name of output file (with 1 palindrom): ";
    getline(cin, outfile1);

    cout << "nter name of output file (without palindroms): ";
    getline(cin, outfile2);

    ifstream in(infile);
    ofstream out1(outfile1);
    ofstream out2(outfile2);

    

    string line;
    bool has1 = false, has2 = false;

    while (getline(in, line)) {
        stringstream ss(line);
        string word;
        int count = 0;

        while (ss >> word)
            if (pal(word)) count++;

        if (count == 1) {
            out1 << line << endl;
            has1 = true;
        } else if (count == 0) {
            out2 << line << endl;
            has2 = true;
        }
    }



    cout << "done\n";
    return 0;
}