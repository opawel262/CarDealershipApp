#include "Admin.h"

// Default constructor
Admin::Admin() {}

// Parameterized constructor
Admin::Admin(const std::string& username, const std::string& password)
    : username(username), password(password) {}

// Getter for username
std::string Admin::getUsername() const
{
    return username;
}

// Setter for username
void Admin::setUsername(const std::string& newUsername)
{
    username = newUsername;
}

// Getter for password
std::string Admin::getPassword() const
{
    return password;
}

// Setter for password
void Admin::setPassword(const std::string& newPassword)
{
    password = newPassword;
}
