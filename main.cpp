#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber("0000"), accountHolderName("Unknown"), balance(0.0) {}
    BankAccount(string accNum, string holder, double bal = 0.0) {
        accountNumber = accNum;
        accountHolderName = holder;
        balance = bal;
    }
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }
    void setAccountHolderName(string newName) { accountHolderName = newName; }
    void deposit(double amount) {
        if (amount > 0) balance += amount;
        else cout << "Invalid deposit.\n";
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
        } else if (amount > 0) {
            balance -= amount;
        } else {
            cout << "Invalid withdrawal.\n";
        }
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n=== Bank Menu ===\n";
        cout << "1. Create Account\n";
        cout << "2. View Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string accNum, holder;
            double bal;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, holder);
            cout << "Enter initial balance: ";
            cin >> bal;
            accounts.push_back(BankAccount(accNum, holder, bal));
            cout << "Account created.\n";

        } else if (choice == 2) {
            for (auto& acc : accounts) {
                cout << acc.getAccountNumber() << " | "
                     << acc.getAccountHolderName() << " | $"
                     << acc.getBalance() << "\n";
            }

        } else if (choice == 3) {
            string accNum;
            double amt;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter deposit amount: ";
            cin >> amt;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) acc.deposit(amt);
            }

        } else if (choice == 4) {
            string accNum;
            double amt;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter withdrawal amount: ";
            cin >> amt;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNum) acc.withdraw(amt);
            }
        }
    } while (choice != 5);

    return 0;
}