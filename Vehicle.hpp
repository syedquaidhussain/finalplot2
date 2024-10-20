#pragma once
#include "Common.hpp"

class Vehicle {
private:
    std::string licenseNumber;
    VehicleType type;

public:
    Vehicle(const std::string& license, VehicleType type);
    const std::string& getLicenseNumber() const;
    VehicleType getType() const;
};
