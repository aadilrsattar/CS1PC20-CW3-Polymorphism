//includes all the libraries needed for the program to run
#include<iostream> 
#include <string>
#include <sstream>

using namespace std;

//creates the base class known as calculator
class calculator {
public:

    //adds floats known as num1 and num2 to be used in the other classes
    float num1;
    float num2;
    virtual float ans() { return 0; };
};

//creates derived class known as add 
class add :public calculator {
public:

    //has function ans and executes it to add num1 and num2
    float ans() {
        return num1 + num2;
    }
};

//creates derived class known as sub 
class sub :public calculator {
public:

    //has function ans and executes it to subtracts num2 from num1
    float ans() {
        return num1 - num2;
    }
};

//creates derived class known as mul 
class mul :public calculator {
public:

    //has function ans and executes it to multiply num1 and num2 
    float ans() {
        return num1 * num2;
    }
};

//creates derived class known as div 
class divi :public calculator {
public:

    //has function ans and executes it to divides num1 by num2
    float ans() {
        return num1 / num2;
    }
};

//sourced from "https://stackoverflow.com/questions/447206/c-isfloat-function/57163016"
//this is the function to make sure a number is a float
bool isFloat(string myString) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

float main() {

    //converts the class' in to local variables to be used in main()
    calculator cal;
    add A;
    sub S;
    mul M;
    divi D;

    //defines the variables needed in main()
    float num1;
    float num2;
    string input;
    string choice;

    //this takes the input for num1 as a string and makes sure it is a valid float
    while (true) {
        
        cout << "Please give the first number: ";
        getline(cin >> ws, input);

        //if it is not a float, it will loop after telling you it is invalid
        if (isFloat(input) == 0)
        {
            cout << "Invalid, please insert a valid float \n";
        }

        //if it is a valid float, it will change it to a float and break the loop
        else
        {
            num1 = stof(input);
            break;
        }
    }

    //this takes the input for num2 as a string and makes sure it is a valid float
    while (true)
    {
        cout << "Please give the second number: ";
        getline(cin >> ws, input);

        //if it is not a float, it will loop after telling you it is invalid
        if (isFloat(input) == 0)
        {
            cout << "Invalid, please insert a valid float \n";
        }

        //if it is a valid float, it will change it to a float and break the loop
        else
        {
            num2 = stof(input);
            break;
        }
    }
    
    //loops till a valid input is given for choice
    while (true) {
        
        //takes input of choice
        cout << "What kind of calculation would you like to do? (Add, Subtract, Multiply or Divide) ";
        cin.clear();
        getline(cin, choice);

        //makes choice all lowercase, which stops any errors from not having proper case
        for (int i = 0; i < choice.length(); i++) {
            choice[i] = tolower(choice[i]);
        }

        //if choice is add or plus(+), it passes the num1 and num2 to A to be used in the add class, before executing ans() function
        if (choice == "add" or choice == "+") {
            A.num1 = num1;
            A.num2 = num2;
            float answer = A.ans();
            cout << answer;
            break;
        }

        //if choice is subtract or minus(-), it passes the num1 and num2 to S to be used in the sub class, before executing ans() function
        else if (choice == "substract" or choice == "-") {
            S.num1 = num1;
            S.num2 = num2;
            float answer = S.ans();
            cout << answer;
            break;
        }

        //if choice is multiply or asterisks(*), it passes the num1 and num2 to M to be used in the mul class, before executing ans() function
        else if (choice == "multiply" or choice == "*") {
            M.num1 = num1;
            M.num2 = num2;
            float answer = M.ans();
            cout << answer;
            break;
        }

        //if choice is divide or forward slash(/), it passes the num1 and num2 to D to be used in the divi class, before executing ans() function
        else if (choice == "divide" or choice == "/") {
            D.num1 = num1;
            D.num2 = num2;
            float answer = D.ans();
            cout << answer;
            break;
        }

        //if choice is invalid, it repeats the loop till a valid choice is given by the user
        else {
            cout << "Please give a valid input from the options stated \n";
        }

    }

    return 0;
}
