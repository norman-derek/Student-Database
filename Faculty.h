/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Faculty class representing a simple Faculty member in a database
*/
#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

class Faculty {
    private:
        int m_facultyID; //holds the faculty ID of the faculty member
        string m_name; //name of the faculty member
        string m_level; //contains information if the faculty member is a lecturer, assistant prof, associate prof, etc
        string m_department; //department the faculty member works in
        SingleLinkedList<int>* m_adviseeIDList; //list of advisees IDs 
    public:
        Faculty(); //constructor
        Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment, SingleLinkedList<int>* m_adviseeList); //overloaded constructor
        ~Faculty(); //destructor

        //getters and setters
        int getID(); //returns the faculty ID for the faculty member
        void setID(int id); //sets the faculty ID for the faculty member

        string getFacultyName(); //returns the name of the faculty member
        void setFacultyName(string facultyName); //sets the faculty members name

        string getFacultyLevel(); //returns the level of the faculty member
        void setFacultyLevel(string facultyLevel); //sets the faculty members level

        string getFacultyDepartment(); //returns the department the faculty member is a part of
        void setFacultyDepartment(string facultyDepartment); //sets the department of the faculty member

        SingleLinkedList<int>* getAdviseeList(); //gets the list of advisees for the faculty member
        void setAdviseeList(SingleLinkedList<int>* adviseeList); //sets the list of advisees for the faculty member

        //helper methods
        bool equalTo(Faculty *other); //compares two faculty IDs to see if they are equal
        bool lessThan(Faculty *other); //compares current faculty ID to other faculty ID to see if current is less than other ID
        bool greaterThan(Faculty *other); //compares current faculty ID to other Faculty ID to see if curren is greater than other ID

        void Print(); //prints visual representation of the faculty member 
};

#endif