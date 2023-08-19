// NOTE: This template is to be used for partner practice ONLY! You must
// use the required Algorithmic Design Document for all Assignments.
/******************************************************************************
    # Author:           Arma Burton
    # Assignment:       001 Food Cart Ordering
    # Date:             July 30, 2023
    # Description:      This program inputs values from the user and computes
                        the cost and tip.
    # Input:            int, char, double, string
    # Output:           string, int, double
    # Sources:          user input
#******************************************************************************/
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

/*
    Name:   main()
    Desc:   This function reads menu input from the user
            If the menu option is 1 then it performs the function operations
            If the menu option is 2 then it quits the program
    input:  int
    output: string, char, int, double
    return: int
*/
int main()
{
    int menuOption;
    char addItem = 'y';
    double itemCost,
        tip,
        discount,
        subTotal,
        grandTotal;

    welcome();
    while (menuOption != 2)
    {
        tip = 0;
        discount = 0;
        subTotal = 0;
        grandTotal = 0;
        displayMenu();
        readOption(menuOption);
        switch (menuOption)
        {
        case 1:
            while (addItem != 'n')
            {
                placeOrder(itemCost);
                subTotal += itemCost;
                cout << subTotal << endl;
                addItem = 'x';
                readChar("Do you want another item? ( y / n ): ", addItem);
                while (tolower(addItem) != 'y' && tolower(addItem) != 'n')
                {

                    if (tolower(addItem) != 'y' && tolower(addItem) != 'n')
                    {
                        cout << "You have chosen poorly.\n";
                        readChar("Do you want another item? ( y / n ): ", addItem);
                    }
                }
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

/*
    Name:   welcome()
    Desc:   This function displays the welcome prompt
    input:  None
    output: prompt
    return: void
*/
void welcome()
{
    cout << endl;
    cout << "Welcome to my Food Cart Program!\n";
    cout << "What would you like to do today?\n";
}

/*
    Name:   displayMenu()
    Desc:   This function displays the menu
    input:  None
    output: prompt
    return: void
*/
void displayMenu()
{
    cout << "1. Place an order\n";
    cout << "2. Quit\n";
}

/*
    Name:   readOption()
    Desc:   This function reads an int from the user
    input:  int
    output: prompt
    return: void
*/
void readOption(int &option)
{
    cout << ">> ";
    cin >> option;
}

/*
    Name:   placeOrder()
    Desc:   This function calls the readString and readDouble functions
    input:  none
    output: prompt
    return: void
*/
void placeOrder(double &cost)
{
    readString("Enter the name of your item: ");
    readDouble("Enter the cost of your item: $", cost);
}

/*
    Name:   readString()
    Desc:   This function inputs a string from the user, then discards it.
    input:  string
    output: prompt
    return: void
*/
void readString(string prompt)
{
    string temp;
    cout << prompt;
    cin >> temp;
}

/*
    Name:   readInt()
    Desc:   This function reads an int from the user
            and performs a validation check
            if Validation check fails then function loops
    input:  int
    output: prompt
    return: void
*/
void readInt(string prompt, int &num)
{
    bool loopState = true;
    while (loopState)
    {
        ;
        cout << prompt;
        cin >> num;
        if (cin.fail())
        {
            cout << "Invaild input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (num < 0)
        {
            ;
            cout << "Invalid input. Please enter a positive integer.\n";
        }
        else
        {
            ;
            loopState = false;
        };
    };
}

/*
    Name:   readDouble()
    Desc:   This function reads an double from the user
            and performs a validation check
            if Validation check fails then function loops
    input:  double
    output: prompt
    return: void
*/
void readDouble(string prompt, double &num)
{
    bool loopState = true;
    while (loopState)
    {
        ;
        cout << prompt;
        cin >> num;
        cin.ignore(1000, '\n');
        if (cin.fail())
        {
            ;
            cout << "Invaild input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (num < 0)
        {
            ;
            cout << "Invalid input. Please enter a positive integer.\n";
        }
        else
        {
            ;
            loopState = false;
        };
    };
}

/*
    Name:   tipDiscount()
    Desc:   Prompts the user for the tip amount that they would like to add
            adds the tip amount to the cost and displays the new cost
            if the cost is over 50 then a 10% discount is applied
            if the cost is over 35 then a 5% discount is applied
    input:  double
    output: prompt
    return: void
*/
double tipDiscount(double &tip, double &discount, double cost)
{
    readDouble("Enter the amount of tip you want to add: $", tip);
    cost += tip;
    cout << "Your total is: $" << cost << endl;
    if (cost >= 50)
    {
        discount = cost * 0.1;
        cout << "You get a 10\% discount!\n";
    }
    else if (cost >= 35)
    {
        discount = cost * 0.05;
    }

    return cost - discount;
}

/*
    Name:   readChar()
    Desc:   This function reads an character from the user
    input:  char
    output: prompt
    return: void
*/
void readChar(string prompt, char &letter)
{
    cout << prompt;
    cin >> letter;
    letter = tolower(letter);
}

/*
    Name:   resetValues()
    Desc:   This function resets all values to default
    input:  none
    output: none
    return: void
*/
void resetValues(char &add, double &cost, double &tipAmount, double &discountAmount, double &sub, double &grand)
{
    add = 'y';
    cost = 0;
    tipAmount = 0;
    discountAmount = 0;
    sub = 0;
    grand = 0;
}
