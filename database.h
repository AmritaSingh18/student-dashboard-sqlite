#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    sqlite3 *db;
    bool connect();
    void createTables();
    bool execute(std::string sql);
};

#endif
