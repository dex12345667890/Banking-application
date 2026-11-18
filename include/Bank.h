#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>

class Bank {
private:
    std::vector<Account> accounts;
    int nextId = 1;

public:
    void createAccount(std::string name,
                   std::string password,
                   double balance);
    Account* findAccount(int id);
    void showAccounts();

    void saveToFile();
    void loadFromFile();
    void saveTransactions();
    void loadTransactions();
};

#endif