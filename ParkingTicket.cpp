#pragma once
#include "Common.hpp"
#include "Vehicle.hpp"
#include "ParkingSpot.hpp"

class ParkingTicket {
private:
    std::string ticketId;
    time_t issueTime;
    time_t paymentTime;
    double amount;
    TicketStatus status;
    Vehicle* vehicle;
    ParkingSpot* spot;

public:
    ParkingTicket(const std::string& id, Vehicle* vehicle, ParkingSpot* spot);
    void markPaid();
    double calculateFee() const;
    TicketStatus getStatus() const;
    const Vehicle* getVehicle() const;
    const ParkingSpot* getSpot() const;
    const std::string& getId() const;
};