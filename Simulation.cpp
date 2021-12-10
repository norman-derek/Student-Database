/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Simulation class, simple class representing a simple simulation 
*/
#include "Simulation.h"

Simulation::Simulation(){ //constructor
    db = new Database();
}

Simulation::~Simulation(){ //destructor
    delete db;
}

/*
*Method runSimulation, runs a simulation and simulates a student database
*/
void Simulation::runSimulation(){ // runs the simulation

    string input;
    while (input != "14"){
        //prompt the user for their choice
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
        
        cin >> input;  //takes user choice  

        if(input == "1"){ //if user choice is equal to 1
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Print All student and the information (sorted by ascending id #)" << endl;
            db->printStudentDatabase(); // prints the student table by ascending id #

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
            
        } else if (input == "2"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Print all faculty and their information (sorted by ascending id #)" << endl;
            db->printFacultyDatabase(); // prints the faculty table by ascending id #

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "3"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Find and display student information given the students id" << endl;
            cout << "Please provide id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){ //if the id is a valid integer 
                if(db->findStudent(stol(id)) == nullptr){ //check if the student exists
                    cout << "Sorry no student found with that ID" << endl; //student does not exist
                } else {
                    db->findStudent(stol(id))->Print(); //Print students information
                }
            } else { //Input ID is not valid
                cout << "Not a valid id!" << endl;
                cout << "Please try again with a valid id..." << endl;
            }
            

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "4"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Find and display faculty information given the faculty id" << endl;
            cout << "Please input faculty id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){
                if(db->findFaculty(stol(id)) == nullptr){ //check if faculty memeber exists
                    cout << "Sorry no student found with that ID" << endl; //faculty member does not exist
                } else {
                    db->findFaculty(stol(id))->Print(); //Print faculty member and information
                }
            } else { //input ID is not valid
                cout << "Not a valid id!" << endl;
                cout << "Please try again with a valid id..." << endl;
            }

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "5"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Given a student's id, print the name and information of their faculty advisor" << endl;
            cout << "Please provide student id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){ //if the input id is an integer 
                if(db->findStudent(stol(id)) == nullptr){ // if the student exists 
                    cout << "Sorry no student found with that ID" << endl; //student does not exist
                } else if (db->findFaculty(db->findStudent(stol(id))->getAdvisorID()) == nullptr ){ // if the faculty exists
                    cout << "Sorry the faculty member the student has listed does not exist!" << endl; //faculty does not exist

                } else { //student and faculty both exist
                    db->printFacultyAdvisor(stol(id)); //print the faculty advisor of the student
                }
            } else { //input ID is not a valid integer
                cout << "Invalid ID, Please try again..." << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "6"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "given a faculty id, print ALL the names and information of his/her advisees" << endl;
            cout << "Please provide faculty id: ";
            string id;
            cin >> id;
            cout << endl;
            if(isInteger(id)){ // if input id is a valid integer
                if(db->findFaculty(stol(id)) == nullptr){ //if the faculty member exists
                    cout << "Faculty with that ID not found, please try again..." << endl; //faculty member does not exist
                } else {
                    db->printAdviseesOfFaculty(stol(id)); //print advisee list of the faculty member
                }
            } else { //input is not a valid integer 
                cout << "Invalid ID, Please try again..." << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "7"){
            cout << string (50, '\n'); //clears the rest of the screen on terminal to focus on current selection
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

            if(isInteger(id) && isInteger(advisorID)){ //if input id is a valid integer and input advisorID is a valid integer
                Student *newStudent = new Student(stol(id), name, level, major, gpa, stol(advisorID)); //create new student

                db->addStudent(newStudent); //add student to student table
            } else { //if student id or advisor id is not a valid integer
                cout << "STUDENT NOT CREATED!!!!" << endl << "Please try again, invalid ID input" << endl;
            }

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
            
        } else if (input == "8"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Delete a student given the id" << endl;
            cout << "Please input student id: ";
            string id;
            cin >> id;
            cout << endl;

            if (isInteger(id)){ //if input id is a valid integer
                if(db->findStudent(stol(id)) == nullptr){ // if the student with id exists
                    cout << "Student with that ID does not exist!" << endl; //student does not exist
                } else {
                    db->deleteStudent(stol(id)); //student exists and deletes student from student table
                }
            } else { //input ID is not a valid ID
                cout << "Invalid ID, please try again..." << endl;
            }
            

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if(input == "9") { // if their option is 9
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
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


            int adviseeID; //will be used to create advisee id list
            SingleLinkedList<int>* adviseeIDList = new SingleLinkedList<int>(); //creates advisee id list for faculty member

            if(!adviseeList.empty()){ //this takes string of advisee id split up by spaces and adds the ids to the advisee list
                string word;
                for(int i = 0; i < adviseeList.length(); ++i){ //loops through the input id for the advisee list
                    if(!isspace(adviseeList[i])){ //add each character to a word because overall word will be the complete id
                        word += adviseeList[i];
                    } else { //on white space add the ID to the advisee id list
                        adviseeID = stol(word);
                        adviseeIDList->insertFront(adviseeID);
                        word = "";
                    }
                }

                adviseeID = stol(word);
                adviseeIDList->insertFront(adviseeID); //insert id into list
            }

            ListNode<int>* curr = adviseeIDList->getFront();
            for(int i = 0; i < adviseeIDList->getSize(); ++i){ //makes sure the student exists and if they dont removing them from the advisee list
                if(db->findStudent(curr->data) == nullptr){//if the student ecists
                    cout << "Student " << curr->data << " does not exist and cannot add that student into advisee list" << endl; 
                    adviseeIDList->removeNode(curr->data); //student doesnt exist in the student table so we remove the ID from advisee id list
                } 

                curr = curr->next;
            }

            if (isInteger(id)){ // if id is a valid integer
                Faculty *f = new Faculty(stol(id), name, level, department, adviseeIDList); //create new faculty member

                db->addFaculty(f); // add faculty member to faculty table

            } else { //if input id is not a valid id
                cout << "FACULTY NOT CREATED!!!!" << endl; //faculty member not created and tells user to try again
                cout << "Please try again and make sure you correctly input information" << endl;
            }
            

            cout << "Press any key to continue..." << endl;
            cin.ignore();

        } else if (input == "10") { //if input is equal to 10
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Delete a faculty member given the id" << endl;
            cout << "Please input faculty id: ";
            string id;
            cin >> id;
            cout << endl;

            if (isInteger(id)){ // if input id is a valid integer 
                if(db->findFaculty(stol(id)) == nullptr){ //if faculty exists
                    cout << "Faculty with that ID does not exist!" << endl; //faculty does not exist
                } else {
                    db->deleteFaculty(stol(id)); //faculty exists and delete faculty from faculty table
                }
            } else { //if input id is not a valid integer
                cout << "Invalid ID, please try again..." << endl;
            }
            

            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();

        } else if (input == "11"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Change a student's advisor given the student id and the new faculty id" << endl;
            cout << "Please input student ID: ";
            string studentID;
            cin >> studentID;
            cout << "Please input faculty ID: ";
            string facultyID;
            cin >> facultyID;
            cout << endl;

            if (isInteger(studentID) && isInteger(facultyID)){ //if student id and faculty id are both valid ids
                if(db->findStudent(stoi(studentID)) == nullptr){ // if student exists
                    cout << "Student not found please try again..." << endl; //student doesn't exist
                } else { //student exists
                    db->changeStudentsAdvisor(stoi(studentID), stoi(facultyID)); //student exists and we change students advisor
                }
            } else { //one or both of input ids were not a valid integer
                cout << "Invalid ID input for one of the two. Please try again..." << endl;
            }

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();

        } else if (input == "12"){
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Remove an advisee from a faculty member given the ids" << endl;
            cout << "Please input faculty ID: ";
            string facultyID;
            cin >> facultyID;
            cout << "Please input student ID: ";
            string studentID;
            cin >> studentID;
            cout << endl;

            if(isInteger(facultyID) && isInteger(studentID)){ // check if faculty id and student id are valid ids
                if(db->findFaculty(stoi(facultyID)) == nullptr){ //check if faculty exists
                    cout << "Faculty not found please try again..." << endl; //faculty doesn't exist
                } else { //faculty exists
                    if(db->findStudent(stoi(studentID)) == nullptr){ //check if student exists
                        cout << "Student does not exist, cannot remove from faculty advisee list" << endl; //student does not exist
                    } else { //student exists
                        db->removeAdvisee(stoi(facultyID), stoi(studentID)); //removes the advisee from the faculty and updates student and faculty variables appropriatley 
                    }

                }
            } else { //one or both provided ids were not a valid integer
                cout << "Invalid ID input for one of the two. Please try again..." << endl;
            }

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "13"){ // rollback option is chosen
            cout << string(50, '\n'); //clears the rest of the screen on terminal to focus on current selection
            cout << "Oops rollback currently does not work :(" << endl;
            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        } else if (input == "14"){ // option 14 is chosen which exits the simulation
            cout << "exiting..." << endl;
        } else {
            cout << "Sorry you did not choose a valid choice please try again!" << endl;

            cout << endl << "Press any key to continue..." << endl;
            cin.ignore();
            cin.ignore();
        }
    }


}


/*
* Method isInteger, checks if a string can be converted into an integer
* Takes single parameter, s, of type string representing the string to be checked
* Returns bool representing whether or not the string is an integer
*/
bool Simulation::isInteger(string s){
    string num = s;
    for(int i = 0; i < num.size(); ++i){
        if(!isdigit(num[i])){
            return false;
        }
    }

    return true;

}

//idk yet
void Simulation::fileProcessor(string studentFile, string facultyFile){
    
    ifstream studentTable;
    ifstream facultyTable;
    //idk really 
}