#pragma once

#include <string>
#include <vector>

#include "mydb/user.h"

class Table {
public:
    explicit Table(const std::string& path);

    bool appendUser(const User& user);
    std::vector<User> readAllUsers() const;

private:
    std::string path_;
};
