#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
    private:
        int m_studentID; //holds the students student ID
        string m_name; //holds the students name
        string m_level; //level field, holds if the student is a freshman, sophmore, junior, or senior
        string m_major; //major of the student
        double m_GPA; //GPA of student
        int m_advisorID; //contains the faculty ID of the students advisor
    
    public:
        Student(); //constructor
        Student(int studentID, string studentName, string studentStanding, string studentMajor, double studentGPA, int advisorID); //overloaded constructor
        ~Student(); //destructor

        //getters and setters
        int getID(); //returns the students ID
        void setID(int id); // sets the students ID

        string getStudentName(); //returns the students name
        void setStudentName(string studentName); //sets the students name

        string getStudentLevel(); //returns the students level
        void setStudentLevel(string studentLevel); //sets the students level

        string getStudentMajor(); //returns the students major
        void setStudentMajor(string studentMajor); //sets the students major

        double getStudentGPA(); //returns the students GPA
        void setStudentGPA(double studentGPA); //sets the students GPA

        int getAdvisorID(); //returns the faculty ID of the students advisor
        void setAdvisorID(int advisorID); //sets the ID for the advisor of the Student

        //helper methods
        bool equalTo(Student *other); //compares two students to see if they are the same by comparing student ID
        bool lessThan(Student *other); //compares current students ID to another Students ID to see if the current students ID is less than the other student
        bool greaterThan(Student *other); //compares current students ID to another Students ID to see if the current students ID is greater than the other student

        void Print(); //prints visual representation of the student

};

#endif