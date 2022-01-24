/*
This is a class that creates a list of nodes 

Last Modified: 1/24/22

By: Kushal Rao
*/
//Imports
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void add();
void print (Node* next);
void remove(Node* &head);

Node* head = NULL;

int main(){
  char input[10];
  bool play = true;
  while(play){
    cin >> input;
    if(strcmp(input, "Add") == 0){
      add();
    }
    if(strcmp(input, "Print") == 0){
      print(head);
      cout << endl;
    }
    if(strcmp(input, "Quit") == 0){
      play = false;
    }
    if(strcmp(input, "Remove") == 0){
      remove(head);
    }
    }
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
    head = new Node(new Student());
    head->getStudent()->setStudent(firstName, lastName, gpa, id);
  }
  else{
    while(current->getNext() != NULL){
     current = current ->getNext();
    }
    current->setNext(new Node(new Student));
    current->getNext()->getStudent()->setStudent(firstName, lastName, gpa, id);
  }
}

void print(Node* next){
  if(next == head){
    cout << "List";
  }
  if(next != NULL){
    next->getStudent()->print();
    print(next->getNext());
  }
}

void remove(Node* &head){
  Node* current = head;
  Node* next = head; 
  bool remove = true;
  int input;
  cout << "Input the ID of the student you want to remove" << endl;
  cin >> input;
  while(remove){
    int check = next->getStudent()->getID();
    if(check == input){
      if(next == head){
	head = next->getNext();
	next->~Node();
	remove = false;
      }
      else{
	current->setNext(next->getNext());
	next->~Node();
	remove = false;
      }
    }
    else{
      if(next == NULL){
	cout << "End of List" << endl;
	remove = false;
      }
      else{
	current = next;
	next = next->getNext();
      }
    }
  }
}

