#include <iostream>
#include <string>
using namespace std;

// COMSC-210 | Lab 37 | Ian Kusmiantoro

int sum_ascii(string);

int main() {
    cout << sum_ascii("536B9DFC93AF") << endl;
    cout << sum_ascii("1DA9D64D02A0") << endl;
    cout << sum_ascii("666D109AA22E") << endl;
    cout << sum_ascii("E1D2665B21EA") << endl;

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
