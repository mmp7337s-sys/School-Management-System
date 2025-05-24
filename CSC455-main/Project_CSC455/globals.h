#ifndef GLOBALS_H
#define GLOBALS_H

#include <map>
#include <string>
#include <vector>

extern std::map<std::string, std::vector<std::string>> instructor_courses;
extern std::map<std::string, int> assignments;
extern std::map<std::string, std::map<std::string, std::string>> gradebook;



extern std::map<std::string, std::vector<std::string>> student_courses;
#endif 