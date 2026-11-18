#include "Bank.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void Bank::createAccount(std::string name,
                         std::string password,
                         double balance) {

    accounts.emplace_back(nextId,
                          name,
                          password,
                          balance);

    nextId++;
}

Account* Bank::findAccount(int id) {
    for (auto &acc : accounts) {
        if (acc.getId() == id) {
            return &acc;
        }
    }
    return nullptr;
}

void Bank::showAccounts() {
    for (auto &acc : accounts) {
        std::cout << acc.getId() << " - "
                  << acc.getName() << " - "
                  << std::fixed << std::setprecision(2) << acc.getBalance() << std::defaultfloat << "\n";
    }
}

void Bank::saveToFile() {
    std::ofstream file("data/accounts.txt");

    for (auto &acc : accounts) {
    file << acc.getId() << " "
         << acc.getName() << " "
         << acc.getPassword() << " "
         << acc.getBalance() << "\n";
    }

    file.close();
}

void Bank::loadFromFile() {
    std::ifstream file("data/accounts.txt");

    int id;
    std::string name;
    std::string password;
    double balance;

    while (file >> id >> name >> password >> balance) {
    accounts.emplace_back(id, name, password, balance);

    if (id >= nextId) {
        nextId = id + 1;
    }
}

    file.close();
}

void Bank::saveTransactions() {

    std::ofstream file("data/transactions.txt");

    for (auto &acc : accounts) {

        for (const auto &t : acc.getTransactions()) {

            file << acc.getId() << "|"
                 << t.getType() << "|"
                 << t.getAmount() << "|"
                 << t.getDateTime();
        }
    }

    file.close();
}

void Bank::loadTransactions() {

    std::ifstream file("data/transactions.txt");

    std::string line;

    while (getline(file, line)) {

        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);

        int id = std::stoi(line.substr(0, p1));

        std::string type =
            line.substr(p1 + 1, p2 - p1 - 1);

        double amount =
            std::stod(line.substr(p2 + 1, p3 - p2 - 1));

        std::string datetime =
            line.substr(p3 + 1);

        Account* acc = findAccount(id);

        if (acc != nullptr) {

            Transaction t(type, amount, datetime);

            acc->addTransaction(t);
        }
    }

    file.close();
}