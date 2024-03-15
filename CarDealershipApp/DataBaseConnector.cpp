#define _CRT_SECURE_NO_WARNINGS
#include "DataBaseConnector.h"
#include <wx/wx.h>
DataBaseConnector::DataBaseConnector(const std::string& file_name)
{
    // Open the SQLite database file
    int result = sqlite3_open(file_name.c_str(), &dataBase);

    // Check if the database connection was successful
    if (result != SQLITE_OK)
    {
        // Log an error if connecting to the database failed
        wxLogError("Error connecting to database");
    }

    // Define SQL query to create the Vehicle table
    this->query = R"(
        CREATE TABLE IF NOT EXISTS Vehicle (
            id INTEGER PRIMARY KEY,
            mileage INTEGER,
            price REAL,
            brand TEXT,
            model TEXT,
            engineCapacity INTEGER,
            bodyType TEXT,
            year INTEGER,
            enginePower INTEGER,
            gearbox TEXT,
            seatingCapacity INTEGER,
            fuelType TEXT
        );
    )";

    // Execute the query to create the Vehicle table
    result = sqlite3_exec(dataBase, this->query.c_str(), nullptr, nullptr, nullptr);

    // Check if creating the Vehicle table was successful
    if (result != SQLITE_OK)
    {
        // Log an error if creating the Vehicle table failed
        wxLogError("Error creating Vehicle table: %s", sqlite3_errmsg(dataBase));
    }

    // Define SQL query to create the Admin table
    this->query = R"(
        CREATE TABLE IF NOT EXISTS Admin (
            username TEXT,
            password TEXT
        );
    )";

    // Execute the query to create the Admin table
    result = sqlite3_exec(dataBase, this->query.c_str(), nullptr, nullptr, nullptr);

    // Check if creating the Admin table was successful
    if (result != SQLITE_OK)
    {
        // Log an error if creating the Admin table failed
        wxLogError("Error creating Admin table: %s", sqlite3_errmsg(dataBase));
    }
}
DataBaseConnector::~DataBaseConnector()
{
	sqlite3_close(dataBase);
}
std::vector<Vehicle> DataBaseConnector::GetAllVehicles()
{
    std::vector<Vehicle> vehicles;

    // SQLite query to select all records from the "Vehicle" table
    this->query = "SELECT * FROM Vehicle;";

    // Execute the query
    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, this->query.c_str(), -1, &statement, nullptr);

    if (result == SQLITE_OK)
    {
        // Fetch data from the result set
        while (sqlite3_step(statement) == SQLITE_ROW)
        {
            // Assuming you have a constructor in your Vehicle class that takes SQLite column values
            Vehicle vehicle{};

            // Set properties of the vehicle object based on the columns in the result set
            vehicle.setId(sqlite3_column_int(statement, 0)); 
            vehicle.setMileage(sqlite3_column_int(statement, 1));
            vehicle.setPrice(sqlite3_column_double(statement, 2));
            vehicle.setBrand(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 3))));
            vehicle.setModel(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 4))));
            vehicle.setEngineCapacity(sqlite3_column_double(statement, 5));
            vehicle.setBodyType(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 6))));
            vehicle.setProductionYear(sqlite3_column_int(statement, 7));
            vehicle.setEnginePower(sqlite3_column_int(statement, 8));
            vehicle.setGearbox(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 9))));
            vehicle.setSeatingCapacity(sqlite3_column_int(statement, 10));
            vehicle.setFuelType(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 11))));

            vehicles.push_back(vehicle);
        }

        // Finalize the statement
        sqlite3_finalize(statement);
    }
    else
    {
        wxLogError("Error getting users");
    }

    return vehicles;
}

