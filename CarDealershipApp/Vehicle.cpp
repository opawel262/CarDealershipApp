#include "vehicle.h"

Vehicle::Vehicle(int id, int mileage, double price, const std::string& brand,
    const std::string& model, int productionYear, double engineCapacity,
    const std::string& bodyType, int enginePower, const std::string& gearbox,
    int seatingCapacity, const std::string& fuelType)
    : id(id), mileage(mileage), price(price), brand(brand), model(model),
    productionYear(productionYear), engineCapacity(engineCapacity),
    bodyType(bodyType), enginePower(enginePower), gearbox(gearbox),
    seatingCapacity(seatingCapacity), fuelType(fuelType) {}

double Vehicle::getEngineCapacity() const
{
    return this->engineCapacity;
}

int Vehicle::getId() const {
    return this->id;
}

std::string Vehicle::getBodyType() const {
    return this->bodyType;
}

int Vehicle::getMileage() const {
    return this->mileage;
}

int Vehicle::getProductionYear() const {
    return this->productionYear;
}

int Vehicle::getEnginePower() const {
    return this->enginePower;
}

std::string Vehicle::getGearbox() const {
    return this->gearbox;
}

int Vehicle::getSeatingCapacity() const {
    return this->seatingCapacity;
}

std::string Vehicle::getFuelType() const {
    return this->fuelType;
}

double Vehicle::getPrice() const {
    return this->price;
}

std::string Vehicle::getBrand() const
{
    return this->brand;
}

std::string Vehicle::getModel() const
{
    return this->model;
}

void Vehicle::setEngineCapacity(double value) {
    this->engineCapacity = value;
}

void Vehicle::setBodyType(const std::string& value) {
    this->bodyType = value;
}

void Vehicle::setMileage(int value) {
    this->mileage = value;
}

void Vehicle::setProductionYear(int value) {
    this->productionYear = value;
}

void Vehicle::setEnginePower(int value) {
    this->enginePower = value;
}

void Vehicle::setGearbox(const std::string& value) {
    this->gearbox = value;
}

void Vehicle::setSeatingCapacity(int value) {
    this->seatingCapacity = value;
}

void Vehicle::setFuelType(const std::string& value) {
    this->fuelType = value;
}

void Vehicle::setPrice(double value) {
    this->price = value;
}

void Vehicle::setBrand(const std::string& value)
{
    this->brand = value;
}

void Vehicle::setModel(const std::string& value)
{
    this->model = value;
}

void Vehicle::setId(int value)
{
    this->id = value;
}
