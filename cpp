#include <iostream>
#include <vector>

using namespace std;

class Account {
private:
    string name;
    string accountNumber;
    float balance;

public:
    Account(string _name, string _accountNumber, float _balance) : name(_name), accountNumber(_accountNumber), balance(_balance) {}

    string getName() const { return name; }
    string getAccountNumber() const { return accountNumber; }
    float getBalance() const { return balance; }

    void displayAccountInfo() const {
        cout << "Name: " << name << ", Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    bool operator==(const Account& other) const {
        return accountNumber == other.accountNumber;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void displayMenu() {
        cout << "Welcome to the Bank Management System" << endl;
        cout << "1. Account management" << endl;
        cout << "2. ATM" << endl;
        cout << "3. Policies" << endl;
        cout << "4. Exit" << endl;
    }

    void accountManagement() {
        char choice;
        do {
            cout << "\nAccount Management Menu:" << endl;
            cout << "a. Display all accounts" << endl;
            cout << "b. Add account" << endl;
            cout << "c. Delete account" << endl;
            cout << "d. Back to main menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 'a':
                    displayAllAccounts();
                    break;
                case 'b':
                    addAccount();
                    break;
                case 'c':
                    deleteAccount();
                    break;
                case 'd':
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 'd');
    }

    void displayAllAccounts() const {
        cout << "\nAll Accounts:" << endl;
        for (const auto& acc : accounts) {
            acc.displayAccountInfo();
        }
    }

    void addAccount() {
        string name, accountNumber;
        float balance;
        cout << "Enter account holder's name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter initial balance: ";
        cin >> balance;

        Account newAccount(name, accountNumber, balance);
        accounts.push_back(newAccount);
        cout << "Account added successfully." << endl;
    }

    void deleteAccount() {
        string accountNumber;
        cout << "Enter account number to delete: ";
        cin >> accountNumber;

        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->getAccountNumber() == accountNumber) {
                accounts.erase(it);
                cout << "Account deleted successfully." << endl;
                return;
            }
        }

        cout << "Account number not found." << endl;
    }
};

int main() {
    Bank bank;
    char choice;
    do {
        bank.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                bank.accountManagement();
                break;
            case '2':
                cout << "ATM functionality not implemented." << endl;
                break;
            case '3':
                cout << "Displaying bank policies..." << endl;
                // Implement policy display
                break;
            case '4':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}