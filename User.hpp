// #pragma once
#include "Common.hpp"

class User {
protected:
    std::string id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(const std::string& id, const std::string& name, 
         const std::string& email, const std::string& password);
    virtual ~User() = default;
    virtual std::string getRole() const = 0;
    const std::string& getId() const;
    const std::string& getName() const;
    bool authenticate(const std::string& inputPassword) const;
};
