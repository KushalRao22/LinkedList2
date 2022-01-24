#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

void Student::setStudent(char firstNameIn[100], char lastNameIn[100], float gpaIn, int idIn){
  strcpy(sFirstName, firstNameIn);
  strcpy(sLastName, lastNameIn);
  gpa = gpaIn;
  id = idIn;
}

void Student::print(){
  cout << " Name: " << sFirstName << " " << sLastName << " gpa: " << setprecision(2) <<  fixed << gpa << " id: " << id; 
}

int Student::getID(){
  return id;
}
