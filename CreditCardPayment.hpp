#pragma once
#include "PaymentProcessor.hpp"

class CreditCardPayment : public PaymentProcessor {
private:
    std::string merchantId;
    std::string terminalId;

public:
    CreditCardPayment(const std::string& merchant, const std::string& terminal);
    bool processPayment(double amount) override;
    bool validateCard(const std::string& cardNumber) const;
};