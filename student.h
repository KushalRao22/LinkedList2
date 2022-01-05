#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Student{
 public:
  char sFirstName[100];
  char sLastName[100];
  float gpa;
  int id;
  void setStudent(char firstName[100], char lastName[100], float gpa, int id);
  void print();

};
#endif
