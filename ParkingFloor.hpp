#pragma once
#include "Common.hpp"
#include "ParkingSpot.hpp"
#include "DisplayBoard.hpp"

class ParkingFloor {
private:
    std::string floorId;
    std::vector<std::unique_ptr<ParkingSpot>> spots;
    std::unique_ptr<DisplayBoard> displayBoard;
    std::map<SpotType, int> spotCounts;
    bool isOpen;

public:
    ParkingFloor(const std::string& id);
    const std::string& getId() const;
    void addParkingSpot(std::unique_ptr<ParkingSpot> spot);
    void removeParkingSpot(const std::string& spotId);
    ParkingSpot* findAvailableSpot(VehicleType vehicleType);
    void updateDisplayBoard();
    bool getFloorStatus() const;
    void setFloorStatus(bool status);
    const std::map<SpotType, int>& getSpotCounts() const;
};
