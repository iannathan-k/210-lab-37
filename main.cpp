#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// COMSC-210 | Lab 37 | Ian Kusmiantoro

int gen_hash_index(string);

int main() {
    ifstream fin;
    fin.open("data.txt");

    // Guard clause
    if (!fin.good()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    map<int, list<string>> hash_table;

    string code;
    int total = 0;
    while (fin >> code) {
        int hash = get_hash_index(code);

        if (hash_table.find(hash) != hash_table.end())
    }

    fin.close();

    

    return 0;
}

int get_hash_index(string str) {
    int hash = 0;

    for (char c : str) {
        hash += (int) c;
    }

    return hash;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
