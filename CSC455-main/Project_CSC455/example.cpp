#include <iostream>
#include <fstream>
#include "globals.h"
#include <filesystem>

using namespace std;

bool check_char(string& word) {
    for (char c : word)
        if (!isalpha(c)) return false;
    return true;
}

bool check_date(string& dob) {
    return dob.size() == 10 && isdigit(dob[0]);
}

void save_to_file_student(const string& uname, const string& fname, const string& lname, const string& dob) {
    ofstream outfile("students.txt", ios::app);
    
    int random_id = rand() % 10000;
    if (outfile.is_open()) {
        outfile << "Student " << random_id << "\n";
        outfile <<"\tUser Name: "<< uname << "\n" <<"\tFirst Name: "<< fname << "\n" <<"\tLast Name: "<< lname << "\n" << "\tDate of birth: \n"<<dob << "Grades:"<<'\n' <<"----------------------------------------\n\n";
        outfile.flush();  
        outfile.close();
    }
}
void save_to_file_admin(const string& uname, const string& fname, const string& lname, const string& dob) {
    ofstream outfile("administrator.txt", ios::app);
    int random_id = rand() % 10000;
    if (outfile.is_open()) {
        outfile << "Student " << random_id << "\n";
        outfile <<"\tUser Name: "<< uname << "\n" <<"\tFirst Name: "<< fname << "\n" <<"\tLast Name: "<< lname << "\n" << "\tDate of birth: \n"<<dob << '\n' <<"----------------------------------------\n\n";
        outfile.close();
    }   
}
void save_to_file_instructor(const string& uname, const string& fname, const string& lname, const string& dob) {
    ofstream outfile("instructor.txt", ios::app);
    int random_id = rand() % 10000;
    if (outfile.is_open()) {

        outfile << "Student " << random_id << "\n";
        outfile <<"\tUser Name: "<< uname << "\n" <<"\tFirst Name: "<< fname << "\n" <<"\tLast Name: "<< lname << "\n" << "\tDate of birth: \n"<<dob << '\n' <<"----------------------------------------\n\n";
        outfile.close();
    }
}

void create_student_credentials(string& uname, string& fname, string& lname, string& dob) {
    bool passu = false, passf = false, passl = false, passdob = false;

    

    do {
        if (passu == false) {
            cout << "Enter Username: (Must start with 'S_' and be atleast 10 characters long)" << endl;
            getline(cin >> ws, uname);
            if ((size(uname) >= 10) &&
                (uname[0] == 'S' ) &&
                uname[1] == '_') {
                passu = true;
            }
        }

        if (passf == false) {
            cout << "Enter First Name" << endl;
            getline(cin >> ws, fname);
            if ((size(fname) <= 12) && check_char(fname)) {
                passf = true;
            }
        }

        if (passl == false) {
            cout << "Enter Last Name" << endl;
            getline(cin >> ws, lname);
            if ((size(lname) <= 12) && check_char(lname)) {
                passl = true;
            }
        }

        if (passdob == false) {
            cout << "Enter date of birth (DD/MM/YYYY)" << endl;
            getline(cin >> ws, dob);
            if ((size(dob) == 10) && check_date(dob)) {
                passdob = true;
            }
        }

    } while (!passu || !passf || !passl || !passdob);

    save_to_file_student(uname, fname, lname, dob); 
    return;
}
void create_admin_credentials(string& uname, string& fname, string& lname, string& dob) {
    bool passu = false, passf = false, passl = false, passdob = false;

    

    do {
        if (passu == false) {
            cout << "Enter Username: (Must start with 'A_' and be atleast 10 characters long)" << endl;
            cin >> uname;
            if ((size(uname) >= 10) &&
                (uname[0] == 'A') &&
                uname[1] == '_') {
                passu = true;
            }
        }

        if (passf == false) {
            cout << "Enter First Name" << endl;
            cin >> fname;
            if ((size(fname) <= 12) && check_char(fname)) {
                passf = true;
            }
        }

        if (passl == false) {
            cout << "Enter Last Name" << endl;
            cin >> lname;
            if ((size(lname) <= 12) && check_char(lname)) {
                passl = true;
            }
        }

        if (passdob == false) {
            cout << "Enter date of birth (DD/MM/YYYY)" << endl;
            cin >> dob;
            if ((size(dob) == 10) && check_date(dob)) {
                passdob = true;
            }
        }

    } while (!passu || !passf || !passl || !passdob);

    save_to_file_admin(uname, fname, lname, dob); 
    return;
}
void create_instructor_credentials(string& uname, string& fname, string& lname, string& dob) {
    bool passu = false, passf = false, passl = false, passdob = false;

    

    do {
        if (passu == false) {
            cout << "Enter Username: (Must start with 'I_' and be atleast 10 characters long)" << endl;
            cin >> uname;
            if ((size(uname) >= 10) &&
                (uname[0] == 'I') &&
                uname[1] == '_') {
                passu = true;
            }
        }

        if (passf == false) {
            cout << "Enter First Name" << endl;
            cin >> fname;
            if ((size(fname) <= 12) && check_char(fname)) {
                passf = true;
            }
        }

        if (passl == false) {
            cout << "Enter Last Name" << endl;
            cin >> lname;
            if ((size(lname) <= 12) && check_char(lname)) {
                passl = true;
            }
        }

        if (passdob == false) {
            cout << "Enter date of birth (DD/MM/YYYY)" << endl;
            cin >> dob;
            if ((size(dob) == 10) && check_date(dob)) {
                passdob = true;
            }
        }

    } while (!passu || !passf || !passl || !passdob);

    save_to_file_instructor(uname, fname, lname, dob); 
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
    int points;
    int grades;
    string view_assigned;
    string chosen_path;
    cout<<"What users would you like to create? Type: students, admins, or instructors \n";

    getline(cin >> ws, chosen_path);
    if (chosen_path == "students") {
        cout<< "If you enter anything that does not meet the format requirements, it will move on and re-ask you later once all inputs meet format requirements \n";  

        create_student_credentials(uname, fname, lname, dob);
    }
    else if (chosen_path == "admins") {
        cout<< "If you enter anything that does not meet the format requirements, it will move on and re-ask you later once all inputs meet format requirements '\n";  

        create_admin_credentials(uname, fname, lname, dob);
    }
    else if (chosen_path == "instructors") {
        cout<< "If you enter anything that does not meet the format requirements, it will move on and re-ask you later once all inputs meet format requirements '\n";  

        create_instructor_credentials(uname, fname, lname, dob);
    }
    else {
        cout << "Invalid choice. Please enter 'students', 'admins', or 'instructors'.\n";
    }
    

    
    cout<<uname<<" "<<fname<<" "<<lname<<" "<<dob<<endl;
}