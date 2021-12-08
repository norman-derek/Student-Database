#include "Simulation.h"

Simulation::Simulation(){
    db = new Database();
}

Simulation::~Simulation(){
    delete db;
}

void Simulation::runSimulation(){
    // Student *one = new Student(2364922, "Derek", "Sophmore", "Computer Science", 3.5, 425435);
    // Student *two = new Student(12275073, "Alexa", "Sophmore", "Mathematics", 3.0, 214);
    // Student *three = new Student(1, "Alexa", "Sophmore", "Mathematics", 3.0, 214);


    // SingleLinkedList<int> *adviseeList = new SingleLinkedList<int>();

    // adviseeList->insertFront(2364922);
    // adviseeList->insertFront(12275073);
    // adviseeList->insertFront(23423);
    // adviseeList->insertFront(3242345);

    // Faculty *fone = new Faculty(425435, "Dr. man", "Professor", "Mathematics", adviseeList);
    // Faculty *ftwo = new Faculty(214, "Professor Jipsen", "Assistant Professor", "Chemistry", adviseeList);



    // Database *test = new Database();

    // test->addFaculty(fone);
    // test->addFaculty(ftwo);

    // cout << "=============== Print Faculty Database =============" << endl;
    // test->printFacultyDatabase();

    // test->addStudent(one);
    // test->addStudent(two);
    // test->addStudent(three);

    // cout << "============= Print student database =========" << endl;
    // test->printStudentDatabase();

    // cout << "================= FIND STUDENT TEST =================" << endl;
    // test->findStudent(2364922);

    // cout << endl;
    // cout << "=============== FIND FACULTY TEST ==================" << endl;
    // test->findFaculty(425435);

    // cout << endl;
    // cout << "================ PRINT FACULTY ADVISOR TEST ==================" << endl;
    // test->printFacultyAdvisor(2364922);

    // cout << endl;
    // cout << "============== GET ADVISEE LIST TEST =============" << endl;
    // test->printAdviseesOfFaculty(425435);

    string input;
    while (input != "14"){
        cout << string(50, '\n');
        cout << "Hello Please Choose One Of The Options Below...(please input corresponding number from list)" << endl;
        cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
        cout << "3. Find and display student information given the students id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Given a student's id, print the name and information of their faculty advisor" << endl;
        cout << "6. given a faculty id, print ALL the names and information of his/her advisees" << endl;
        cout << "7. Add a new student" << endl;
        cout << "8. Delete a student given the id" << endl;
        cout << "9. Add a new faculty member" << endl;
        cout << "10. Delete a faculty member given the id" << endl;
        cout << "11. Change a student's advisor given the student id and the new faculty id" << endl;
        cout << "12. Remove an advisee from a faculty member given the ids" << endl;
        cout << "13. Rollback" << endl;
        cout << "14. Exit" << endl;
        
        cin >> input;        

        if(input == "1"){
            cout << string(50, '\n');
            cout << "Print All student and the information (sorted by ascending id #)" << endl;
            db->printStudentDatabase();

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
            
        } else if (input == "2"){
            cout << string(50, '\n');
            cout << "Print all faculty and their information (sorted by ascending id #)" << endl;
            db->printFacultyDatabase();

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "3"){
            cout << string(50, '\n');
            cout << "Find and display student information given the students id" << endl;
            cout << "Please provide id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){
                if(db->findStudent(stol(id)) == nullptr){
                    cout << "Sorry no student found with that ID" << endl;
                } else {
                    db->findStudent(stol(id))->Print();
                }
            } else {
                cout << "Not a valid id!" << endl;
                cout << "Please try again with a valid id..." << endl;
            }
            

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "4"){
            cout << string(50, '\n');
            cout << "Find and display faculty information given the faculty id" << endl;
            cout << "Please input faculty id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){
                if(db->findFaculty(stol(id)) == nullptr){
                    cout << "Sorry no student found with that ID" << endl;
                } else {
                    db->findFaculty(stol(id))->Print();
                }
            } else {
                cout << "Not a valid id!" << endl;
                cout << "Please try again with a valid id..." << endl;
            }

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "5"){
            cout << string(50, '\n');
            cout << "Given a student's id, print the name and information of their faculty advisor" << endl;
            cout << "Please provide student id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){
                if(db->findStudent(stol(id)) == nullptr){
                    cout << "Sorry no student found with that ID" << endl;
                } else if (db->findFaculty(db->findStudent(stol(id))->getAdvisorID()) == nullptr ){
                    cout << "Sorry the faculty member the student has listed does not exist!" << endl;

                } else {
                    db->printFacultyAdvisor(stol(id));
                }
            } else {
                cout << "Invalid ID, Please try again..." << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "6"){
            cout << string(50, '\n');
            cout << "given a faculty id, print ALL the names and information of his/her advisees" << endl;
            cout << "Please provide faculty id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){
                if(db->findFaculty(stol(id)) == nullptr){
                    cout << "Faculty with that ID not found, please try again..." << endl;
                } else {
                    db->printAdviseesOfFaculty(stol(id));
                }
            } else {
                cout << "Invalid ID, Please try again..." << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "7"){
            cout << string (50, '\n');
            cout << "Add a new student" << endl;

            string id;
            string name = "";
            string level = "";
            string major = "";
            double gpa;
            string advisorID;

            cout << "Please input student id: ";
            cin.ignore();
            cin >> id;
            cout << endl;
            cout << "Please input student name: ";
            cin.ignore();
            getline(cin, name);
            cout << endl;
            cout << "Please input student level: ";
            getline(cin, level);
            cout << endl;
            cout << "Please input student major: ";
            getline(cin, major);
            cout << endl;
            cout << "Please input gpa (with decimal): ";
            cin >> gpa;
            cout << endl;
            cout << "Please input 0 if student has no advisor" << endl;
            cout << "Please input advisor ID: ";
            cin.ignore();
            cin >> advisorID;
            cout << endl;

            if(isInteger(id)){
                Student *newStudent = new Student(stol(id), name, level, major, gpa, stol(advisorID));

                db->addStudent(newStudent);
            } else {
                cout << "STUDENT NOT CREATED!!!!" << endl << "Please try again, invalid ID input" << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
            
        } else if (input == "8"){
            cout << string(50, '\n');
            cout << "Delete a student given the id" << endl;
            cout << "Please input student id: ";
            string id;
            cin >> id;
            cout << endl;

            if (isInteger(id)){
                if(db->findStudent(stol(id)) == nullptr){
                    cout << "Student with that ID does not exist!" << endl;
                } else {
                    db->deleteStudent(stol(id));
                }
            } else {
                cout << "Invalid ID, please try again..." << endl;
            }
            

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if(input == "9") { // if their option is 9
            cout << string(50, '\n');
            cout << "Add a new faculty member" << endl; //add new faculty member
            cout << "Please input faculty ID: ";
            cin.ignore();
            string id;
            cin >> id;
            cout << endl;
            cout << "Please input name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            cout << endl;
            cout << "Please input Level: ";
            string level;
            getline(cin, level);
            cout << endl;
            cout << "Please input department: ";
            string department;
            getline(cin, department);
            cout << endl;
            cout << "Please input adviseeList seperated by spaces: ";
            string adviseeList;
            getline(cin, adviseeList);
            cout << endl;


            int adviseeID;
            SingleLinkedList<int>* adviseeIDList = new SingleLinkedList<int>();

            if(!adviseeList.empty()){ //this takes string of advisee id split up by spaces and adds the ids to the advisee list
                string word;
                for(int i = 0; i < adviseeList.length(); ++i){
                    if(!isspace(adviseeList[i])){
                        word += adviseeList[i];
                    } else {
                        adviseeID = stol(word);
                        adviseeIDList->insertFront(adviseeID);
                        word = "";
                    }
                }

                adviseeID = stol(word);
                adviseeIDList->insertFront(adviseeID);
            }

            ListNode<int>* curr = adviseeIDList->getFront();
            for(int i = 0; i < adviseeIDList->getSize(); ++i){ //makes sure the student exists in the student table before adding it to the advisee list
                if(db->findStudent(curr->data) == nullptr){
                    cout << "Student " << curr->data << " does not exist and cannot add that student into advisee list" << endl;
                    adviseeIDList->removeNode(curr->data);
                } else {
                    
                }

                curr = curr->next;
            }

            if (isInteger(id)){
                Faculty *f = new Faculty(stol(id), name, level, department, adviseeIDList);

                db->addFaculty(f);

            } else {
                cout << "FACULTY NOT CREATED!!!!" << endl;
                cout << "Please try again and make sure you correctly input information" << endl;
            }
            

            cout << "Press any key to continue..." << endl;
            cin.ignore();

        } else if (input == "10") {
            cout << string(50, '\n');
            cout << "Delete a faculty member given the id" << endl;
            cout << "Please input faculty id: ";
            string id;
            cin >> id;
            cout << endl;

            if (isInteger(id)){
                if(db->findFaculty(stol(id)) == nullptr){
                    cout << "Faculty with that ID does not exist!" << endl;
                } else {
                    db->deleteFaculty(stol(id));
                }
            } else {
                cout << "Invalid ID, please try again..." << endl;
            }
            

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();

        } else if (input == "11"){
            cout << string(50, '\n');
            cout << "Change a student's advisor given the student id and the new faculty id" << endl;
            cout << "Please input student ID: ";
            string studentID;
            cin >> studentID;
            cout << "Please input faculty ID: ";
            string facultyID;
            cin >> facultyID;
            cout << endl;

            if (isInteger(studentID) && isInteger(facultyID)){
                if(db->findStudent(stoi(studentID)) == nullptr){
                    cout << "Student not found please try again..." << endl;
                } else {
                    db->changeStudentsAdvisor(stoi(studentID), stoi(facultyID));
                }
            } else {
                cout << "Invalid ID input for one of the two. Please try again..." << endl;
            }

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();

        } else if (input == "12"){
            cout << string(50, '\n');
            cout << "Remove an advisee from a faculty member given the ids" << endl;
            cout << "Please input faculty ID: ";
            string facultyID;
            cin >> facultyID;
            cout << "Please input student ID: ";
            string studentID;
            cin >> studentID;
            cout << endl;

            if(isInteger(facultyID) && isInteger(studentID)){
                if(db->findFaculty(stoi(facultyID)) == nullptr){
                    cout << "Faculty not found please try again..." << endl;
                } else {
                    if(db->findStudent(stoi(studentID)) == nullptr){
                        cout << "Student does not exist, cannot remove from faculty advisee list" << endl;
                    } else {
                        db->removeAdvisee(stoi(facultyID), stoi(studentID));
                    }

                }
            } else {
                cout << "Invalid ID input for one of the two. Please try again..." << endl;
            }

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "13"){
            cout << string(50, '\n');
            cout << "Oops rollback currently does not work :(" << endl;
            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "14"){
            cout << "exiting..." << endl;
        } else {
            cout << "Sorry you did not choose a valid choice please try again!" << endl;

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        }
    }


}

bool Simulation::isInteger(string s){
    string num = s;
    for(int i = 0; i < num.size(); ++i){
        if(!isdigit(num[i])){
            return false;
        }
    }

    return true;

}