compile: UnsortedListDriver

UnsortedListDriver: UnsortedList.o Student.o UnsortedListDriver.cpp
	g++ -Wall  -g -o UnsortedListDriver UnsortedList.o UnsortedListDriver.cpp

UnsortedList.o: UnsortedList.cpp UnsortedList.h
	g++ -Wall -c -std=c++14 -O0 -pedantic-errors -g UnsortedList.cpp

Student.o: Student.cpp Student.h
	g++ -Wall -c -std=c++14 -O0 -pedantic-errors -g Student.cpp

run:
	./UnsortedListDriver

clean:
	/bin/rm *.o UnsortedListDriver
