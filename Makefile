all:
	g++ main.cpp student.cpp database.cpp auth.cpp hash.cpp \
	-lsqlite3 -lssl -lcrypto -o dashboard

run:
	./dashboard

