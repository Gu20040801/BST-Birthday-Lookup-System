#include "a4_birthdayBST.hpp"



void print_options(){
    cout<< "Please enter number 1-6 for the following option then press enter:"<<endl;
    cout<< "1)To load a birthday file."<<endl;
    cout<< "2)To list birthdays sorted by Month-Day."<<endl;
    cout<< "3)To look up a birthday."<<endl;
    cout<< "4)To add a birthday."<<endl;
    cout<< "5)To save a birthday file."<<endl;
    cout<< "6)To terminate the program."<<endl;
    cout<< "Option: ";
    return;
}



int main(){
    int number = 0;
    short month, day, year;
    string line, filename, birthdayline, endline, name, knownfor;
    BirthdayBST* treeptr = new BirthdayBST();
    cout<< "+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<< "+++++++++++Famous Birthday Look Up System++++++"<<endl;
    cout<< "++++++++++++++++++++Andrew Gu++++++++++++++++++"<<endl;
    cout<< "++++++++++++++++++++301569350++++++++++++++++++"<<endl;
    cout<< "+++++++++++++++++andrew_gu@sfu.ca++++++++++++++"<<endl;
    cout<< "+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    while(number != 6){
        cout<< "Please enter number 1-5 for the following option then press enter:"<<endl;
        cout<< "1)To load a birthday file."<<endl;
        cout<< "2)To list birthdays sorted by Month-Day."<<endl;
        cout<< "3)To look up a birthday."<<endl;
        cout<< "4)To add a birthday."<<endl;
        cout<< "5)To save a birthday file."<<endl;
        cout<< "6)To terminate the program."<<endl;
        cout<< "Option: ";
        cin>> number;
        switch (number)
        {   
            case 0:{
                break;
            }
            case 1:{
                cout<< "Enter the full name of the birthday file (with extension):";
                cin>> filename;
                ifstream file;
                file.open(filename);
                if(!file.is_open()){
                    cout<< "Error in opening file, please try again."<<endl;
                    cout<< "==============================================="<<endl;
                    number = 0;
                    break;
                }
                if(treeptr!=nullptr){
                    delete treeptr;
                    treeptr = new BirthdayBST();
                }
                int lines1=0;
                string line1;
                short year1, month1, day1;
                string endline, name, knownfor,birthdayline;
                while (getline(file,line1)) {
                    lines1++;
                }
                cout << lines1/4 << " entries read." << endl;
                cout << "=================================================="<<endl;
                file.clear();
                file.seekg(0, ios::beg);
                for(int i = 0; i < lines1/4; i++) {
                    getline(file, birthdayline);
                    sscanf(birthdayline.c_str(), "%hd-%hd-%hd", &year1, &month1, &day1);
                    getline(file, name);
                    getline(file, knownfor);
                    getline(file,endline);
                    treeptr->insertNode(create_Birthday(year1, month1, day1, name, knownfor));
                }
    
                file.close();
                break;
            }
            case 2:{
                if(treeptr->getSize() == 0){
                    cout<<"Please load a file first.\n";
                    cout<< "==============================================="<<endl;
                    break;
                }
                treeptr->inOrderPrint(cout);
                break;
            }
            case 3:{
                if(treeptr->getSize() == 0){
                    cout<<"Please load a file first.\n";
                    cout<< "==============================================="<<endl;
                    break;
                }
                cout << "What is the month?(input number 1-12 then press enter): ";
                cin >> month;
                cout<<"What is the day?(input number 1-31 then press enter): ";
                cin >> day;
                treeptr->printAllNodeWithMatchingMD(month, day, cout);
                break;
            }
            case 4:{
                if(treeptr->getSize() == 0){
                    cout<<"Please load a file first.\n";
                    cout<< "==============================================="<<endl;
                    break;
                }
                cout<<"What is the year?(input number then press enter): ";
                cin >> year;
                cout<<"What is the month?(input number 1-12 then press enter): ";
                cin >> month;
                cout<<"What is the day?(input number 1-31 then press enter): ";
                cin >> day;
                cin.ignore();
                cout<<"What is the the name of the person? ";
                getline(cin, name);
                cout<<"What is this person known for? ";
                getline(cin, knownfor);
                if(treeptr->findNodeByYMDN(year,month, day, name)== nullptr){
                    treeptr->insertNode(create_Birthday(year, month, day, name, knownfor));
                }
                break;
            }
            case 5:{
                if(treeptr->getSize() == 0){
                    cout<<"Please load a file first.\n";
                    cout<< "==============================================="<<endl;
                    break;
                }
                cout<<"Where do you want to save your entries? (enter the file name then press enter) ";
                cin >> filename;
                treeptr->savefile(filename);
                cout<< "==============================================="<<endl;
                break;
            }
            case 6:{
                cout<< "Thanks for using Famous Birthdays Lookup System!"<<endl;
                cout<< "==============================================="<<endl;
                treeptr->~BirthdayBST();
                delete treeptr;
                return 0;
            }
            default:{
                cout<< "Invalid number, please try again."<<endl;
                cout<< "==============================================="<<endl;
                number = 0;
                break;
            }
        }
    }
    return 0;
}