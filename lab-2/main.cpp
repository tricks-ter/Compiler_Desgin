#include <iostream>
#include <string>
using namespace std;


bool isNumericConstant(const string& s) {
    if (s.empty()) return false;
    for (char ch : s) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

void findOperators(const string& s) {
    int opCount = 0;
    for (char ch : s) {
        if (isOperator(ch)) {
            opCount++;
            cout << "operator" << opCount << ": " << ch << endl;
        }
    }
    if (opCount == 0)
        cout << "No operator found" << endl;
}

bool isSingleLineComment(const string& s) {
    return s.size() >= 2 && s[0] == '/' && s[1] == '/';
}

bool isMultiLineComment(const string& s) {
    return s.size() >= 4 && s.substr(0, 2) == "/*" && s.substr(s.size() - 2) == "*/";
}

bool isComment(const string& s) {
    return isSingleLineComment(s) || isMultiLineComment(s);
}


bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isAlphaNumeric(char ch) {
    return isAlpha(ch) || (ch >= '0' && ch <= '9');
}

bool isValidIdentifier(const string& s) {
    if (s.empty()) return false;
    if (!(isAlpha(s[0]) || s[0] == '_')) return false;
    for (size_t i = 1; i < s.size(); ++i) {
        if (!(isAlphaNumeric(s[i]) || s[i] == '_')) return false;
    }
    return true;
}

int main() {
    int choice;
    string input;

    do {
        cout << "\nChoose Task to run:\n";
        cout << "1. Check Numeric Constant\n";
        cout << "2. Find Operators\n";
        cout << "3. Check Comment Line\n";
        cout << "4. Check Identifier\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter input: ";
                getline(cin, input);
                if (isNumericConstant(input))
                    cout << "Numeric constant\n";
                else
                    cout << "Not numeric\n";
                break;

            case 2:
                cout << "Enter input: ";
                getline(cin, input);
                findOperators(input);
                break;

            case 3:
                cout << "Enter comment line(s): ";
                getline(cin, input);
                if (isSingleLineComment(input))
                    cout << "Single line comment\n";
                else if (isMultiLineComment(input))
                    cout << "Multi-line comment\n";
                else
                    cout << "Not a comment\n";
                break;

            case 4:
                cout << "Enter input to check identifier: ";
                getline(cin, input);
                if (isValidIdentifier(input))
                    cout << "Valid identifier\n";
                else
                    cout << "Not a valid identifier\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
