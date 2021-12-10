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
#include "Database.h"

Database::Database(){ //constructor
    masterStudent = new BST<Student*>();
    masterFaculty = new BST<Faculty*>();

}

Database::~Database(){ //destructor
    delete masterStudent;
    delete masterFaculty;
}

/*
* method addStudent, adds a student to the student table
* Takes single parameter student, representing the student going to be added
*/
void Database::addStudent(Student *student){
    if(student->getAdvisorID() == 0){ //insert student without advisor incase no advisors are in table yet
        masterStudent->insert(student);

    } else if(findFaculty(student->getAdvisorID()) == nullptr){ //if the faculty advisor does not exist
        cout << "please try inserting student with ID of advisor who exists!" << endl; //cout error

    } else { //faculty advisor exists
        masterStudent->insert(student); //add the student 
        if(student->getAdvisorID() != 0){ //this loop makes sure to add the students ID to the list of advisees for their advisor
            Faculty *f = findFaculty(student->getAdvisorID());
            f->getAdviseeList()->insertFront(student->getID()); //add student ID to faculy advisee list
        }
    }
    
}

/*
* method addFaculty, adds a faculty member to the faculty table
* Takes single parameter faculty, representing the faculty member going to be added
*/
void Database::addFaculty(Faculty *faculty){
    masterFaculty->insert(faculty); //adds faculty member to faculty table
}

/*
* method deleteStudent, deletes a student from the student table
* Takes a single parameter id, of type int representing the id of the student to be deleted
*/
void Database::deleteStudent(int id){
    Student *studentToDelete = new Student(id, "", "", "", 0.0, 0); //copy of student they want to delete 
    masterStudent->deleteNode(studentToDelete); //deletes the student if found
    delete studentToDelete;
}

/*
* method deleteFaculty, deleted a faculty member from the faculty table
* Takes a single parameter id, of type int representing the id of the faculty to be deleted 
*/
void Database::deleteFaculty(int id){
    Faculty *facultyToDelete = new Faculty(id, "", "", "", {});
    masterFaculty->deleteNode(facultyToDelete); //delete faculty if they are found
    delete facultyToDelete;
}

/*
* method findStudent, finds a student given the student id
* Takes single parameter, id, of type int representing the id of the student
* Returns Student* representing the student that was found or null if no student was found
*/
Student* Database::findStudent(int id){
    Student *studentToFind = new Student(id, "", "", "", 0.0, 0);
    studentToFind = masterStudent->contains(studentToFind); //see if the student to find exists
    if(studentToFind != NULL){ //student exists
        return studentToFind; //return student
    } else { //student does not exist
        cout << "No student found with that ID!" << endl; 
        return nullptr; //return null
    }
    
}

/*
* method findFaculty, finds a faculty member given the faculty id
* Takes single parameter, id, of type int representing the id of the faculty member
* Returns Faculty* representing the faculty that was found or null if no faculty was found
*/
Faculty* Database::findFaculty(int id){ //find a faculty member
    Faculty *facultyToFind = new Faculty(id, "", "", "", {});
    facultyToFind = masterFaculty->contains(facultyToFind); //see if the faculty member exists
    if(facultyToFind != NULL){ //if they exist
        return facultyToFind; //return the faculty member
    } else { //if they do not exist
        cout << "No faculty found with that ID!" << endl;
        return nullptr; //return null
    }

}

/*
* method printStudentDatabase, prints a visual representation of the student table 
*/
void Database::printStudentDatabase(){ 
    masterStudent->printNodesInorder();
}

/*
* method printFacultyDatabase, prints a visual representation of the faculty table
*/
void Database::printFacultyDatabase(){
    masterFaculty->printNodesInorder();
}

/*
* method printFacultyAdvisor, prints the advisor of a student given the student id
* Takes single parameter studentID, of type int representing the id of the student
*/
void Database::printFacultyAdvisor(int studentID){
    Student *student = findStudent(studentID); //find student
    Faculty *faculty = findFaculty(student->getAdvisorID()); //find advisor
    if(student == nullptr){ //if student does not exist
        cout << "No Student with ID " << studentID << " found" << endl;
        return; //return nothing
    }
    if (faculty == nullptr) { //if faculty advisor does not exist
        cout << "Faculty advisor does not exist!" << endl;
        cout << "Please consider changing students advisor" << endl;

    } else { //else if student and faculty advisor exist then print the faculty advisor
        faculty->Print();
    }
    

}

/*
* method printAdviseesOfFaculty, prints the list of advisees for a faculty member given the faculty id
* Takes single parameter facultyID, of type int representing the faculty members id
*/
void Database::printAdviseesOfFaculty(int facultyID){
    Faculty *faculty = findFaculty(facultyID); //find faculty from id

    if(faculty == nullptr){ //if faculty does not exist
        cout << "Faculty advisor does not exis please try again!" << endl;
    } else { // if faculty does exist, then print the list of advisees
        cout << "Advisees of " << faculty->getFacultyName() << ": " << endl;
        SingleLinkedList<int>* temp = faculty->getAdviseeList();
        ListNode<int>* curr = temp->getFront();
        while (curr != NULL){
            Student *s = findStudent(curr->data);
            if(s == nullptr){ //if the faculty members advisee does not exist in student table
                cout << "Student with ID '" << curr->data << "' not found." << endl; 
                curr = curr->next;
            } else { //if student in advisee list doest exist
                s->Print(); //print the student information

                curr = curr->next;
            }
        }

    }
}

/*
* method changeStudentsAdvisor, changes the students advisor given the student ID and the new advisor id
* Takes two parameters, studentID representing the id of the student, facultyID representing the id of the new faculty member to be used as advisor.
*/
void Database::changeStudentsAdvisor(int studentID, int facultyID){
    Student *student = findStudent(studentID);

    if(student == nullptr){
        cout << "Student with that ID does not exist..." << endl;
    } else {
        Faculty *faculty = findFaculty(facultyID);
        if(faculty == nullptr){
            cout << "Cannot change students advisor ID because a Faculty member with " << facultyID << " does not exist" << endl;
        } else {
            student->setAdvisorID(facultyID);
            faculty->getAdviseeList()->insertFront(studentID);
        }
    }
}

/*
* method removeAdvisee, removes an advisee from a faculty advisee id list given the faculty id and student id
* Takes two parameters, facultyID representing the id of the faculty member, studentID representing the id to remove from the faculty members advisee id list.
*/
void Database::removeAdvisee(int facultyID, int studentID){
    Faculty *faculty = findFaculty(facultyID);

    if(faculty == nullptr){
        cout << "Faculty with that ID does not exist..." << endl; ///
    } else {
        Student *student = findStudent(studentID);
        if(student == nullptr){
            cout << "Cannot remove advisee because the student does not exist in database" << endl;
        } else {
            faculty->getAdviseeList()->removeNode(studentID);
            student->setAdvisorID(0);
        }
    }
}

