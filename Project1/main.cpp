#include <iostream>
#include <cassert>
using namespace std;

class BankAccount {
private:
double balance;

public:
BankAccount() : balance(0.0) {}

void deposit(double amount) {
if (amount > 0) {
balance += amount;
cout << "Deposited: $" << amount << "\n";
} else {
cout << "Invalid deposit amount. Please enter an amount greater than zero.\n";
}
assert(balance >= 0); 
}

void withdraw(double amount) {
if (amount > 0 && amount <= balance) {
balance -= amount;
cout << "Withdrawn: $" << amount << "\n";
} else if (amount <= 0) {
cout << "Invalid withdrawal amount. Please enter an amount greater than zero.\n";
} else {
cout << "Insufficient funds.\n";
}
assert(balance >= 0);
}

void checkBalance() const {
cout << "Current Balance: $" << balance << "\n";
}
};

int main() {
BankAccount account;
int choice;
double amount;

while (true) {
cout << "\nBanking System Menu:\n";
cout << "1. Deposit Money\n";
cout << "2. Withdraw Money\n";
cout << "3. Check Balance\n";
cout << "4. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1:
cout << "Enter deposit amount: ";
cin >> amount;
account.deposit(amount);
break;
case 2:
cout << "Enter withdrawal amount: ";
cin >> amount;
account.withdraw(amount);
break;
case 3:
account.checkBalance();
break;
case 4:
cout << "Exiting program. Thank you!\n";
return 0;
default:
cout << "Invalid choice. Please enter a number between 1 and 4.\n";
}
}
}