void DataBaseConnector::AddVehicle(Vehicle& vehicle)
{
    // SQLite query to insert a new record into the "Vehicle" table
    this->query = "INSERT INTO Vehicle (id, mileage, price, brand, model, engineCapacity, bodyType, year, enginePower, gearbox, seatingCapacity, fuelType) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?);";

    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, this->query.c_str(), -1, &statement, nullptr);

    if (result == SQLITE_OK)
    {
    // Bind parameters with the values from the provided Vehicle object
        sqlite3_bind_int(statement, 1, vehicle.getId());
        sqlite3_bind_int(statement, 2, vehicle.getMileage());
        sqlite3_bind_double(statement, 3, vehicle.getPrice());
        sqlite3_bind_text(statement, 4, vehicle.getBrand().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 5, vehicle.getModel().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(statement, 6, vehicle.getEngineCapacity());
        sqlite3_bind_text(statement, 7, vehicle.getBodyType().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(statement, 8, vehicle.getProductionYear());
        sqlite3_bind_int(statement, 9, vehicle.getEnginePower());
        sqlite3_bind_text(statement, 10, vehicle.getGearbox().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(statement, 11, vehicle.getSeatingCapacity());
        sqlite3_bind_text(statement, 12, vehicle.getFuelType().c_str(), -1, SQLITE_TRANSIENT);


        // Execute the insert statement
        result = sqlite3_step(statement);

        if (result != SQLITE_DONE)
        {
            wxLogError("Error adding vehicle: %s", sqlite3_errmsg(dataBase));
        }

        // Finalize the statement
        sqlite3_finalize(statement);
    }
    else
    {
        wxLogError("Error preparing insert statement: %s", sqlite3_errmsg(dataBase));
    }
}
void DataBaseConnector::DeleteVehicle(int vehicleID)
{
    // SQLite query to delete a record from the "Vehicle" table based on the vehicle's ID
    this->query = "DELETE FROM Vehicle WHERE id = ?;";

    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, this->query.c_str(), -1, &statement, nullptr);

    if (result == SQLITE_OK)
    {
        // Bind the vehicle ID as a parameter
        sqlite3_bind_int(statement, 1, vehicleID);  // Assuming there is a method like getID() in your Vehicle class

        // Execute the delete statement
        result = sqlite3_step(statement);

        if (result != SQLITE_DONE)
        {
            wxLogError("Error deleting vehicle: %s", sqlite3_errmsg(dataBase));
        }

        // Finalize the statement
        sqlite3_finalize(statement);
    }
    else
    {
        wxLogError("Error preparing delete statement: %s", sqlite3_errmsg(dataBase));
    }
}
Vehicle DataBaseConnector::getVehicle(int vehicleID)
{
    // Set the SQL query to select a vehicle by ID
    this->query = "SELECT * FROM Vehicle WHERE id = ?;";

    // Create a Vehicle object to store the retrieved data
    Vehicle vehicle;
    sqlite3_stmt* statement;

    // Prepare the SQL statement
    int result = sqlite3_prepare_v2(dataBase, this->query.c_str(), -1, &statement, nullptr);

    // Check if the statement was prepared successfully
    if (result == SQLITE_OK)
    {
        // Bind the vehicle ID parameter to the first placeholder in the statement
        sqlite3_bind_int(statement, 1, vehicleID);

        // Execute the query
        result = sqlite3_step(statement);

        // Check if a row was retrieved
        if (result == SQLITE_ROW)
        {
            // Retrieve data from columns and set them in the Vehicle object
            vehicle.setId(sqlite3_column_int(statement, 0));
            vehicle.setMileage(sqlite3_column_int(statement, 1));
            vehicle.setPrice(sqlite3_column_double(statement, 2));
            vehicle.setBrand(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 3))));
            vehicle.setModel(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 4))));
            vehicle.setEngineCapacity(sqlite3_column_int(statement, 5));
            vehicle.setBodyType(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 6))));
            vehicle.setProductionYear(sqlite3_column_int(statement, 7));
            vehicle.setEnginePower(sqlite3_column_int(statement, 8));
            vehicle.setGearbox(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 9))));
            vehicle.setSeatingCapacity(sqlite3_column_int(statement, 10));
            vehicle.setFuelType(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 11))));
        }
        else
        {
            // Log an error if no vehicle was found with the given ID
            wxLogError("No vehicle found with ID: %d", vehicleID);
        }

        // Finalize the statement to release resources
        sqlite3_finalize(statement);
    }
    else
    {
        // Log an error if preparing the statement failed
        wxLogError("Error preparing SQL statement");
    }

    // Return the retrieved vehicle object
    return vehicle;
}

