#include "Account.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int id,
                 std::string name,
                 std::string password,
                 double balance)
    : id(id),
      name(name),
      password(password),
      balance(balance) {}

void Account::deposit(double amount) {

    if (amount <= 0) {
        std::cout << "Invalid amount!\n";
        return;
    }

    balance += amount;

    time_t now = time(0);
    std::string dt = ctime(&now);

    transactions.emplace_back("Deposit", amount, dt);
}

bool Account::withdraw(double amount) {

    if (amount <= 0) {
        std::cout << "Invalid amount!\n";
        return false;
    }

    if (amount > balance) {
        std::cout << "Not enough balance\n";
        return false;
    }

    balance -= amount;

    time_t now = time(0);
    std::string dt = ctime(&now);

    transactions.emplace_back("Withdraw", amount, dt);

    return true;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getName() const {
    return name;
}

int Account::getId() const {
    return id;
}

void Account::showTransactions() const {

    std::cout << "\n===== TRANSACTIONS =====\n";

    for (const auto &t : transactions) {

    std::cout << std::fixed << std::setprecision(2);

    std::cout << t.getType()
              << " | $"
              << t.getAmount()
              << "\n"
              << t.getDateTime()
              << "\n\n";
}
}

void Account::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

const std::vector<Transaction>& Account::getTransactions() const {
    return transactions;
}

std::string Account::getPassword() const {
    return password;
}
