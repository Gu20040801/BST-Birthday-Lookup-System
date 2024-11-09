all: test1

test1: birthdayLookupSystem.cpp birthdaylib.cpp birthdayBST.cpp
	g++ -Wall -std=c++11 -o test1 birthdayLookupSystem.cpp birthdaylib.cpp birthdayBST.cpp

clean:
	rm -f test1
