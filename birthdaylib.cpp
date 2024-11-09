#include "a4_birthdayBST.hpp"


Birthday* create_Birthday(short year, short month, short day, string name, string knownFor){
    Birthday* person = new Birthday;
    
        person->year = year;
        person->month = month;
        person->day = day;
        person->name = string(name); 
        person->knownFor = string(knownFor);
    
    return person;
}
void delete_Birthday(Birthday* person){
    if (person != nullptr) { 
        person->year = -1;
        person->month = -1;
        person->day = -1;
        person->name = nullptr;
        person->knownFor = nullptr;
        delete person;
        person = nullptr;
    }
}



int compareBirthdaysByMD(const Birthday* p1, const Birthday* p2){
    if(p1->month == p2->month){  
        return (p1->day - p2->day); 
    }
    else{ 
        return (p1->month - p2->month); 
    }
}