std::vector<Vehicle> DataBaseConnector::getVehicleWithFilter(const std::string& filter, const std::string& value)
{
    std::vector<Vehicle> vehicles;

    if (filter == "id" || filter == "mileages" || filter == "price" || filter == "year") {
        this->query = "SELECT * FROM Vehicle WHERE " + filter + " = " + value + "; ";
    }
    else {
        this->query = "SELECT * FROM Vehicle WHERE " + filter + " LIKE '" + value + "%'; ";
    }

    // Execute the query
    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, this->query.c_str(), -1, &statement, nullptr);

    if (result == SQLITE_OK)
    {
        // Fetch data from the result set
        while (sqlite3_step(statement) == SQLITE_ROW)
        {
            // Assuming you have a constructor in your Vehicle class that takes SQLite column values
            Vehicle vehicle{};
            // Set properties of the vehicle object based on the columns in the result set
            vehicle.setId(sqlite3_column_int(statement, 0));
            vehicle.setMileage(sqlite3_column_int(statement, 1));
            vehicle.setPrice(sqlite3_column_double(statement, 2));
            vehicle.setBrand(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 3))));
            vehicle.setModel(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 4))));
            vehicle.setEngineCapacity(sqlite3_column_double(statement, 5));
            vehicle.setBodyType(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 6))));
            vehicle.setProductionYear(sqlite3_column_int(statement, 7));
            vehicle.setEnginePower(sqlite3_column_int(statement, 8));
            vehicle.setGearbox(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 9))));
            vehicle.setSeatingCapacity(sqlite3_column_int(statement, 10));
            vehicle.setFuelType(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 11))));

            vehicles.push_back(vehicle);
        }

        // Finalize the statement
        sqlite3_finalize(statement);
    }
    else
    {
        // Pobierz komunikat o błędzie
        const char* errorMessage = sqlite3_errmsg(dataBase);
        // Wyświetl komunikat o błędzie lub podejmij inne działania z nim związane
        wxLogError("SQLite error: %s", errorMessage);
    }

    return vehicles;
}


void DataBaseConnector::UpdateVehicleEngineCapacity(int vehicleID, double newEngineCapacity)
{
    std::string updateQuery = "UPDATE Vehicle SET engineCapacity = ? WHERE id = ?;";
    ExecuteUpdateDoubleParameter(updateQuery, newEngineCapacity, vehicleID);
}

void DataBaseConnector::UpdateVehicleMileage(int vehicleID, int mileage) {
    std::string updateQuery = "UPDATE Vehicle SET mileage = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, mileage, vehicleID);

}
void DataBaseConnector::UpdateVehiclePrice(int vehicleID, int price) {
    std::string updateQuery = "UPDATE Vehicle SET price = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, price, vehicleID);
}
void DataBaseConnector::UpdateVehicleBrand(int vehicleID, const std::string& newBrand)
{
    std::string updateQuery = "UPDATE Vehicle SET brand = ? WHERE id = ?;";
    ExecuteUpdateStringParameter(updateQuery, newBrand, vehicleID);
}

// Update function for the "model" field (assuming it's a string)
void DataBaseConnector::UpdateVehicleModel(int vehicleID, const std::string& newModel)
{
    std::string updateQuery = "UPDATE Vehicle SET model = ? WHERE id = ?;";
    ExecuteUpdateStringParameter(updateQuery, newModel, vehicleID);
}

// Update function for the "engineCapacity" field
void DataBaseConnector::UpdateVehicleEngineCapacity(int vehicleID, int newEngineCapacity)
{
    std::string updateQuery = "UPDATE Vehicle SET engineCapacity = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, newEngineCapacity, vehicleID);
}

// Update function for the "bodyType" field (assuming it's a string)
void DataBaseConnector::UpdateVehicleBodyType(int vehicleID, const std::string& newBodyType)
{
    std::string updateQuery = "UPDATE Vehicle SET bodyType = ? WHERE id = ?;";
    ExecuteUpdateStringParameter(updateQuery, newBodyType, vehicleID);
}

// Update function for the "productionYear" field
void DataBaseConnector::UpdateVehicleProductionYear(int vehicleID, int newProductionYear)
{
    std::string updateQuery = "UPDATE Vehicle SET year = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, newProductionYear, vehicleID);
}

// Update function for the "enginePower" field
void DataBaseConnector::UpdateVehicleEnginePower(int vehicleID, int newEnginePower)
{
    std::string updateQuery = "UPDATE Vehicle SET enginePower = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, newEnginePower, vehicleID);
}

// Update function for the "gearbox" field (assuming it's a string)
void DataBaseConnector::UpdateVehicleGearbox(int vehicleID, const std::string& newGearbox)
{
    std::string updateQuery = "UPDATE Vehicle SET gearbox = ? WHERE id = ?;";
    ExecuteUpdateStringParameter(updateQuery, newGearbox, vehicleID);
}

// Update function for the "seatingCapacity" field
void DataBaseConnector::UpdateVehicleSeatingCapacity(int vehicleID, int newSeatingCapacity)
{
    std::string updateQuery = "UPDATE Vehicle SET seatingCapacity = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, newSeatingCapacity, vehicleID);
}

// Update function for the "fuelType" field (assuming it's a string)
void DataBaseConnector::UpdateVehicleFuelType(int vehicleID, const std::string& newFuelType)
{
    std::string updateQuery = "UPDATE Vehicle SET fuelType = ? WHERE id = ?;";
    ExecuteUpdateStringParameter(updateQuery, newFuelType, vehicleID);
}

