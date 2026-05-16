#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// COMSC-210 | Lab 38 | Ian Kusmiantoro

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

    fin.close();

    int option = -1;
    while (true) { // no option to exit YET
        cout << "Hash Table Menu" << endl;
        cout << "[1] Print First 100 Entries" << endl;
        cout << "[2] Search For a Key" << endl;
        cout << "[3] Add a Key" << endl;
        cout << "[4] Remove a Key" << endl;
        cout << "Option: ";
        cin >> option;

        if (option == 1) {
            // Code from Lab 37
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
        } else if (option == 2) {
            string search_key;
            cout << "Enter Key to Search: ";
            cin >> search_key;

            // Verify if the hash even exists
            bool found = false;
            int hash = gen_hash_index(search_key);
            if (hash_table.find(hash) != hash_table.end()) {

                // Traverse the list to find if we have our hash
                for (string code : hash_table.at(hash)) {
                    if (code == search_key) {
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                cout << "Key was found!" << endl;
            } else {
                cout << "Key was not found!" << endl;
            }
        } else if (option == 3) {
            string new_key;
            cout << "Enter key to Add: ";
            cin >> new_key;

            int hash = gen_hash_index(new_key);
            // From Above
            if (hash_table.find(hash) != hash_table.end()) {
                hash_table.at(hash).push_back(new_key); // If the hash already exists, then the list already exists
            } else {
                list<string> new_list {new_key}; // otherwise it's the first time seeing a hash
                hash_table.emplace(hash, new_list);
            }
        } else if (option == 4) {
            string doomed_key;
            cout << "Enter key to Remove: ";
            cin >> doomed_key;

            int hash = gen_hash_index(doomed_key);
            // Ensure what we're deleting actually exists
            if (hash_table.find(hash) != hash_table.end()) {

                // Check if the key exists in the list
                bool found = false;
                for (string code : hash_table.at(hash)) {
                    if (code == doomed_key) {
                        found = true;
                        break;
                    }
                }
                
                if (found) {
                    hash_table.at(hash).remove(doomed_key);
                } else {
                    cout << "Key not found!" << endl;
                }

            } else {
                cout << "Key doesn't exist!" << endl;
            }
        }

        cout << endl;
    }

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
