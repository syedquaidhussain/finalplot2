// main.cpp
#include "ParkingLot.hpp"

#include "Admin.hpp"

#include "Customer.hpp"

#include "CompactSpot.hpp"

#include "LargeSpot.hpp"

#include "CreditCardPayment.hpp"

#include "CashPayment.hpp"
#include <iostream>

int main() {
    try {
        // Get parking lot instance
        ParkingLot* parkingLot = ParkingLot::getInstance();

        // Initialize payment processors
        parkingLot->addPaymentProcessor(
            PaymentType::CREDIT_CARD,
            std::make_unique<CreditCardPayment>("MERCHANT123", "TERM456")
        );
        parkingLot->addPaymentProcessor(
            PaymentType::CASH,
            std::make_unique<CashPayment>(1000.0)  // Initial cash drawer balance
        );

        // Create admin
        Admin admin("A1", "John Admin", "admin@parking.com", "admin123");

        // Create customer
        Customer customer("C1", "Alice", "alice@email.com", "pass123");

        // Create parking attendant
        auto attendant = std::make_unique<ParkingAttendant>(
            "PA1", "Bob", "bob@parking.com", "pass456"
        );
        parkingLot->addParkingAttendant(std::move(attendant));

        // Create vehicle
        Vehicle car("ABC123", VehicleType::CAR);

        // Create and configure parking floor
        auto floor = std::make_unique<ParkingFloor>("F1");
        floor->addParkingSpot(std::make_unique<CompactSpot>("CS1"));
        floor->addParkingSpot(std::make_unique<LargeSpot>("LS1"));

        // Add floor to parking lot
        parkingLot->addParkingFloor(std::move(floor));

        // Customer parks car
        ParkingTicket* ticket = parkingLot->getNewParkingTicket(&car);
        if (ticket) {
            customer.addTicket(ticket);
            std::cout << "Vehicle parked successfully!" << std::endl;
            
            // Process payment after some time
            double fee = ticket->calculateFee();
            std::cout << "Parking fee: $" << fee << std::endl;
            
            if (parkingLot->processExitTicket(ticket)) {
                std::cout << "Payment processed successfully!" << std::endl;
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}