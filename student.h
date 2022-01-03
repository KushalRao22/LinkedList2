#include <iostream>

using namespace std;

class Student{
  char firstName[100];
  char lastName[100];
  float gpa;
  int id;
  void setStudent(char firstName[100], char lastName[100], float gpa, int id);
  void remove();
  void print();
}
