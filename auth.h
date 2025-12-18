#ifndef AUTH_H
#define AUTH_H

#include "database.h"

bool adminLogin();
bool studentLogin(Database &db, int &roll);

#endif
