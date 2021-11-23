#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>

using namespace std;

class Faculty {
    private:
        int m_facultyID; //holds the faculty ID
        string m_name; //name of the faculty
        string m_level; //contains information if the person is a lecturer, assistant prof, associate prof, etc
        string m_department; //department the faculty works in
        int *m_adviseeIDList; //list of advisees IDs
    public:
        Faculty(); //constructor
        Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment, int *adviseeList); //overloaded constructor
        ~Faculty();
        equalTo(Faculty *other); //compares two faculty IDs to see if they are equal
        lessThan(Faculty *other); //compares current faculty ID to other faculty ID to see if current is less than other ID
        greaterThan(Faculty *other); //compares current faculty ID to other Faculty ID to see if curren is greater than other ID
};

#endif