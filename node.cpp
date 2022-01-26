#include "node.h"
#include <iostream>
#include <cstring>


using namespace std;

Node::Node(Student* newStudent) {
  student = newStudent;
  next = NULL;
}

Node::~Node() {
  delete student;
  next = NULL;
}

Student* Node::getStudent() {
  return student;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}
