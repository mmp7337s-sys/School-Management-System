#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <map>
#include <limits>
#include "globals.h"
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

string clean_input(const string& s) {
    string result;
    for (char c : s) {
        if (isalnum(c)) result += c;
    }
    return result;
}
//read courses.txt 
void load_course_assignments(const string& filename) {
    ifstream infile(filename);
    string line;
    string current_course_id;
    string instructor;

    while (getline(infile, line)) {
        if (line.find("ID: ") != string::npos) {
            current_course_id = line.substr(4);
        }
        else if (line.find("Instructor: ") != string::npos) {
            instructor = line.substr(12);
            instructor_courses[instructor].push_back(current_course_id);
        }
    }
    infile.close();
}
bool course_id_format_check(string& course_id){
    
    if(size(course_id)>6){
        cout<<"Course ID must be 3 letters followed by 3 numbers!";
        return false;
    }
    for (int i = 0; i < 3; i++) {
            if (!isalpha(course_id[i])) {
                cout <<"First 3 letters must be alphabetical!";
                return false;
            }
            else{
                continue;
            }
        }
    for (int i = 3; i < 6; i++) {
            if (!isdigit(course_id[i])) {
                cout <<"The last 3 letters must be numerical!";
                return false;
            }
            else{
                continue;
            }
        }
        return true;
        
}
bool course_number_format_check(string& course_number){
    bool letter_check;
    if(size(course_number)>7 or size(course_number)<7){
        cout<<"Course Number must be exactly 7 letters!";
        return false;
    }
    //isdigit automagically rules out negative numbers since '-' is not a digit
    for (int i = 0; i < 7; i++) {
            if (!isdigit(course_number[i])) {
                cout <<"Course number must be comprised of only numbers!";
                return false;
            }
            else{
                continue;
            }
        }
        return true;
        
}

bool course_description_format_check(string& course_description) {
    if (course_description.size() > 30) {
        cout << "Course description is limited to 30 characters!" << endl;
        return false;
    }

    for (size_t i = 0; i < course_description.size(); ++i) {
        unsigned char c = course_description[i];

        if (!isalpha(c) && !isspace(c) && !ispunct(c)) {
            cout << "Course description must only be comprised of letters, spaces, and punctuation." << endl;
            return false;
        }
    }

    return true;
}

bool num_seats_format_check(string& num_seats, string& students_registered){
    num_seats=clean_input(num_seats);
    students_registered=clean_input(students_registered);
    for (char c : num_seats) {
        if (!isdigit(c)) {
            cout << "Course number must be comprised of only numbers!" << endl;
            return false;
        }
    }

    for (char c : students_registered) {
        if (!isdigit(c)) {
            cout << "Course number must be comprised of only numbers!" << endl;
            return false;
        }
    }
    int number_of_seats;
    int number_of_registered;
    number_of_seats=stoi(num_seats);
    number_of_registered=stoi(students_registered);
    if(number_of_registered>number_of_seats){
        cout<< "You entered more registered students than available seating!";
        return false;
    }
    else {
    }
        return true;

}
bool course_assigned_format_check(string& course_assigned, string& professor_name){
    if (course_id_format_check(course_assigned)==false){
        cout<<"Did not pass the format check! First 3 letters must be alphabetical, and the last 3 must be numerical!";
        return false;
    }
    else{

    }
    return true;

}




void save_to_file(string& course_id, string& course_number, string& course_description, string& num_seats, string& course_id_assign, string& students_registered, string& assigned_classes, string& professor_name){
    ofstream outfile("courses.txt", ios::app);  

    if (outfile.is_open()) {
        int seats = stoi(num_seats);
        int enrolled = stoi(students_registered);
        int remaining = seats - enrolled;
        cout<< "File is open successfully!";
        static int course_counter = 1; 

        outfile << "Course " << course_counter++ << '\n';
        outfile << "ID: " << course_id_assign << '\n';
        outfile << "Course Number: " << course_number << '\n';
        outfile << "Description: " << course_description << '\n';
        outfile << "Max Seats: " << num_seats << '\n';
        outfile << "Currently Enrolled: " << students_registered << '\n';
        outfile << "Remaining: " << remaining << "\n";
        outfile << "Instructor: "<<professor_name <<'\n' <<'\n';
        outfile.close();
        cout << "Course successfully saved to courses.txt\n";
    } else {
        cerr << "Error: Could not open courses.txt for writing.\n";
    }
}

