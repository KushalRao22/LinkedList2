/*
This is the .h file for student.cpp

By: Kushal Rao

Last modified: 1/26/22
*/

//Header Gaurd
#ifndef STUDENT_H
#define STUDENT_H
//Imports
#include <iostream>

using namespace std;

class Student{
 public:
  //Stats
  char sFirstName[100];
  char sLastName[100];
  float gpa;
  int id;
  //Methods
  void setStudent(char firstName[100], char lastName[100], float gpa, int id);
  void print();
  int getID();
  float getGPA();
};
#endif

