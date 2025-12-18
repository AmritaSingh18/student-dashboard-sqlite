#include "student.h"
#include <iostream>
#include "hash.h"

static int callback(void *, int argc, char **argv, char **col) {
    for (int i = 0; i < argc; i++)
        std::cout << col[i] << ": " << argv[i] << "\n";
    std::cout << "------------------\n";
    return 0;
}

void Student::add(Database &db) {
    std::cout << "Roll: "; std::cin >> roll;
    std::cin.ignore();
    std::cout << "Name: "; getline(std::cin, name);
    std::cout << "Branch: "; getline(std::cin, branch);
    std::cout << "Marks: "; std::cin >> marks;
    std::cout << "Attendance: "; std::cin >> attendance;
    std::string raw;
    std::cout << "Password: ";
    std::cin >> raw;
    password = sha256(raw);


    std::string sql = "INSERT INTO students VALUES(" +
        std::to_string(roll) + ",'" + name + "','" +
        branch + "'," + std::to_string(marks) + "," +
        std::to_string(attendance) + ",'" + password + "');";

    db.execute(sql);
}

void Student::viewAll(Database &db) {
    std::string sql = "SELECT roll,name,branch,marks,attendance FROM students;";
    sqlite3_exec(db.db, sql.c_str(), callback, 0, nullptr);
}

void Student::viewOne(Database &db, int r) {
    std::string sql = "SELECT roll,name,branch,marks,attendance FROM students WHERE roll=" +
                      std::to_string(r) + ";";
    sqlite3_exec(db.db, sql.c_str(), callback, 0, nullptr);
}
void Student::update(Database &db) {
    int r;
    std::cout << "Enter Roll to Update: ";
    std::cin >> r;
    std::cin.ignore();

    std::cout << "New Name: ";
    getline(std::cin, name);
    std::cout << "New Branch: ";
    getline(std::cin, branch);
    std::cout << "New Marks: ";
    std::cin >> marks;
    std::cout << "New Attendance: ";
    std::cin >> attendance;

    std::string sql =
        "UPDATE students SET "
        "name='" + name + "', "
        "branch='" + branch + "', "
        "marks=" + std::to_string(marks) + ", "
        "attendance=" + std::to_string(attendance) +
        " WHERE roll=" + std::to_string(r) + ";";

    if (db.execute(sql))
        std::cout << "Student Updated Successfully\n";
}
void Student::remove(Database &db, int r) {
    std::string sql =
        "DELETE FROM students WHERE roll=" + std::to_string(r) + ";";

    if (db.execute(sql))
        std::cout << "Student Deleted Successfully\n";
}
