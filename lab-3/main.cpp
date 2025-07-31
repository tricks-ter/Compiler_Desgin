#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string keywords[] = {"int", "float", "if", "else", "while", "for", "return", "void"};
int keywordsCount = 8;

char operators[] = {'+', '-', '*', '/', '=', '<', '>', '!', '%'};
int operatorsCount = 9;

bool isKeyword(const string& token) {
    for (int i = 0; i < keywordsCount; i++) {
        if (token == keywords[i]) return true;
    }
    return false;
}

bool isOperator(char c) {
    for (int i = 0; i < operatorsCount; i++) {
        if (c == operators[i]) return true;
    }
    return false;
}

bool isValidIdentifier(const string& token) {
    if (token.empty()) return false;
    if (!isalpha(token[0]) && token[0] != '_') return false;

    for (size_t i = 1; i < token.size(); i++) {
        if (!isalnum(token[i]) && token[i] != '_')
            return false;
    }
    return true;
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string token = "";
        for (size_t i = 0; i < line.length(); i++) {
            char c = line[i];

            if (isspace(c) || isOperator(c) || c == ';') {
                if (!token.empty()) {
                    if (isKeyword(token))
                        cout << token << "   : Keyword\n";
                    else if (isValidIdentifier(token))
                        cout << token << "   : Valid Identifier\n";
                    else
                        cout << token << "  : Invalid Identifier\n";
                    token = "";
                }
                if (isOperator(c)) {
                    cout << c << "   : Operator\n";
                }
                else if (c == ';') {
                    cout << c << "   : Statement Terminator\n";
                }
            }
            else {
                token += c;
            }
        }
        if (!token.empty()) {
            if (isKeyword(token))
                cout << token << "   : Keyword\n";
            else if (isValidIdentifier(token))
                cout << token << "   : Valid Identifier\n";
            else
                cout << token << "  : Invalid Identifier\n";
        }
    }

    file.close();
    return 0;
}
