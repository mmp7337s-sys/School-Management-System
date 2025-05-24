#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


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

bool course_description_format_check(string& course_description){
    bool letter_check;
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
string clean_input(const string& s) {
    string result;
    for (char c : s) {
        if (isalnum(c)) result += c;
    }
    return result;
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

void admin_actions(string& course_id, string& course_number, string& course_description, string& num_seats, string& students_registered){

    bool course_id_check, course_number_check, course_description_check, num_seats_check = false;
    
    do{
        if(course_id_check == false){
            cout<<"(Format: 'ABC123' \nEnter course id:"<<endl;
            cin>> course_id;
            if(course_id_format_check(course_id)==true){
                course_id_check = true;
            }else{

            }
        }else{

        }
        if(course_number_check == false){
            cout<<"Enter course number \n(No longer than length 7)"<<endl;
            cin>>course_number;
            if(course_number_format_check(course_number)==true){
                course_number_check = true;
            }else{

            }
        }else{

        }
        if(course_description_check == false){
            cout<<"Enter course description \n(Maximum of 30 characters)"<<endl;
            cin>>course_description;
            if(course_description_format_check(course_description)==true){
                course_description_check = true;
            }else{

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

        }
        
        
        
    }while((course_id_check && course_number_check && course_description_check && num_seats_check) != true);
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
    //retrieve_credentials(uname, fname, lname, dob);
    admin_actions(course_id, course_number, course_description, num_seats, students_registered );
    cout<<uname<<" "<<fname<<" "<<lname<<" "<<dob<<endl;
}
