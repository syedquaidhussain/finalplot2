#pragma once
#include "Common.hpp"
#include "ParkingFloor.hpp"
#include "ParkingAttendant.hpp"
#include "PaymentProcessor.hpp"

class ParkingLot {
private:
    static ParkingLot* instance;
    std::vector<std::unique_ptr<ParkingFloor>> floors;

    std::vector<std::unique_ptr<ParkingAttendant>> attendants;

    std::map<PaymentType, std::unique_ptr<PaymentProcessor>> paymentProcessors;
    
    double hourlyRate;
    int capacity;
    int currentVehicleCount;
    bool isOpen;

    ParkingLot();  // Private constructor for singleton

public:
    static ParkingLot* getInstance();
    ~ParkingLot();

    // Floor management
    bool addParkingFloor(std::unique_ptr<ParkingFloor> floor);
    bool removeParkingFloor(const std::string& floorId);
    
    // Attendant management
    bool addParkingAttendant(std::unique_ptr<ParkingAttendant> attendant);
    bool removeParkingAttendant(const std::string& attendantId);
    ParkingAttendant* findAttendant(const std::string& attendantId);
    
    // Vehicle operations
    ParkingTicket* getNewParkingTicket(Vehicle* vehicle);
    bool processExitTicket(ParkingTicket* ticket);
    
    // Payment operations
    void setHourlyRate(double rate);
    double getHourlyRate() const;
    bool addPaymentProcessor(PaymentType type, std::unique_ptr<PaymentProcessor> processor);
    
    // Status operations
    bool isFull() const;
    bool isOperational() const;
    void setOperationalStatus(bool status);
    int getCurrentVehicleCount() const;
    int getCapacity() const;
    
    // Prevent copying and assignment
    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;
};
