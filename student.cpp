/*
This is a class to define students

Last modified: 1/24/22

By: Kushal Rao
*/
//Imports
#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

void Student::setStudent(char firstNameIn[100], char lastNameIn[100], float gpaIn, int idIn){//Set students stats
  strcpy(sFirstName, firstNameIn);
  strcpy(sLastName, lastNameIn);
  gpa = gpaIn;
  id = idIn;
}

void Student::print(){//Print student
  cout << " Name: " << sFirstName << " " << sLastName << " gpa: " << setprecision(2) <<  fixed << gpa << " id: " << id; 
}

int Student::getID(){//Return ID
  return id;
}
