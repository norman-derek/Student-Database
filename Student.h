#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
    private:
        int m_studentID; //holds the students student ID
        string m_name; //holds the students name
        string m_standing; //level field, holds if the student is a freshman, sophmore, junior, or senior
        string m_major; //major of the student
        double m_GPA; //GPA of student
        int m_advisorID; //contains the faculty ID of the students advisor
    
    public:
        Student(); //constructor
        Student(int studentID, string studentName, string studentStanding, string studentMajor, double studentGPA, int advisorID); //overloaded constructor
        ~Student(); //destructor
        bool equalTo(Student *other); //compares two students to see if they are the same by comparing student ID
        bool lessThan(Student *other); //compares current students ID to another Students ID to see if the current students ID is less than the other student
        bool greaterThan(Student *other); //compares current students ID to another Students ID to see if the current students ID is greater than the other student

};

#endif