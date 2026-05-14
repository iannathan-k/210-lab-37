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
    while (fin >> code) {
        int hash = gen_hash_index(code);

        if (hash_table.find(hash) != hash_table.end()) {
            hash_table.at(hash).push_back(code); // If the hash already exists, then the list already exists
        } else {
            list<string> new_list {code}; // otherwise it's the first time seeing a hash
            hash_table.emplace(hash, new_list);
        }
    }

    auto it = hash_table.begin();
    auto end = hash_table.begin(); // iterator to end on

    // Prevent crash when table size < 100
    if (hash_table.size() < 100) {
        end = hash_table.end();
    } else {
        advance(end, 100); // Little trick from the Goat Manager 9000
    }

    while (it != end) {
        cout << "Hash - " << it->first << endl;

        list<string> list = it->second;
        for (string str : list) {
            cout << "\t" << str << endl;
        }

        it++;
    }

    fin.close();

    return 0;
}

int gen_hash_index(string str) {
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
