#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;

Node::Node(){
  s = new Student();
  next = NULL;
}

Node::~Node(){
  s->remove();
  next = NULL;
}

void Node::setStudent(char firstName[100], char lastName[100], float gpa, int id){
  s->setStudent(firstName, lastName, gpa, id);
}

Student* Node::getStudent(){
  return s;
}

void Node::setNext(Node* newNext){
  next = newNext
}

Node* Node::getNext(){
  return next;
}
