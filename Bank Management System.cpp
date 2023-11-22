#include <iostream>
#include <string>
using namespace std;

int previous_account_number[100] = {1, 2, 3};
string previous_account_Holder_Name[100] = {"John", "Don", "Tony"};
int balance_available[100] = {236, 230, 200};
int total_member = 3;
int limit = 100;
int key;
int memorysize = sizeof(previous_account_Holder_Name) / sizeof(previous_account_Holder_Name[0]);

void welcome();
int create_account();
void deposite_money();
void withdraw_money();
void display_account();

int main() {
    cout << "Welcome to Bank Management System" << endl;
    welcome();
    return 0;
}

void welcome() {
    cout << "1. Create Account" << endl
         << "2. Deposit Money" << endl
         << "3. Withdraw Money" << endl
         << "4. Display Account" << endl
         << "5. Exit";

    int user_choice;
    cout << endl << "Press Number(1-5): ";
    cin >> user_choice;
    switch (user_choice) {
    case 1:
        create_account();
        break;
    case 2:
        deposite_money();
        break;
    case 3:
        withdraw_money();
        break;
    case 4:
        display_account();
        break;
    case 5:
        cout << "Goodbye!";
        break;
    default:
        cout << "Invalid Choice!";
    }
}

int create_account() {
    while (total_member < limit) {
        cout << endl << "\tWelcome to create a new account" << endl << endl;
        int new_account_number, initial_balance;
        string new_account_name;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, new_account_name);
        cout << "Enter your Account Number: ";
        cin >> new_account_number;
        for (int i = 0; i < total_member; i++) {
            if (new_account_number == previous_account_number[i]) {
                cout << "Account Number is already exist" << endl << "Please input your account number: ";
                cin >> new_account_number;
                i = -1;
            }
        }
        cout << "Enter your initial balance: ";
        cin >> initial_balance;
        previous_account_Holder_Name[total_member] = new_account_name;
        previous_account_number[total_member] = new_account_number;
        balance_available[total_member] = initial_balance;
        cout << "Congratulations! Your account has been created successfully." << endl;
        total_member++;
        char response;
        cout << "Do you want to create another account? (y/n): ";
        cin >> response;

        if (response != 'y' && response != 'Y') {
            break;
        }
    }
    welcome();
    return 0;
}

void display_account() {
    cout << endl << "\tBank Account Information" << endl << endl;
    for (int i = 0; i < total_member; i++) {
        cout << "Account Holder Name: " << previous_account_Holder_Name[i] << endl;
        cout << "Account Number: " << previous_account_number[i] << endl;
        cout << "Account Balance: " << balance_available[i] << endl;
    }
    welcome();
}

void deposite_money() {
    int i, deposite, account_number;
    cout << "Enter your Account Number: ";
    cin >> account_number;
    for (i = 0; i < total_member; i++) {
        if (account_number != previous_account_number[i]) {
            cout << "Your account number is invalid" << endl;
            cout << "Again Enter Account Number: ";
            cin >> account_number;
            i = -1;
            continue;
        } else {
            key = i;
            break;
        }
    }
    cout << "Enter Amount: ";
    cin >> deposite;
    balance_available[key] += deposite;
    cout << "Now, Your Balance is " << balance_available[key] << endl << endl;
    // Return to the main menu
    welcome();
}

void withdraw_money() {
    int account_number, withdraw_balance, i;

    while (true) {
        cout << "Enter your Account Number: ";
        cin >> account_number;
        for (i = 0; i < total_member; i++) {
            if (account_number == previous_account_number[i]) {
                key = i;
                break;
            }
        }

        if (i == total_member) {
            cout << "Your account number is invalid. Please enter a valid account number." << endl;
        } else {
            break; // Break out of the loop if a valid account number is entered
        }
    }
    cout << "Enter your Amount: ";
    cin >> withdraw_balance;

    while (true) {
        if (withdraw_balance > balance_available[key]) {
            cout << "Insufficient funds. Your Balance is: " << balance_available[key] << endl;
            cout << "Enter your Amount again: ";
            cin >> withdraw_balance;
        } else {
            break;
        }
    }
    cout << "Withdrawal Amount: " << withdraw_balance << endl;
    cout << "Total Balance: " << balance_available[key];
    int remaining_balance = balance_available[key] - withdraw_balance;
    balance_available[key] = remaining_balance;
    cout << endl << "Remaining Balance: " << balance_available[key] << endl;
    cout << "Thank you for withdrawing money!!" << endl;
    int user;
    cout << "Press 1 for Back to Home Page and 2 for exit: ";
    cin >> user;
    if (user == 1) {
        welcome();
    }
}
