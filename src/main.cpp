#include <iostream>
#include <limits>
#include <iomanip>
#include "Bank.h"

int main() {
    Bank bank;

    bank.loadFromFile();
    bank.loadTransactions();

    Account* currentAccount = nullptr;

    int choice;

while (true) {

    if (currentAccount == nullptr) {

        std::cout << "\n===== BANK =====\n";
        std::cout << "1. Create account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Show accounts\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input!\n";

            continue;
        }

        if (choice == 1) {

            std::string name;
            std::string password;
            double balance;

            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Password: ";
            std::cin >> password;
            std::cout << "Start balance: ";

            if (!(std::cin >> balance)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid balance!\n";

                continue;
            }

            if (balance < 0) {
            std::cout << "Balance cannot be negative!\n";
            continue;
            }

            bank.createAccount(name, password, balance);
            bank.saveToFile();
            bank.saveTransactions();

            std::cout << "Account created!\n";
        }

        else if (choice == 2) {

            int id;

            std::cout << "Enter account ID: ";
            if (!(std::cin >> id)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid ID!\n";

                continue;
            }

            Account* acc = bank.findAccount(id);
            std::string password;

            std::cout << "Password: ";
            std::cin >> password;

            if (acc != nullptr && acc->getPassword() == password) {

                currentAccount = acc;

                std::cout << "Logged in as "
                          << currentAccount->getName()
                          << "\n";
            }
            else {
                std::cout << "Account not found!\n";
            }
        }

        else if (choice == 3) {
            bank.showAccounts();
        }

        else if (choice == 4) {
            bank.saveToFile();
            bank.saveTransactions();
            std::cout << "Goodbye!\n";
            break;
        }
        
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    else {

        std::cout << "\n===== ACCOUNT MENU =====\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Show balance\n";
        std::cout << "4. Show transactions\n";
        std::cout << "5. Logout\n";
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input!\n";

            continue;
        }

        if (choice == 1) {

            double amount;

            std::cout << "Amount: ";

            if (!(std::cin >> amount)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid amount!\n";

                continue;
            }

            currentAccount->deposit(amount);

            bank.saveToFile();
            bank.saveTransactions();

            std::cout << "Deposit successful!\n";
        }

        else if (choice == 2) {

            double amount;

            std::cout << "Amount: ";

            if (!(std::cin >> amount)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid amount!\n";

                continue;
            }

            currentAccount->withdraw(amount);

            bank.saveToFile();
            bank.saveTransactions();
        }

        else if (choice == 3) {

            std::cout << "Balance: "
                      << std::fixed << std::setprecision(2) << currentAccount->getBalance() << std::defaultfloat
                      << "\n";
        }

        else if (choice == 4) {

            currentAccount->showTransactions();
        }

        else if (choice == 5) {

            currentAccount = nullptr;

            std::cout << "Logged out!\n";
        }

        else {
            std::cout << "Invalid choice!\n";
        }
    }
}

return 0;
}