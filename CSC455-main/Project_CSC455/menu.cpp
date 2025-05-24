#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

string clean_input(const string& s) {
    string result;
    for (char c : s) {
        if (isalnum(c)) result += c;
    }
    return result;
}
bool check_char(string& word){
    for(int i = 0; i < size(word); i++){
        if(!isalpha(word[i])){
            return false;
        }
    }
    return true;
    
}

bool check_date(string& dob){
    for(int i = 0; i < size(dob); i++){
        if(i != 2 && i != 5 && (!isdigit(dob[i]))){
            return false;
        }else if((i == 2 || i == 5) && (dob[i] != '/')){
            return false;
        }
    }
    return true;
}

void retrieve_credentials(string& uname, string& fname, string& lname, string& dob){

    bool passu, passf, passl, passdob = false;
    do{
        if(passu == false){
            cout<<"Enter Username:"<<endl;
            cin>> uname;
            if((size(uname) >= 10) && 
            (uname[0] == 'A' || uname[0] == 'S' || uname[0] == 'I' ) && 
            uname[1] == '_'){
                passu = true;
            }else{

            }
        }else{

        }
        if(passf == false){
            cout<<"Enter First Name"<<endl;
            cin>>fname;
            if((size(fname) <= 12) && check_char(fname)){
                passf = true;
            }else{

            }
        }else{

        }
        if(passl == false){
            cout<<"Enter Last Name"<<endl;
            cin>>lname;
            if((size(lname) <= 12) && check_char(fname)){
                passl = true;
            }else{

            }
        }else{

        }
        if(passdob == false){
            cout<<"Enter date of birth"<<endl;
            cin>>dob;
            if((size(dob) == 10) && check_date(dob)){
                passdob = true;
            }
        }else{

        }
    }while((passl && passf && passu && passdob) != true);
    return;
}
void save_to_file(const string& uname, const string& fname, const string& lname, const string& dob){
    ofstream outfile("administrator.txt", ios::app);  

    if (outfile.is_open()) {
        cout<< "File is open successfully!";
        static int course_counter = 1; 

        outfile << "User name " << uname << '\n';
        outfile << "First name " << fname << '\n';
        outfile << "Last name "  << lname << '\n';
        outfile << "Date of birth: " << dob << '\n';

        outfile.close();
        cout << "Course successfully saved to courses.txt\n";
    } else {
        cerr << "Error: Could not open courses.txt for writing.\n";
    }
}
void create_credentials(string& uname, string& fname, string& lname, string& dob) {
    bool passu = false, passf = false, passl = false, passdob = false;

    do {
        if (passu == false) {
            cout << "Enter Username:" << endl;
            cin >> uname;
            if ((size(uname) >= 10) &&
                (uname[0] == 'A' || uname[0] == 'S' || uname[0] == 'I') &&
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
            if ((size(lname) <= 12) && check_char(fname)) {
                passl = true;
            }
        }

        if (passdob == false) {
            cout << "Enter date of birth" << endl;
            cin >> dob;
            if ((size(dob) == 10) && check_date(dob)) {
                passdob = true;
            }
        }

    } while ((passl && passf && passu && passdob) != true);

    save_to_file(uname, fname, lname, dob);
    return;
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
map<string, vector<string>> instructor_courses;
bool course_description_format_check(string& course_description){
    
    course_description=clean_input(course_description);
    if(size(course_description)>30){
        cout<<"Course description is limited to 30 characters!";
        return false;
    }
    for (int i = 0; i <= 30; i++) {
            if (!isalpha(course_description[i]||!isspace(course_description[i]||!ispunct(course_description[i])))) {
                cout <<"Course description must only be comprised of characters, spaces and punctuation";
                return false;
            }
            else{
                continue;
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

void admin_actions(string& course_id, string& course_number, string& course_description, string& num_seats, string& students_registered, string& assigned_classes, string& professor_name){

    bool course_id_check = false;
    bool course_number_check = false;
    bool course_description_check = false;
    bool num_seats_check = false;
    bool course_assigned_check = false;    
    do{
        if(course_id_check == false){
            cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
            cin>> course_id;
            if(course_id_format_check(course_id)==true){
                course_id_check = true;
            }else{
                cout<<"Try Again";
            }
        }else{

        }
        if(course_number_check == false){
            cout<<"Enter course number \n(No longer than length 7)"<<endl;
            cin>>course_number;
            if(course_number_format_check(course_number)==true){
                course_number_check = true;
            }else{
                cout<<"Try Again";
            }
        }else{

        }
        if(course_description_check == false){
            cout<<"Enter course description \n(Maximum of 30 characters)"<<endl;
            cin>>course_description;
            if(course_description_format_check(course_description)==true){
                course_description_check = true;
            }else{
                cout<<"Try Again";
            }
        }else{

        }
        if(num_seats_check == false){
            cout<<"Enter maximum number of seats: \n"<<endl;
            cin>>num_seats;
            cout<<"Enter number of currently registered students: \n"<<endl;
            cin>>students_registered;
            int remaining_seats;
            if(num_seats_format_check(num_seats, students_registered)==true){
                num_seats_check = true;
                remaining_seats=stoi(num_seats)-stoi(students_registered);
                cout<< "Remaining seats available: " <<remaining_seats;
            }
        }else{
            cout<<"Try Again";
        }

        if(course_assigned_check == false){
            cout<<"Enter classes to assign \n"<<endl;
            cin>>num_seats;
            cout<<"Enter professors username \n"<<endl;
            cin>>students_registered;
            
            if(course_assigned_format_check(assigned_classes, professor_name)==true){
                
                

                string instructor_name;
                string course_id;
            
                cout << "Enter instructor user name: ";
                getline(cin >> ws, instructor_name);
            
                cout << "Enter course ID to assign: ";
                cin >> course_id;
            
                // Assign the course to the instructor
                instructor_courses[instructor_name].push_back(course_id);
            
                // Print the result
                cout << "\n" << instructor_name << " is assigned to course(s): ";
                for (const string& cid : instructor_courses[instructor_name]) {
                    cout << cid << " ";
                }
                cout << endl;
            
                course_assigned_check=true;
            }
                
            }
        else{
            cout<<"Try Again";
        }
        
        
        
    }while((course_id_check && course_number_check && course_description_check && num_seats_check && course_assigned_check) != true);
    return;
}
map<string, int> assignments;
map<string, map<string, int>> gradebook;
void instructor_actions(string& assignment_created, string&assignment_name, int&points, int&grades, string&view_assigned, string&student_name, string&professer_name){
    
    bool assignment_created_check, points_check, grades_check, view_assigned_courses = false;
    
    do{
        if(assignment_created_check == false){
            cout<<"What is the name of the assignment you would like to create?"<<endl;
            cin>> assignment_created;
            
            cout<<"And how many points is this assignment worth?";
            cin>>points;
            assignments[assignment_created] = points;
        }else{

        }
        
        
        if(grades_check == false){
            cout<<"For which assignment would you like to enter grades for?"<<endl;
            cin>>assignment_name;
            cout<<"For which student?";
            cin>>student_name;
            cout<<"What grade would you like to give?";
            cin>> grades;
            gradebook[assignment_name][student_name] = grades;
        }else{

        }
        if(view_assigned_courses == false){
            cout<<"Would you like to view assigned courses?(Y/N)"<<endl;
            string input;
            cin>>input;
            if (input[0] == 'y' || input[0] == 'Y'){
                cout<<"For which professor would you like to view? Please enter their username";
                cin>>professer_name;
                cout << "\n" << professer_name << " is assigned to course(s): ";
                for (const string& cid : instructor_courses[professer_name]) {
                    cout << cid << " ";
                }
                cout << endl;
            
            }
            else{
                view_assigned_courses = true;
                cout<<"Okay you have chosen not to view assigned courses";
            }

            
        }else{

        }
       //add a would you like to do this, and if reply is no then just set the check to true 
        
    }while((assignment_created_check && points_check && grades_check && view_assigned_courses) != true);
    return;
}
// void student_actions(string& student_user_name, string&course_number, string&course_id, string&grades, string&instructor_name){

//     bool assignment_created_check, assignment_name_check, points_check, grades_check, instructor_name_check = false;
    
//     do{
//         if(assignment_created_check == false){
//             cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
//             cin>> assignment_created;
            
//         }else{

//         }
//         if(assignment_name_check == false){
//             cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
//             cin>> assignment_name;
            
//         }else{

//         }
//         if(points_check == false){
//             cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
//             cin>> points;
            
//         }else{

//         }
//         if(grades_check == false){
//             cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
//             cin>> grades;
            
//         }else{

//         }
//         if(instructor_name_check == false){
//             cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
//             cin>> grades;
            
//         }else{

//         }
//        //add a would you like to do this, and if reply is no then just set the check to true 
        
//     }while((assignment_created_check && assignment_name_check && points_check && grades_check && instructor_name_check) != true);
//     return;
// }
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
    
    //retrieve_credentials(uname, fname, lname, dob);
    admin_actions(course_id, course_number, course_description, num_seats, students_registered, assigned_classes, professor_name );
    instructor_actions( assignment_created, assignment_name, points, grades, view_assigned, student_name, professor_name);
    cout<<uname<<" "<<fname<<" "<<lname<<" "<<dob<<endl;
}