#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
struct Account {
    string password;
    double balance;
};

unordered_map<string, Account> accounts;

void createAccount() {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    
    if (accounts.find(userId) != accounts.end()) {
        cout << "Account already exists!" << endl;
        return;
    }
    
    cout << "Please enter your password: ";
    cin >> password;
    
    accounts[userId] = {password, 0.0};
    cout << "Thank You! Your account has been created!" << endl;
}

bool login(string& userId) {
    string password;
    cout << "Please enter your user id: ";
    cin >> userId;
    
    cout << "Please enter your password: ";
    cin >> password;
    
    if (accounts.find(userId) != accounts.end() && accounts[userId].password == password) {
        cout << "Access Granted!" << endl;
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***" << endl;
        return false;
    }
}

void depositMoney(string userId) {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    accounts[userId].balance += amount;
    cout << "Deposit successful!" << endl;
}

void withdrawMoney(string userId) {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;
    
    if (amount > accounts[userId].balance) {
        cout << "Insufficient balance!" << endl;
    } else {
        accounts[userId].balance -= amount;
        cout << "Withdrawal successful!" << endl;
    }
}

void requestBalance(string userId) {
    cout << "Your balance is $" << accounts[userId].balance << "." << endl;
}

int main() {
    char option;
    string userId;

    cout << "Hi! Welcome to the ATM Machine!" << endl;

    while (true) {
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> option;
        
        if (option == 'q') {
            cout << "Goodbye!" << endl;
            break;
        }
        
        if (option == 'c') {
            createAccount();
        } else if (option == 'l') {
            if (login(userId)) {
                while (true) {
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;
                    cout << "> ";
                    cin >> option;

                    if (option == 'd') {
                        depositMoney(userId);
                    } else if (option == 'w') {
                        withdrawMoney(userId);
                    } else if (option == 'r') {
                        requestBalance(userId);
                    } else if (option == 'q') {
                        break;
                    } else {
                        cout << "Invalid option!" << endl;
                    }
                }
            }
        } else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
