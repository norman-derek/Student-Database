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
#include "Faculty.h"

Faculty::Faculty(){ //constructor
    m_facultyID = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    m_adviseeIDList = new SingleLinkedList<int>();
}

Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment, SingleLinkedList<int>* adviseeList){ //overloaded constructor
    m_facultyID = facultyID;
    m_name = facultyName;
    m_level = facultyLevel;
    m_department = facultyDepartment;
    if(adviseeList == NULL){
        m_adviseeIDList = new SingleLinkedList<int>();
    } else {
        m_adviseeIDList = adviseeList;
    }
}

Faculty::~Faculty(){
    delete m_adviseeIDList;
}

/*
* Method getFacultyID, returns the ID number for the faculty member
* returns an int representing the ID of the faculty member 
*/
int Faculty::getID(){
    return m_facultyID;
}

/*
* Method setFacultyID, sets the ID for the faculty member
* Takes single parameter of type int, id, representing the id of the faculty member
*/
void Faculty::setID(int id){
    m_facultyID = id;
}

/*
* Method getFacultyName, returns the name of the faculty member
* Returns a string representing the name of the faculty member
*/
string Faculty::getFacultyName(){
    return m_name;
}

/*
* Method setFacultyName, sets the name of the faculty member
* Takes single parameter of type string, facultyName, representing the name of the faculty member
*/
void Faculty::setFacultyName(string facultyName){
    m_name = facultyName;
}

/*
* Method getFacultyLevel, returns the level of the faculty member
* Returns a string representing the level of the faculty member
*/
string Faculty::getFacultyLevel(){
    return m_level;
}

/*
* Method setFacultyLevel, sets the level of the faculty member
* Takes a single parameter of type string, facultyLevel, representing the level of the faculty member 
*/
void Faculty::setFacultyLevel(string facultyLevel){
    m_level = facultyLevel;
}

/*
* Method getFacultyDepartment, returns the department of the faculty member
* Returns a string representing the department of the faculty member
*/
string Faculty::getFacultyDepartment(){
    return m_department;
}

/*
* Method setFacultyDepartment, sets the department of the faculty member
* Takes a single parameter of type string, facultyDepartment, representing the department of the faculty member
*/
void Faculty::setFacultyDepartment(string facultyDepartment){
    m_department = facultyDepartment;
}

/*
* Method getAdviseeList, returns the list of advisees for that the faculty member has
* Returns an int* representing the list of advisees that the faculty member has
*/
SingleLinkedList<int>* Faculty::getAdviseeList(){
    return m_adviseeIDList;
}

/*
* Method setAdviseeList, sets the advisee list for the faculty member
* Takes a single paramter of type int*, adviseeList, representing the list of advisees the faculty member has
*/
void Faculty::setAdviseeList(SingleLinkedList<int> *adviseeList){
    m_adviseeIDList = adviseeList;
}

/*
* method equalTo, checks if a faculty member is equal to another faculty member
* Takes single parameter other, representing the other faculty member
* Returns a bool representing whether or not the faculty members are equal 
*/
bool Faculty::equalTo(Faculty *other){
    if(m_facultyID == other->getID()){ //compares ID of the faculty and if the same it returns true
        return true;
    }

    return false;
}

/*
* method lessThan, checks if a faculty ID is less than another faculty ID
* Takes single parameter other, representing the other faculty member
* Returns a bool representing whether or not the faculty member id is less than the other faculty members
*/
bool Faculty::lessThan(Faculty *other){
    if(m_facultyID < other->getID()){ //compares IDs of the faculty and if the current object id is less than the other id then it returns true
        return true;
    }

    return false;
}

/*
* method greaterThan, checks if a faculty ID is greater than another faculty ID
* Takes single parameter other, representing the other faculty member
* Returns a bool representing whether or not the faculty member id is greater than the other faculty members
*/
bool Faculty::greaterThan(Faculty *other){ 
    if(m_facultyID > other->getID()){ //compares ids of the faculty and if the current Faculty ID is greater than the other faculty ID and if it is returns true 
        return true;
    }

    return false;
}

/*
* method Print, prints a visual representation of the Faculty
*/
void Faculty::Print(){
    cout << "Faculty [" << endl;
    cout << "Name: " << m_name << endl;
    cout << "ID: " << m_facultyID << endl;
    cout << "Level: " << m_level << endl;
    cout << "Department: " << m_department << endl;
    cout << "Advisee ID list: ";
    if(m_adviseeIDList->isEmpty()){
        cout << "" << endl;
    } else {
        m_adviseeIDList->printList();
    }
    cout << "] " << endl;
}