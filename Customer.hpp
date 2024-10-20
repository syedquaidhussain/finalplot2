#pragma once
#include "User.hpp"
#include "ParkingTicket.hpp"
#include <vector>

class Customer : public User {
private:
    std::vector<ParkingTicket*> tickets;

public:
    Customer(const std::string& id, const std::string& name, 
            const std::string& email, const std::string& password);
    std::string getRole() const override;
    void addTicket(ParkingTicket* ticket);
    const std::vector<ParkingTicket*>& getTickets() const;
    double getTotalSpending() const;
};
