/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Student class representing a simple Student in a database
*/
#include "Student.h"

Student::Student(){ //constructor
    m_studentID = 0;
    m_name = "";
    m_level = "";
    m_major = "";
    m_GPA = 0.0;
    m_advisorID = 0;
}

Student::Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int advisorID){ //overloaded constructor
    m_studentID = studentID;
    m_name = studentName;
    m_level = studentLevel;
    m_major = studentMajor;
    m_GPA = studentGPA;
    m_advisorID = advisorID;
}

Student::~Student(){ //destructor

}

/*
* Method getID, gets the ID number of the student 
* returns an int representing the student ID
*/
int Student::getID(){
    return m_studentID;
}

/*
* method setStudentID, sets the students ID number
* Takes a single paramter ID representing the student ID to be set 
*/
void Student::setID(int id){
    m_studentID = id;
}

/*
* Method getStudentName, returns the name of the student
* returns a string representing the name of the student
*/
string Student::getStudentName(){
    return m_name;
}

/*
* Method setStudentName, sets the name of the student
* takes a single string parameter, studentName, representing the name of the student 
*/
void Student::setStudentName(string studentName){
    m_name = studentName;
}

/*
* Method getStudentLevel, returns the level of the student
* returns a string representing the level of the student
*/
string Student::getStudentLevel(){
    return m_level;
}

/*
* Method setStudentLevel, sets the level of the student
* Takes single string parameter, studentLevel, representing the level of the student
*/
void Student::setStudentLevel(string studentLevel){
    m_level = studentLevel;
}

/*
* Method getStudentMajor, returns the major of the student
* returns a string representing the major of the student
*/
string Student::getStudentMajor(){
    return m_major;
}

/*
* Method setStudentMajor, sets the students major
* takes a single parameter of type string, studentMajor, representing the major of the student
*/
void Student::setStudentMajor(string studentMajor){
    m_major = studentMajor;
}

/*
* Method getStudentGPA, returns the gpa of the student
* returns a double representing the gpa of the student 
*/
double Student::getStudentGPA(){
    return m_GPA;
}

/*
* Method setStudentGPA, sets the students gpa
* takes single parameter of type double, studentGPA, representing the students gpa
*/
void Student::setStudentGPA(double studentGPA){
    m_GPA = studentGPA;
}

/*
* Method getAdvisorID, returns the faculty ID of the students advisor
* returns an int representing the ID of the students advisor
*/
int Student::getAdvisorID(){
    return m_advisorID;
}

/*
* Method setAdvisorID, sets the students advisor ID
* takes a single parameter of type int, advisorID, representing the ID of the students advisor
*/
void Student::setAdvisorID(int advisorID){
    m_advisorID = advisorID;
}

/*
* method equalTo, checks if a student is equal to another student
* Takes single parameter other, representing the other student
* Returns a bool representing whether or not the students are equal 
*/
bool Student::equalTo(Student *other){
    if(m_studentID == other->getID()){
        return true;
    }

    return false;
}

/*
* method lessThan, checks if a student id is less than another students id
* Takes a single paramter other, representing the other student
* Returns a bool representing whether or not the students id is less than the other students id
*/
bool Student::lessThan(Student *other){
    if(m_studentID < other->getID()){
        return true;
    }

    return false;
}

/*
* method greaterThan, checks if a student id is greater than another students id
* Takes a single paramter other, representing the other student
* Returns a bool representing whether or not the students id is greater than the other students id
*/
bool Student::greaterThan(Student *other){
    if(m_studentID > other->getID()){
        return true;
    }

    return false;
}


/*
* method Print, prints a visual representation of the Student 
*/
void Student::Print(){
    cout << "[ Student Name: " << m_name << ", " << endl;
    cout << "Student ID: " << m_studentID << ", " << endl;
    cout << "Level: " << m_level << ", " << endl;
    cout << "Major: " << m_major << ", " << endl;
    cout << "GPA: " << m_GPA << ", " << endl;
    cout << "advisor ID: " << m_advisorID << " ], " << endl;
    cout << endl;
}