void DataBaseConnector::ExecuteUpdateStringParameter(const std::string& updateQuery, const std::string& parameter, int vehicleID)
{
    // Prepare the SQL statement
    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, updateQuery.c_str(), -1, &statement, nullptr);

    // Check if the statement was prepared successfully
    if (result == SQLITE_OK)
    {
        // Bind the string parameter to the first placeholder in the statement
        sqlite3_bind_text(statement, 1, parameter.c_str(), -1, SQLITE_STATIC);
        // Bind the vehicle ID parameter to the second placeholder in the statement
        sqlite3_bind_int(statement, 2, vehicleID);

        // Execute the prepared statement
        ExecuteUpdateStatement(statement);
    }
    else
    {
        // Log an error message if preparing the statement failed
        wxLogError("Error preparing update statement: %s", sqlite3_errmsg(dataBase));
    }
}

// Helper function for executing update queries with integer parameters
void DataBaseConnector::ExecuteUpdateIntParameter(const std::string& updateQuery, int parameter, int vehicleID)
{
    // Prepare the SQL statement
    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, updateQuery.c_str(), -1, &statement, nullptr);

    // Check if the statement was prepared successfully
    if (result == SQLITE_OK)
    {
        // Bind the integer parameter to the first placeholder in the statement
        sqlite3_bind_int(statement, 1, parameter);
        // Bind the vehicle ID parameter to the second placeholder in the statement
        sqlite3_bind_int(statement, 2, vehicleID);

        // Execute the prepared statement
        ExecuteUpdateStatement(statement);
    }
    else
    {
        // Log an error message if preparing the statement failed
        wxLogError("Error preparing update statement: %s", sqlite3_errmsg(dataBase));
    }
}

// Helper function for executing update statements
void DataBaseConnector::ExecuteUpdateStatement(sqlite3_stmt* statement)
{
    // Execute the prepared statement
    int result = sqlite3_step(statement);

    // Check if the execution was successful
    if (result != SQLITE_DONE)
    {
        // Log an error message if updating the vehicle field failed
        wxLogError("Error updating vehicle field: %s", sqlite3_errmsg(dataBase));
    }

    // Finalize the statement to release resources
    sqlite3_finalize(statement);
}

void DataBaseConnector::AddAdmin(Admin& admin)
{
    // SQLite query to insert a new record into the "Admin" table
    this->query = "INSERT INTO Admin (username, password) VALUES ('" +
        std::string(admin.getUsername().c_str()) + "', '" +
        std::string(admin.getPassword().c_str()) + "');";
    int result = sqlite3_exec(dataBase, query.c_str(), nullptr, nullptr, nullptr);

    if (result != SQLITE_OK)
    {
        wxLogError("Error adding admin: %s", sqlite3_errmsg(dataBase));
    }
    
}

void DataBaseConnector::UpdateVehicleId(int vehicleID, int newVehicleID)
{
    std::string updateQuery = "UPDATE Vehicle SET id = ? WHERE id = ?;";
    ExecuteUpdateIntParameter(updateQuery, newVehicleID, vehicleID);
}

std::vector<Admin> DataBaseConnector::GetAllAdmins()
{
    std::vector<Admin> admins;

    // SQLite query to select all records from the "Admin" table
    this->query = "SELECT * FROM Admin;";

    // Execute the query
    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, this->query.c_str(), -1, &statement, nullptr);

    if (result == SQLITE_OK)
    {
        // Fetch data from the result set
        while (sqlite3_step(statement) == SQLITE_ROW)
        {
            // Assuming you have a constructor in your Admin class that takes SQLite column values
            Admin admin{};

            // Set properties of the admin object based on the columns in the result set
            admin.setUsername(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0))));
            admin.setPassword(std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 1))));

            admins.push_back(admin);
        }

        // Finalize the statement
        sqlite3_finalize(statement);
    }
    else
    {
        wxLogError("Error getting admins");
    }

    return admins;
}
void DataBaseConnector::ExecuteUpdateDoubleParameter(const std::string& updateQuery, double parameter, int vehicleID)
{
    // Prepare the SQL statement
    sqlite3_stmt* statement;
    int result = sqlite3_prepare_v2(dataBase, updateQuery.c_str(), -1, &statement, nullptr);

    // Check if the statement was prepared successfully
    if (result == SQLITE_OK)
    {
        // Bind the double parameter to the first placeholder in the statement
        sqlite3_bind_double(statement, 1, parameter);
        // Bind the integer parameter to the second placeholder in the statement
        sqlite3_bind_int(statement, 2, vehicleID);

        // Execute the prepared statement
        ExecuteUpdateStatement(statement);
    }
    else
    {
        // Log an error message if preparing the statement failed
        wxLogError("Error preparing update statement: %s", sqlite3_errmsg(dataBase));
    }
}