void admin_actions(string& course_id, string& course_number, string& course_description, string& course_id_assign, string& num_seats, string& students_registered, string& assigned_classes, string& professor_name){

    bool course_id_check = false;
    bool course_number_check = false;
    bool course_description_check = false;
    bool num_seats_check = false;
    bool course_assigned_check = false;    
    do{
        while(true){
            if(course_id_check == false){
                cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
                cin>> course_id;
                if(course_id_format_check(course_id)==true){
                    course_id_check = true;
                    break;
                }else{
                    cout<<"Try Again";
                }
            }
        }
        if(course_number_check == false){
            while(true){
                cout<<"Enter course number \n(No longer than length 7)"<<endl;
                cin>>course_number;
                if(course_number_format_check(course_number)==true){
                    course_number_check = true;
                    break;
                }else{
                    cout<<"Try Again\n";
                }
            }
                
        }
        
        if (course_description_check == false) {
            
            while (true) {

                cout << "Enter course description \n(Maximum of 30 characters)" << endl;
                getline(cin >> ws, course_description);  
                if (course_description_format_check(course_description)) {
                    course_description_check = true;
                    break;
                } else {
                    cout << "Try Again\n";
                }
            }
        }
        if(num_seats_check == false){
            while(true){
                cout<<"Enter maximum number of seats: \n"<<endl;
                cin>>num_seats;
                cout<<"Enter number of currently registered students: \n"<<endl;
                cin>>students_registered;
                int remaining_seats;
                if(num_seats_format_check(num_seats, students_registered)==true){
                    num_seats_check = true;
                    remaining_seats=stoi(num_seats)-stoi(students_registered);
                    cout<< "Remaining seats available: " <<remaining_seats <<'\n';
                    break;
                }
            }
        }else{
            cout<<"Try Again";
        }

        if(course_assigned_check == false){
            while(true){
                    
                    
                
                    cout << "Enter instructor user name: ";

                    getline(cin >> ws, professor_name);
                    while(true){
                        cout << "Enter course ID to assign: ";
                        getline(cin >> ws, course_id_assign);
                        if(course_id_format_check(course_id_assign)==true){
                            break;
                        }
                        else{
                            
                        }
                    }
                    // Assign the course to the instructor
                    auto& courses = instructor_courses[professor_name];
                    if (find(courses.begin(), courses.end(), course_id_assign) != courses.end()) {
                        cout << "Error: " << professor_name << " is already assigned to course " << course_id_assign << ". Try a different course or instructor.\n";
                        continue; // Ask again
                    }

                    // Assign the course
                    courses.push_back(course_id_assign);
                                    
                    // Print the result
                    cout << "\n" << professor_name << " is assigned to course(s): ";
                    for (const string& cid : instructor_courses[professor_name]) {
                        cout << cid << " ";
                    }
                    cout << endl;
                
                    course_assigned_check=true;
                    break;
                }
                

            }
                
        
    }while((course_id_check && course_number_check && course_description_check && num_seats_check && course_assigned_check) != true);
    save_to_file(course_id, course_number,  course_description, num_seats, course_id_assign, students_registered, assigned_classes, professor_name);
    return;
}

int main(){
    load_course_assignments("courses.txt");

    string uname;
    string fname;
    string lname;
    string dob;
    string course_id;
    string course_number;
    string course_description; 
    string num_seats;
    string students_registered;
    string assigned_classes; 
    string professor_name;
    string assignment_name;
    string student_name;
    int grade;
    string assignment_created;
    string course_id_assign;
    int points;
    int grades;
    string view_assigned;
    
    //retrieve_credentials(uname, fname, lname, dob);
    admin_actions(course_id, course_number, course_description, num_seats, students_registered, assigned_classes, professor_name, course_id_assign );
}