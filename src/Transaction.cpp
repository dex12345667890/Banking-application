#include "Transaction.h"
#include <string>
#include <iostream>
#include <vector>

Transaction::Transaction(std::string type,
                         double amount,
                         std::string dateTime)
    : type(type),
      amount(amount),
      dateTime(dateTime) {}

std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDateTime() const {
    return dateTime;
}