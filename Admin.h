// #pragma once
#include "User.h"
#include "ParkingLot.h"

class Admin : public User {
public:
    Admin(const std::string& id, const std::string& name,
          const std::string& email, const std::string& password);

    std::string getRole() const override;

    bool addParkingFloor(ParkingLot& parkingLot, std::unique_ptr<ParkingFloor> floor);

    bool removeParkingFloor(ParkingLot& parkingLot, const std::string& floorId);

    bool modifyParkingRate(ParkingLot& parkingLot, double rate);

    bool addParkingAttendant(ParkingLot& parkingLot, std::unique_ptr<ParkingAttendant> attendant);

    bool removeParkingAttendant(ParkingLot& parkingLot, const std::string& attendantId);
};