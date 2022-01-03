#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public:
  Node();
  ~Node();
  void setStudent(char firstName[100], char lastName[100], float gpa, int id);
  Student* getStudent();
  void setNext(Node* newNext);
  Node* getNext();
 private:
  Student* s;
  Node* next;
}
