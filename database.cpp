#include "database.h"
#include <iostream>

bool Database::connect() {
    if (sqlite3_open("dashboard.db", &db)) {
        std::cout << "Database connection failed\n";
        return false;
    }
    return true;
}

void Database::createTables() {
    std::string sql =
        "CREATE TABLE IF NOT EXISTS students ("
        "roll INTEGER PRIMARY KEY,"
        "name TEXT,"
        "branch TEXT,"
        "marks REAL,"
        "attendance REAL,"
        "password TEXT);";
    execute(sql);
}

bool Database::execute(std::string sql) {
    char *err;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &err) != SQLITE_OK) {
        std::cout << "SQL Error: " << err << "\n";
        sqlite3_free(err);
        return false;
    }
    return true;
}
