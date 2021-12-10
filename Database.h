/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Database class, simple representation of a database
*/
#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "bst.h"


class Database {
    public:
        Database(); // constructor
        ~Database(); //destructor
        void addStudent(Student *student); // adds student to student database
        void addFaculty(Faculty *faculty); // adds student to faculty database
        void deleteStudent(int id); //deletes student given the student ID
        void deleteFaculty(int id); // deletes faculty given the id
        Student* findStudent(int id); //find student and prints their information given id 
        Faculty* findFaculty(int id); //finds faculty and prints their information given id
        void printStudentDatabase(); // prints student database in ascending order by id
        void printFacultyDatabase(); // prints faculty database in ascending order by id
        void printFacultyAdvisor(int studentID); // given a students id it prints the name and info of their faculty advisor
        void printAdviseesOfFaculty(int facultyID); // given a faculty id it prints all the names and infor of his/her advisees 
        void changeStudentsAdvisor(int studentID, int facultyID); //change a students advisor given the student id and the new faculty id.
        void removeAdvisee(int facultyID, int studentID); //removes an advisee from a faculty member given the ids



    private:
        BST<Student*> *masterStudent;
        BST<Faculty*> *masterFaculty;


};

#endif