#include <filesystem>
#include <iostream>
#include <vector>

#include "mydb/table.h"
#include "mydb/user.h"

void runConsole() {
    const auto table_path = std::filesystem::path(__FILE__).parent_path() / "User.table";
    Table table(table_path.string());

    while (true) {
        std::cout << "\n=== User 表 ===\n";
        std::cout << "1. 添加用户\n";
        std::cout << "2. 查看所有用户\n";
        std::cout << "0. 退出\n";
        std::cout << "请选择操作：";

        int choice;
        if (!(std::cin >> choice)) {
            std::cerr << "输入无效，程序结束。\n";
            return;
        }

        if (choice == 0) {
            return;
        }

        if (choice == 1) {
            User user;

            std::cout << "请输入用户 ID：";
            if (!(std::cin >> user.id)) {
                std::cerr << "ID 输入无效。\n";
                return;
            }

            std::cout << "请输入用户名：";
            std::cin >> user.name;

            std::cout << "请输入年龄：";
            if (!(std::cin >> user.age)) {
                std::cerr << "年龄输入无效。\n";
                return;
            }

            if (table.appendUser(user)) {
                std::cout << "用户添加完成。\n";
            }
        } else if (choice == 2) {
            const std::vector<User> users = table.readAllUsers();

            if (users.empty()) {
                std::cout << "表中没有用户。\n";
                continue;
            }

            for (const User& user : users) {
                std::cout << "ID: " << user.id
                          << ", Name: " << user.name
                          << ", Age: " << user.age << '\n';
            }
        } else {
            std::cout << "没有这个选项，请重新选择。\n";
        }
    }
}

int main() {
    runConsole();
    return 0;
}
