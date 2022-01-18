#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(Student* newStudent);
  ~Node();
  Student* getStudent();
  void setNext(Node* newNext);
  Node* getNext();

 private:
  Student* student;
  Node* next;
};
#endif