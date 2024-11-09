#ifndef A4_BIRTHDAYLIB_HPP
#define A4_BIRTHDAYLIB_HPP

#include <string>
using namespace std;


typedef struct {
    short year;
    short month;
    short day;
    string name;
    string knownFor;
} Birthday;
















Birthday* create_Birthday(short year, short month, short day,
                            string name, string knownFor);







void delete_Birthday(Birthday* person);





int compareBirthdaysByMD(const Birthday* p1, const Birthday* p2);

#endif