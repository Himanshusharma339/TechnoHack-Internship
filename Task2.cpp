#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int checkPasswordLength(string str) {
    // Error checking for password length
    int passwordLength;

    try {
        passwordLength = stoi(str);
    }
    catch (...) {
        cout << "Invalid password length." << endl;
        return -1;
    }

    if (passwordLength < 1 || passwordLength > 50) {
        cout << "Invalid password length." << endl;
        return -1;
    }
    return passwordLength;
}

int getPasswordLength() {
    string str;

    cout << "Password length: ";
    getline(cin, str);

    return checkPasswordLength(str);
}

set<int> getOptions() {
    cout << "Character set options:" << endl;
    cout << "1. Lowercase (eg:- abcdef)" << endl;
    cout << "2. Uppercase (eg:- ABCDEF)" << endl;
    cout << "3. Digits (like:- 123456)" << endl;
    cout << "4. Symbols (like:- !@#${})" << endl;
    cout << "0. All" << endl;
    cout << "You may choose all or any combination of the first 4 options. Type all desired options separated by a space, then hit \"Enter\"." << endl;
    cout << "Option(s): ";

    string optionInput;
    getline(cin, optionInput);

    // Interpret input
    set<int> options;

    istringstream iss(optionInput);
    string token;
    while (iss >> token) {
        if (token == "1") {
            options.insert(1);
        }
        else if (token == "2") {
            options.insert(2);
        }
        else if (token == "3") {
            options.insert(3);
        }
        else if (token == "4") {
            options.insert(4);
        }
        else if (token == "0") {
            options.insert(1);
            options.insert(2);
            options.insert(3);
            options.insert(4);
        }
        else {
            cout << "Invalid option: " << token << endl;
        }
    }

    return options;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int passwordLength = getPasswordLength();
    if (passwordLength == -1) {
        return 1;
    }

    set<int> options = getOptions();

    // Generate password
    string password;
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()-_=+[{]}|;:',<.>/?";

    string charSet;
    if (options.find(1) != options.end()) {
        charSet += lowercase;
    }
    if (options.find(2) != options.end()) {
        charSet += uppercase;
    }
    if (options.find(3) != options.end()) {
        charSet += digits;
    }
    if (options.find(4) != options.end()) {
        charSet += symbols;
    }

    int charSetLength = charSet.length();
    for (int i = 0; i < passwordLength; ++i) {
        password += charSet[rand() % charSetLength];
    }

    cout << "Generated Password: " << password << endl;

    return 0;
}
