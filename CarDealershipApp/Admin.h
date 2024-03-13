#pragma once
#include <string>

class Admin
{
private:
    std::string username;
    std::string password;

public:
    Admin();

    Admin(const std::string& username, const std::string& password);

    std::string getUsername() const;

    void setUsername(const std::string& newUsername);

    std::string getPassword() const;

    void setPassword(const std::string& newPassword);

};