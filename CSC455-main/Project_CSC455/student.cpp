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
void load_student_courses(const string& filename) {
    ifstream infile(filename);
    string line;
    string current_username;

    while (getline(infile, line)) {
        
        line.erase(line.find_last_not_of(" \n\r\t") + 1);

        
        size_t colon_pos = line.find(": ");
        if (colon_pos != string::npos) {
            string key = line.substr(0, colon_pos);
            string value = line.substr(colon_pos + 2); 

            if (key == "User Name") {
                current_username = clean_input(value);
            } else if (key == "Course" && !current_username.empty()) {
                student_courses[current_username].push_back(value);
            }
        }
    }

    infile.close();
}
void append_course_to_student(const string& student_user_name, const string& new_course_id) {
    ifstream infile("students.txt");
    vector<string> lines;
    string line;
    bool in_target_user = false;
    bool inserted = false;
    size_t insert_pos = 0;

    while (getline(infile, line)) {
        lines.push_back(line);

        if (line == "User Name: " + student_user_name) {
            in_target_user = true;
            continue;
        }

        if (in_target_user && line == "----------------------------------------" && !inserted) {
            
            insert_pos = lines.size() - 1;
            lines.insert(lines.begin() + insert_pos, "Course: " + new_course_id);
            inserted = true;
            in_target_user = false;
        }
    }

    infile.close();


}
void student_actions(string& student_user_name, string&course_number, string&course_id, string&grades){

    bool enroll_check = false;
    bool drop_check = false;
    bool view_grades_check = false;
    do{
        if(enroll_check == false){
            cout<<"What is your user name?";
            getline(cin, student_user_name); 
            cout<<"For which classes would you like to enroll in?\n"<<endl;
            getline(cin, course_id); 
            append_course_to_student(student_user_name, course_id); 
            enroll_check =true;
        }else{

        }

       
        
    }while((enroll_check) != true);
    return;
}
int main(){
    
    string student_user_name;
    string course_number;
    string course_id;
    string grades;
    string instructor_name;
    //retrieve_credentials(uname, fname, lname, dob);
    student_actions(student_user_name, course_number, course_id, grades);
    
}