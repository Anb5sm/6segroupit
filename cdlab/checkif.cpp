#include <iostream>
#include <string>

using namespace std;


bool isValidIfStatement(const string& statement) {
    size_t ifPos = statement.find("if");
    if (ifPos == string::npos) return false;  // No 'if' keyword

    size_t openParen = statement.find('(', ifPos);
    size_t closeParen = statement.find(')', ifPos);

    if (openParen == string::npos || closeParen == string::npos || closeParen < openParen) {
        return false;  
    }

    
    string condition = statement.substr(openParen + 1, closeParen - openParen - 1);
    if (condition.empty()) {
        return false;  
    }

   
    size_t bodyStart = statement.find_first_of("{", closeParen);
    size_t bodyEnd = statement.find_first_of("}", closeParen);

    if (bodyStart != string::npos && bodyEnd != string::npos && bodyEnd > bodyStart) {
        return true;  
    }

    
    size_t semicolonPos = statement.find(";", closeParen);
    return semicolonPos != string::npos && semicolonPos > closeParen;  
}

int main() {
    string statement;

    cout << "Enter an if statement (C code): ";
    getline(cin, statement);

    if (isValidIfStatement(statement)) {
        cout << "This is a valid if statement." << endl;
    } else {
        cout << "This is not a valid if statement." << endl;
    }

    return 0;
}
