#include "auth.h"
#include <iostream>
#include "hash.h"
bool adminLogin() {
    std::string u, p;
    std::cout << "Admin Username: ";
    std::cin >> u;
    std::cout << "Password: ";
    std::cin >> p;
    return (u == "admin" && p == "admin123");
}

bool studentLogin(Database &db, int &roll) {
    std::string pass;
    std::cout << "Roll No: ";
    std::cin >> roll;
    std::cout << "Password: ";
    std::string raw;
    std::cin >> raw;
    pass = sha256(raw);


    std::string sql =
        "SELECT roll FROM students WHERE roll=" +
        std::to_string(roll) + " AND password='" + pass + "';";

    int found = 0;
    auto cb = [](void *f, int, char **, char **) {
        *(int *)f = 1;
        return 0;
    };

    sqlite3_exec(db.db, sql.c_str(), cb, &found, nullptr);
    return found;
}
