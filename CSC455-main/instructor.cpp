
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <map>
#include <limits>
using namespace std;
map<string, bool> assignments;
map<string, map<string, bool>> gradebook;
map<string, vector<string>> instructor_courses;
void instructor_actions(string& assignment_created, string&assignment_name, bool&points, bool&grades, string&view_assigned, string&student_name, string&professer_name){
    
    bool view_assigned_courses = false;
    bool grades_check=false;
    bool assignment_created_check = false;
    bool points_check = false;

    
    do{
        if(assignment_created_check == false){
            cout << "What is the name of the assignment you would like to create?" << endl;

            
            getline(cin, assignment_created); 
        
            cout << "And how many points is this assignment worth? ";
            cin >> points;
        
            assignments[assignment_created] = points;
            assignment_created_check = true;
        }else{

        }
        
        
        if(grades_check == false){
            cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <--- clear leftover newline
                cout << "For which assignment would you like to enter grades for?" << endl;
                getline(cin, assignment_name); 

                cin.clear();
                cout << "For which student?";
                getline(cin, student_name); 

                cin.clear();
                cout << "What grade would you like to give?";
                cin >> grades;

                gradebook[assignment_name][student_name] = grades;
                grades_check = true;
        }else{

        }
        if(view_assigned_courses == false){
            cout<<"Would you like to view assigned courses?(Y/N)"<<endl;
            string input;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, input);
            if (input[0] == 'y' || input[0] == 'Y'){
                cout<<"For which professor would you like to view? Please enter their username\n";
                cin>>professer_name;
                cout << "\n" << professer_name << " is assigned to course(s): ";
                for (const string& cid : instructor_courses[professer_name]) {
                    cout << cid << " ";
                }
                cout << endl;
                view_assigned_courses = true;
            }
            else{
                view_assigned_courses = true;
                cout<<"Okay you have chosen not to view assigned courses";
            }

            
        }else{

        }
        
    }while((assignment_created_check && points_check && grades_check && view_assigned_courses) != true);
    return;
}

int main(){
    string uname;
    string fname;
    string lname;
    string dob;
    string course_id = "";
    string course_number = "";
    string course_description = "";
    string num_seats = "";
    string students_registered = "";
    string assigned_classes; 
    string professor_name;
    string assignment_name;
    string student_name;
    int grade;
    string assignment_created;
    bool points;
    bool grades;
    string view_assigned;
    
    //retrieve_credentials(uname, fname, lname, dob);
    instructor_actions( assignment_created, assignment_name, points, grades, view_assigned, student_name, professor_name);
    cout<<uname<<" "<<fname<<" "<<lname<<" "<<dob<<endl;
}
