#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

void welcome();
void displayMenu();
void readOption(int &option);
void placeOrder(double &cost);
void readInt(string prompt, int &num);
void readDouble(string prompt, double &num);
void readString(string prompt);
void readChar(string prompt, char &letter);
double tipDiscount(double &tip, double &discount, double cost);
void resetValues(char &add, double &cost, double &tipAmount, double &discountAmount, double &sub, double &grand);

int main(){
    int menuOption;
    char addItem = 'y';
    double itemCost,
           tip,
           discount,
           subTotal,
           grandTotal;

    welcome();
    while(true){
        tip = 0;
        discount = 0;
        subTotal = 0;
        grandTotal = 0;
        displayMenu();
        readOption(menuOption);
        switch(menuOption){
            case 1:
                while(addItem != 'n'){
                    placeOrder(itemCost);
                    subTotal += itemCost;
                    cout << subTotal << endl;
                    readChar("Do you want another item? ( y / n ): ", addItem);
                }
                cout << "Your total is: " << subTotal << endl;
                grandTotal = tipDiscount(tip, discount, subTotal);
                cout << "Your discount is: $ " << discount << endl;
                cout << "Your final total is: $" << grandTotal << endl;
                resetValues(addItem, itemCost, tip, discount, subTotal, grandTotal);

                break;
            case 2:
                cout << "See you next time!\n";
                return 0;
            default:
                cout << "You have chosen poorly. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
    
    return 0;
}

void welcome(){
    cout << endl;
    cout << "Welcome to my Food Cart Program!\n";
    cout << "What would you like to do today?\n";
}

void displayMenu(){
    cout << "1. Place an order\n";
    cout << "2. Quit\n";
}

void readOption(int &option){
    cout << ">> ";
    cin >> option; 
}

void placeOrder(double &cost){
    readString("Enter the name of your item: ");
    readDouble("Enter the cost of your item: $", cost);
}

void readString (string prompt){
    string temp;
    cout << prompt;
    cin >> temp;
}

void readInt(string prompt, int &num){
    bool loopState = true;
    while(loopState){;
        cout << prompt;
        cin >> num;
        if (cin.fail()){;
            cout << "Invaild input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (num < 0){;
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {;
            loopState = false;
        };
    };
}

void readDouble(string prompt, double &num){
    bool loopState = true;
    while(loopState){;
        cout << prompt;
        cin >> num;
        if (cin.fail()){;
            cout << "Invaild input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (num < 0){;
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {;
            loopState = false;
        };
    };
}

double tipDiscount(double &tip, double &discount, double cost){
    readDouble("Enter the amount of tip you want to add: $", tip);
    cost += tip;
    cout << "Your total is: $" << cost << endl;
    if (cost >= 50){
        discount = cost * 0.1;
        cout << "You get a 10\% discount!\n";
    } else if (cost >= 35){
        discount = cost * 0.05;
    }

    return cost - discount;
}

void readChar(string prompt, char &letter){
    cout << prompt;
    cin >> letter;
    letter = tolower(letter);
}

void resetValues(char &add, double &cost, double &tipAmount, double &discountAmount, double &sub, double &grand){
    add = 'y';
    cost = 0;
    tipAmount = 0;
    discountAmount = 0;
    sub = 0; 
    grand = 0;
}

