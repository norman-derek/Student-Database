#include "Student.h"

Student::Student(){ //constructor
    m_studentID = 0;
    m_name = "";
    m_standing = "";
    m_major = "";
    m_GPA = 0.0;
    m_advisorID = 0;
}

Student::Student(int studentID, string studentName, string studentStanding, string studentMajor, double studentGPA, int advisorID){ //overloaded constructor
    m_studentID = studentID;
    m_name = studentName;
    m_standing = studentStanding;
    m_major = studentMajor;
    m_GPA = studentGPA;
    m_advisorID = advisorID;
}

Student::~Student(){ //destructor

}

