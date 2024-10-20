#pragma once
#include "User.hpp"
#include "ParkingTicket.hpp"
#include "PaymentProcessor.hpp"

class ParkingAttendant : public User {
private:
    std::vector<ParkingTicket*> processedTickets;

public:
    ParkingAttendant(const std::string& id, const std::string& name,
                     const std::string& email, const std::string& password);
    std::string getRole() const override;
    ParkingTicket* processVehicleEntry(Vehicle* vehicle, ParkingLot& parkingLot);
    bool processPayment(ParkingTicket* ticket, PaymentType paymentType);
    const std::vector<ParkingTicket*>& getProcessedTickets() const;
};