#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// COMSC-210 | Lab 37 | Ian Kusmiantoro

int sum_ascii(string);

int main() {
    ifstream fin;
    fin.open("data.txt");

    // Guard clause
    if (!fin.good()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Sum each line and add to total
    string code;
    int total = 0;
    while (fin >> code) {
        total += sum_ascii(code);
    }

    cout << "Total sum: " << total << endl;
    // yay I get 69893419

    fin.close();

    return 0;
}

int sum_ascii(string str) {
    int sum = 0;

    for (char c : str) {
        sum += (int) c;
    }

    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
