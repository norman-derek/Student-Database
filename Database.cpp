
#include "Database.h"

Database::Database(){
    masterStudent = new BST<Student*>();
    masterFaculty = new BST<Faculty*>();

}

Database::~Database(){
    delete masterStudent;
    delete masterFaculty;
}

void Database::addStudent(Student *student){
    if(student->getAdvisorID() == 0){
        masterStudent->insert(student);

    } else if(findFaculty(student->getAdvisorID()) == nullptr){
        cout << "please try inserting student with ID of advisor who exists!" << endl;

    } else {
        masterStudent->insert(student);
    }
    
}

void Database::addFaculty(Faculty *faculty){
    masterFaculty->insert(faculty);
}

void Database::deleteStudent(int id){
    Student *studentToDelete = new Student(id, "", "", "", 0.0, 0);
    masterStudent->deleteNode(studentToDelete);
    delete studentToDelete;
}

void Database::deleteFaculty(int id){
    Faculty *facultyToDelete = new Faculty(id, "", "", "", {});
    masterFaculty->deleteNode(facultyToDelete);
    delete facultyToDelete;
}

Student* Database::findStudent(int id){
    Student *studentToFind = new Student(id, "", "", "", 0.0, 0);
    studentToFind = masterStudent->contains(studentToFind);
    if(studentToFind != NULL){
        return studentToFind;
        //studentToFind->Print();
    } else {
        cout << "No student found with that ID!" << endl;
        return nullptr;
    }
    //return studentToFind;
    
}

Faculty* Database::findFaculty(int id){
    Faculty *facultyToFind = new Faculty(id, "", "", "", {});
    facultyToFind = masterFaculty->contains(facultyToFind);
    if(facultyToFind != NULL){
        return facultyToFind;
        //facultyToFind->Print();
    } else {
        cout << "No faculty found with that ID!" << endl;
        return nullptr;
    }

    //return facultyToFind;
}

void Database::printStudentDatabase(){
    masterStudent->printNodesInorder();
}

void Database::printFacultyDatabase(){
    masterFaculty->printNodesInorder();
}

void Database::printFacultyAdvisor(int studentID){
    Student *student = findStudent(studentID);
    Faculty *faculty = findFaculty(student->getAdvisorID());
    if(student == nullptr){
        cout << "No Student with ID " << studentID << " found" << endl;
        return;
    }
    if (faculty == nullptr) {
        cout << "Faculty advisor does not exist!" << endl;
        cout << "Please consider changing students advisor" << endl;

    } else {
        faculty->Print();
    }
    

}

void Database::printAdviseesOfFaculty(int facultyID){
    Faculty *faculty = findFaculty(facultyID);

    if(faculty == nullptr){
        cout << "Faculty advisor does not exis please try again!" << endl;
    } else {
        cout << "Advisees of " << faculty->getFacultyName() << ": " << endl;
        SingleLinkedList<int>* temp = faculty->getAdviseeList();
        ListNode<int>* curr = temp->getFront();
        while (curr != NULL){
            Student *s = findStudent(curr->data);
            if(s == nullptr){
                cout << "Student with ID '" << curr->data << "' not found." << endl; 
                curr = curr->next;
            } else {
                s->Print();

                curr = curr->next;
            }
        }

    }
}

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

void Database::removeAdvisee(int facultyID, int studentID){
    Faculty *faculty = findFaculty(facultyID);

    if(faculty == nullptr){
        cout << "Faculty with that ID does not exist..." << endl;
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

