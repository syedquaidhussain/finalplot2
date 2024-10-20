#pragma once
#include <stdexcept>
#include <string>

class ParkingFullException : public std::runtime_error {
public:
    ParkingFullException() : std::runtime_error("Parking lot is full") {}
};

class InvalidTicketException : public std::runtime_error {
public:
    InvalidTicketException() : std::runtime_error("Invalid ticket") {}
};

class PaymentFailedException : public std::runtime_error {
public:
    PaymentFailedException() : std::runtime_error("Payment failed") {}
};