#pragma once
#include "Common.hpp"
#include "ParkingSpot.hpp"

class DisplayBoard {
private:
    std::string boardId;
    std::map<SpotType, int> availableSpots;
    bool isOperational;

public:
    DisplayBoard(const std::string& id);
    void updateAvailableSpots(const std::map<SpotType, int>& spots);
    void displayMessage(const std::string& message);
    bool getOperationalStatus() const;
    void setOperationalStatus(bool status);
    const std::map<SpotType, int>& getAvailableSpots() const;
};