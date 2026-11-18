#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <vector>

class Transaction {
private:
    std::string type;
    double amount;
    std::string dateTime;

public:
    Transaction(std::string type,
            double amount,
            std::string dateTime);

    std::string getType() const;
    double getAmount() const;
    std::string getDateTime() const;
};

#endif