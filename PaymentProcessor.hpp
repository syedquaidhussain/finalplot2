#pragma once
#include "Common.hpp"

class PaymentProcessor {
protected:
    double transactionFee;

public:
    PaymentProcessor(double fee = 0.0);
    virtual ~PaymentProcessor() = default;
    virtual bool processPayment(double amount) = 0;
    virtual double getTransactionFee() const;
    void setTransactionFee(double fee);
};