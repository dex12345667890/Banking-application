#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Transaction.h"
#include <vector>

class Account {
private:
    int id;
    std::string name;
    std::string password;
    double balance;

    std::vector<Transaction> transactions;

public:
    Account(int id,
        std::string name,
        std::string password,
        double balance);

    void deposit(double amount);
    bool withdraw(double amount);
    void showTransactions() const;

    void addTransaction(const Transaction& transaction);

    const std::vector<Transaction>& getTransactions() const;

    double getBalance() const;
    std::string getName() const;
    int getId() const;
    std::string getPassword() const;
};

#endif