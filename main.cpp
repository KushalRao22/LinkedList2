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
//Function Prototypes
void add();
void print (Node* next);
void remove(Node* &head);
//Define head of linked list
Node* head = NULL;

int main(){
  char input[10];
  bool play = true;
  while(play){//While user is doing stuff
    cout << "Input a valid command(Add, Print, Remove, Quit)" << endl;
    cin >> input;
    if(strcmp(input, "Add") == 0){//If user wants to add
      add();
    }
    if(strcmp(input, "Print") == 0){//if user wants to print
      print(head);
      cout << endl;
    }
    if(strcmp(input, "Quit") == 0){//if user wants to quit
      play = false;
    }
    if(strcmp(input, "Remove") == 0){//if user wants to remove
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
  if(current == NULL){//If this is first Student
    head = new Node(new Student());
    head->getStudent()->setStudent(firstName, lastName, gpa, id);//set student to have stats
  }
  else{
    while(current->getNext() != NULL){//Go to the end of the list
      current = current ->getNext();
    }
    //Add a new student with stats
    current->setNext(new Node(new Student));
    current->getNext()->getStudent()->setStudent(firstName, lastName, gpa, id);
  }
}

void print(Node* next){//Print all students in the list
  if(next == head){
    cout << "List";
  }
  if(next != NULL){//Until the end of the list
    next->getStudent()->print();//Print yourself
    print(next->getNext());//Call print on next function
  }
}

void remove(Node* &head){//Remove student
  Node* prev = head;
  Node* current = head; 
  bool remove = true;
  int input;
  cout << "Input the ID of the student you want to remove" << endl;
  cin >> input;
  while(remove){//while student is not removed
    int check = current->getStudent()->getID();//get ID of the student
    if(check == input){//If current student is the same as the one user wants to remove
      if(current == head){//If current is head
	head = current->getNext();//Set head to next
	current->~Node();//Remove head
	remove = false;//Leave loop
      }
      else{
	prev->setNext(current->getNext());//set previous to point to next
	current->~Node();//Remove current
	remove = false;
      }
    }
    else{
      prev = current;
      current = current->getNext();
      }
    }
  }

