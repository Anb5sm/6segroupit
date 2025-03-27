#include <iostream>
#include <string>
using namespace std;

bool checkForSingleLine(const string& text) {
    for (size_t i = 0; i < text.length() - 1; i++) {
        if (text[i] == '/' && text[i + 1] == '/') {
            return true;
        }
    }
    return false;
}

bool checkForMultiLine(const string& text) {
    size_t begin = string::npos, close = string::npos;
    
    for (size_t i = 0; i < text.length() - 1; i++) {
        if (text[i] == '/' && text[i + 1] == '*' && begin == string::npos) {
            begin = i;
        }
        if (text[i] == '*' && text[i + 1] == '/' && close == string::npos) {
            close = i;
        }
    }
    
    return (begin != string::npos && close != string::npos && begin < close);
}

bool analyzeComment(const string& text) {
    return checkForSingleLine(text) || checkForMultiLine(text);
}

int main() {
    string userInput;
    cout << "Enter a string: ";
    getline(cin, userInput);

    if (analyzeComment(userInput)) {
        cout << "Comment detected." << endl;
    } else {
        cout << "No valid comment found." << endl;
    }

    return 0;
}
