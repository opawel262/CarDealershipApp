#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
    // Private member variables representing vehicle attributes
    int id;
    int mileage;
    double price;
    std::string brand;
    std::string model;
    double engineCapacity;
    std::string bodyType;
    int productionYear;
    int enginePower;
    std::string gearbox;
    int seatingCapacity;
    std::string fuelType;

public:
    // Constructors
    Vehicle() = default; // Default constructor
    Vehicle(int id, int mileage, double price, const std::string& brand,
        const std::string& model, int productionYear, double engineCapacity,
        const std::string& bodyType, int enginePower, const std::string& gearbox,
        int seatingCapacity, const std::string& fuelType);

    // Getter methods for retrieving vehicle attributes
    double getEngineCapacity() const;
    int getId() const;
    std::string getBodyType() const;
    int getMileage() const;
    int getProductionYear() const;
    int getEnginePower() const;
    std::string getGearbox() const;
    int getSeatingCapacity() const;
    std::string getFuelType() const;
    double getPrice() const;
    std::string getBrand() const;
    std::string getModel() const;

    // Setter methods for modifying vehicle attributes
    void setEngineCapacity(double value);
    void setBodyType(const std::string& value);
    void setMileage(int value);
    void setProductionYear(int value);
    void setEnginePower(int value);
    void setGearbox(const std::string& value);
    void setSeatingCapacity(int value);
    void setFuelType(const std::string& value);
    void setPrice(double value);
    void setBrand(const std::string& value);
    void setModel(const std::string& value);
    void setId(int value);
};

#endif // VEHICLE_H
