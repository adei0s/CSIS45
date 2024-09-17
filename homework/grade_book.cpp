#include<iostream>
using namespace std;

int main() {

    cout << "==> Welcome to lazy grades!" << endl;

    // initializing variables
    char action;
    
    string names[100]; //add students, max capacity 100
    char grades[100]; 
    int student_count = 0;
    int student_add = 0;
    string input_name;
    char input_grade;

    int student_drop;       //drop student
    int student_lookup;     //look up student

    // while loop to allow repeat actions
    while (true) {

        // selecting user action
        cout << "---------------------------" << endl;
        cout << "==> Would you like to: \n"
                "[a] add students \n"
                "[b] drop students \n"
                "[c] look up a student by ID \n" 
                "[d] print student roster \n"
                "[e] exit" << endl;
        cin >> action;

        // if action == 'a', add student names and grade
        if (action == 'a') {

            cout << "==> How many students are being added? \n";
            cin >> student_add;

            // adding names and grades
            for (int i=student_count; i<(student_count + student_add); i++){
                cout << "==> Enter name for student ID " << i << endl;
                cin >> input_name;
                names[i] = input_name;
                cout << "==> Enter grade for " << input_name << endl;
                cin >> input_grade;
                grades[i] = input_grade;
            }
            student_count += student_add;
            cout << "==> Students added!" << endl;
        }

        // if action == 'b', drop student names and grade
        else if (action == 'b') {
            cout << "==> Enter ID to drop a student:" << endl;
            cin >> student_drop;
            names[student_drop] = "dropped";
            grades[student_drop] = 'X';
            cout << "==> Students dropped!" << endl;
        }

        // if action == 'c', look up student by ID
        else if (action == 'c') {
            cout << "==> Enter ID of the student to look up:" <<endl;
            cin >> student_lookup;
            cout << "==> student name: " << names[student_lookup] << endl;
            cout << "    student grade: " << grades[student_lookup] << endl;
        }
        
        // if action == 'd', print student roster 
        // i'm adding this option just so 'e' can stand for 'e'xit
        else if (action == 'd') {
            cout << "[student roster]" << endl;
            for (int i=0; i<student_count; i++) {
                cout << i << " - " << names[i] << " - "<< grades[i] << endl;
            }
        }

        // if action == 'e', exit program
        else if (action == 'e') {
            cout << "==> Thank you for using lazy grades. Goodbye!" << endl;
            cout << "---------------------------" << endl;
            break;
        }

        // input exceptions
        else {
            cout << "==> Not a valid input, please enter: a, b, c, d, or e." << endl;
        }
    }  
return 0;
}