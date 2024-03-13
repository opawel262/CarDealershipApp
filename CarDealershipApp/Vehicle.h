#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
    int id;
    int mileage;
    double price;
    std::string brand;
    std::string model;
    int engineCapacity;
    std::string bodyType;
    int productionYear;
    int enginePower;
    std::string gearbox;
    int seatingCapacity;
    std::string fuelType;

public:
    Vehicle() = default;
    Vehicle(int engineCapacity, int id, const std::string& bodyType, int mileage,
        int productionYear, int enginePower,
        const std::string& gearbox, int seatingCapacity, const std::string& fuelType,
        double price);

    int getEngineCapacity() const;
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

    void setId(int value);
    void setEngineCapacity(int value);
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
};

#endif 
