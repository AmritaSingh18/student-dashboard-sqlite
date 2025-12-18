#include <iostream>
#include "database.h"
#include "student.h"
#include "auth.h"

int main() {
    Database db;
    db.connect();
    db.createTables();

    Student s;
    int choice;

    std::cout << "\n1. Admin Login\n2. Student Login\nChoice: ";
    std::cin >> choice;

    if (choice == 1 && adminLogin()) {
    int op;
    std::cout <<
    "\n1. Add Student"
    "\n2. View All Students"
    "\n3. Update Student"
    "\n4. Delete Student"
    "\nChoice: ";
    std::cin >> op;

    if (op == 1) s.add(db);
    else if (op == 2) s.viewAll(db);
    else if (op == 3) s.update(db);
    else if (op == 4) {
        int r;
        std::cout << "Enter Roll to Delete: ";
        std::cin >> r;
        s.remove(db, r);
    }
}

    return 0;
}
