#include<iostream>
#include <string>
#include <sstream>
using namespace std;

class calculator {
public:
    float num1;
    float num2;
    virtual float ans() { return 0; };
};
class add :public calculator {
public:
    float ans() {
        return num1 + num2;
    }
};

class sub :public calculator {
public:
    float ans() {
        return num1 - num2;
    }
};

class mul :public calculator {
public:
    float ans() {
        return num1 * num2;
    }
};

class divi :public calculator {
public:
    float ans() {
        return num1 / num2;
    }
};

bool isFloat(string myString) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

float main() {
    calculator cal;
    add A;
    sub S;
    mul M;
    divi D;
    string userinput;
    float num1;
    float num2;
    string choice;

    while (true) {

        cout << "Please give the first number: ";
        getline(cin >> ws, userinput);
        if (isFloat(userinput) == 0)
        {
            cout << "Invalid, please insert a valid float \n";
        }

        else
        {
            num1 = stof(userinput);
            break;
        }
    }

    while (true)
    {
        cout << "Please give the second number: ";
        getline(cin >> ws, userinput);

        if (isFloat(userinput) == 0)
        {
            cout << "Invalid, please insert a valid float \n";
        }

        else
        {
            num2 = stof(userinput);
            break;
        }
    }

    while (true) {
        cout << "What kind of calculation would you like to do? (Add, Subtract, Multiply or Divide) ";
        cin.clear();
        getline(cin, choice);

        for (int i = 0; i < choice.length(); i++) {
            choice[i] = tolower(choice[i]);
        }

        if (choice == "add" or choice == "+") {
            A.num1 = num1;
            A.num2 = num2;
            float answer = A.ans();
            cout << answer;
            break;
        }

        else if (choice == "substract" or choice == "-") {
            S.num1 = num1;
            S.num2 = num2;
            float answer = S.ans();
            cout << answer;
            break;
        }

        else if (choice == "multiply" or choice == "*") {
            M.num1 = num1;
            M.num2 = num2;
            float answer = M.ans();
            cout << answer;
            break;
        }

        else if (choice == "divide" or choice == "/") {
            D.num1 = num1;
            D.num2 = num2;
            float answer = D.ans();
            cout << answer;
            break;
        }

        else {
            cout << "Please give a valid input from the options stated \n";
        }

    }

    return 0;
}
