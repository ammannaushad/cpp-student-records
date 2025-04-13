#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


enum gradeLevels {Freshman =1,Sophomore =2,Junior =3,Senior =4};



namespace StudentUtils {
    void formatName(string &name) {
    transform(name.begin(), name.end(), name.begin(), ::toupper);
}



string gradeName(gradeLevels level) {
    switch (level) {
    case Freshman: return "Freshman";
    case Sophomore: return "Sophomore";
    case Junior: return "Junior";
    case Senior: return "Senior";
    default: return "Error";
    }
}



void displayStudentInfo(const string &name, gradeLevels level, double gpa) {
    cout<< "Student Record";
    cout<< "Name" <<name<<endl;
    cout<< "Grade Level" <<gradeName(level)<<endl;
    cout<<fixed<<setprecision(2);
    cout<< "GPA" <<gpa<<endl;

    }
}


typedef gradeLevels Grade; 


int main () {
    string name;
    double GPA;
    int gradeInput;
    Grade Gradelevel;


cout<< "Enter the student name ";
cin.ignore();
getline(cin, name);



cout<< "Enter the grade level (1.Freshman, 2.Sophomore, 3.Junior, 4.Senior) ";
cin>> gradeInput;
Gradelevel = static_cast<gradeLevels>(gradeInput);


do {
cout<< "Enter GPA (0.00 - 4.00)";
cin>> GPA;

if (cin.fail() || GPA < 0.0 || GPA > 4.0) {
    cout<< "Error";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
} while (GPA < 0.0 || GPA > 4.0 || cin.fail());



StudentUtils::formatName(name);
StudentUtils::displayStudentInfo(name, Gradelevel, GPA);



return 0;
}