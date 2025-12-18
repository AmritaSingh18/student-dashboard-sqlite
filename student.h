#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "database.h"

class Student {
public:
    int roll;
    std::string name, branch, password;
    float marks, attendance;

    void add(Database &db);
    void viewAll(Database &db);
    void viewOne(Database &db, int roll);
    void update(Database &db);
    void remove(Database &db, int roll);

};

#endif
