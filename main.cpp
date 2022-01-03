#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void add();
void print (Node* next);

Node* head = NULL;

int main(){
  

  
  return 0;
}

void add(){
  Node* current = head;
  int id = -1;
  float gpa= -1;
  char firstName[100];
  char lastName[100];
  cout << "Input First Name" << endl;//Prompt user for first name
  cin >> firstName;
  cout << "Input Last Name" << endl;//Prompt user for last name
  cin >> lastName;
  cout << "Input Student ID" << endl;//Prompt user for student id
  cin >> id;
  cout << "Input Student GPA" << endl;//Prompt user for GPA
  cin >> gpa;
  if(current == NULL){
    head = new Node();
    head->setStudent(firstName, lastName, gpa, id);
  }
  else{
    while(current->getNext() != NULL){
      current = current ->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(firstName, lastName, gpa, id);
  }
  
}
