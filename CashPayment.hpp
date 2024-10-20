#pragma once
#include "PaymentProcessor.hpp"

class CashPayment : public PaymentProcessor {
private:
    double cashDrawerBalance;

public:
    CashPayment(double initialBalance = 0.0);
    bool processPayment(double amount) override;
    double getDrawerBalance() const;
    void adjustDrawerBalance(double amount);
};