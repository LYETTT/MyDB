#include "mydb/table.h"

#include <cstdint>
#include <fstream>
#include <iostream>

Table::Table(const std::string& path)
    : path_(path) {
}

bool Table::appendUser(const User& user) {
    //检查 id 是否重复
    auto exist_users=readAllUsers();
    for (const auto& existing_user : exist_users) {
        if (existing_user.id == user.id) {
            std::cerr<<"id 重复"<<std::endl;
            return false;
        }
    }

    std::ofstream file(path_, std::ios::binary | std::ios::app);

    if (!file.is_open()) {
        std::cerr << "无法打开表文件进行写入\n";
        return false;
    }

    const std::uint32_t name_size =user.name.size();

    file.write(reinterpret_cast<const char*>(&user.id), sizeof(user.id));
    file.write(reinterpret_cast<const char*>(&name_size), sizeof(name_size));
    file.write(user.name.data(), name_size);
    file.write(reinterpret_cast<const char*>(&user.age), sizeof(user.age));

    file.flush();
    if (!file) {
        std::cerr << "写入用户失败\n";
        return false;
    }
    return true;
}

std::vector<User> Table::readAllUsers() const {
    std::vector<User> users;
    std::ifstream file(path_, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "无法打开表文件进行读取\n";
        return users;
    }

    while (true) {
        User user;
        std::uint32_t name_size;

        if (!file.read(reinterpret_cast<char*>(&user.id), sizeof(user.id))) {
            break;
        }

        if (!file.read(reinterpret_cast<char*>(&name_size), sizeof(name_size))) {
            std::cerr << "读取 name_size 失败\n";
            return users;
        }

        user.name.resize(name_size);

        if (!file.read(user.name.data(), name_size)) {
            std::cerr << "读取 user.name 失败\n";
            return users;
        }

        if (!file.read(reinterpret_cast<char*>(&user.age), sizeof(user.age))) {
            std::cerr << "读取 user.age 失败\n";
            return users;
        }

        users.push_back(user);
    }

    file.close();

    return users;
}
