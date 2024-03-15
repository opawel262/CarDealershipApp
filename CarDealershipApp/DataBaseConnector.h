#pragma once
#include "sqlite3/sqlite3.h"
#include "Vehicle.h";
#include "Admin.h"
#include <vector>
class DataBaseConnector
{
private:
	sqlite3* dataBase;
	std::string query;
	std::vector<Vehicle> allVehicles;
	std::vector<Admin> allAdmins;

	void ExecuteUpdateStringParameter(const std::string& updateQuery, const std::string& parameter, int vehicleID);
	void ExecuteUpdateIntParameter(const std::string& updateQuery, int parameter, int vehicleID);
	void ExecuteUpdateStatement(sqlite3_stmt* statement);
public:
	DataBaseConnector(const std::string& file_name);
	~DataBaseConnector();

	std::vector<Vehicle> GetAllVehicles();
	std::vector<Admin> GetAllAdmins();

	void ExecuteUpdateDoubleParameter(const std::string& updateQuery, double parameter, int vehicleID);

	void DeleteVehicle(int vehicleID);
	Vehicle getVehicle(int vehicleID);
	std::vector<Vehicle> getVehicleWithFilter(const std::string& filter, const std::string& value);

	void AddVehicle(Vehicle& vehicle);
	void AddAdmin(Admin& admin);

	void UpdateVehicleId(int vehicleID, int newVehicleID);

	void UpdateVehicleEngineCapacity(int vehicleID, double newEngineCapacity);

	void UpdateVehicleMileage(int vehicleID, int newMileage);

	void UpdateVehiclePrice(int vehicleID, int price);

	void UpdateVehicleBrand(int vehicleID, const std::string& newBrand);

	void UpdateVehicleModel(int vehicleID, const std::string& newModel);

	void UpdateVehicleEngineCapacity(int vehicleID, int newEngineCapacity);

	void UpdateVehicleBodyType(int vehicleID, const std::string& newBodyType);

	void UpdateVehicleProductionYear(int vehicleID, int newProductionYear);

	void UpdateVehicleEnginePower(int vehicleID, int newEnginePower);

	void UpdateVehicleGearbox(int vehicleID, const std::string& newGearbox);

	void UpdateVehicleSeatingCapacity(int vehicleID, int newSeatingCapacity);

	void UpdateVehicleFuelType(int vehicleID, const std::string& newFuelType);
};