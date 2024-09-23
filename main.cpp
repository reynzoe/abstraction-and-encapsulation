#include <iostream>
#include <iomanip>

using namespace std;

// Abstract class for Account
class Account {
protected:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Current balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) = 0; // Pure virtual function for withdrawal

    virtual void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }
};

// Derived class for Savings Account
class SavingsAccount : public Account {
    const double minimumBalance = 1000;
public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {}

    void withdraw(double amount) override {
        if (amount > 0 && balance - amount >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance! Minimum balance of " << minimumBalance << " required." << endl;
        }
    }
};

// Derived class for Current Account
class CurrentAccount : public Account {
public:
    CurrentAccount(double initialBalance) : Account(initialBalance) {}

    void withdraw(double amount) override {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

// Function to display the account menu
void accountMenu(Account* account) {
    int choice;
    double amount;

    while (true) {
        cout << "\n--- Sub Menu ---\n1- Deposit\n2- Withdraw\n3- Check Balance\n4- Back\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                break;
            case 3:
                account->checkBalance();
                break;
            case 4:
                return; // Exit sub-menu
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

// Main function
int main() {
    int choice;
    SavingsAccount savings(1000); // Initialize with a default balance of 1000
    CurrentAccount current(500);  // Initialize with a default balance of 500

    while (true) {
        cout << "\n--- Main Menu ---\n1- Savings Account\n2- Current Account\n3- Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                accountMenu(&savings);
                break;
            case 2:
                accountMenu(&current);
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
