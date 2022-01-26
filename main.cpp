/*
This is a class that creates a list of nodes 

Last Modified: 1/26/22

By: Kushal Rao
*/
//Imports
#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"

using namespace std;
//Function Prototypes
void add(Node* input, char firstName[100], char lastName[100], float gpa, int id);
void print (Node* next);
void average(Node* current, float total, float count);
void remove(Node* &head, Node* current, Node* prev, int input);
//Define head of linked list
Node* head = NULL;

int main(){
  char input[10];
  bool play = true;
  while(play){//While user is doing stuff
    cout << "Input a valid command(Add, Print, Remove, Average, Quit)" << endl;
    cin >> input;
    if(strcmp(input, "Add") == 0){//If user wants to add
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
      add(head, firstName, lastName, gpa, id);
    }
    if(strcmp(input, "Print") == 0){//if user wants to print
      print(head);
      cout << endl;
    }
    if(strcmp(input, "Quit") == 0){//if user wants to quit
      play = false;
    }
    //    if(strcmp(input, "Remove") == 0){//if user wants to remove
    //int input;
    //cout << "Input the ID of the student you want to remove" << endl;
    //cin >> input;
    //remove(head, head, head, input);
      //}
    if(strcmp(input, "Average") == 0){//if user wants to remove
      int input;
      float total;
      float count = 0;
      average(head, total, count);
    }
   }
  return 0;
}

void add(Node* input, char firstName[100], char lastName[100], float gpa, int id){

  if(head == NULL){//If this is first Student
    head = new Node(new Student());
    head->getStudent()->setStudent(firstName, lastName, gpa, id);//set student to have stats
    return;
  }
  else if(input->getNext() != NULL){//Go to the end of the list
    add(input->getNext(), firstName, lastName, gpa, id);//Walk to the end of the list
  }
    //Add a new student with stats
  Student* n = new Student;
  input->setNext(new Node(n));
  input->getNext()->getStudent()->setStudent(firstName, lastName, gpa, id);
  input->getNext()->getStudent()->print();
  return;
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

void remove(Node* &head, Node* current, Node* prev,int input){//Remove student
  int check = current->getStudent()->getID();//get ID of the student
  if(check == input){//If current student is the same as the one user wants to remove
    if(current == head){//If current is head
      head = current->getNext();//Set head to next
      current->~Node();//Remove head
      return;//Stop recursion
    }
    else{
      prev->setNext(current->getNext());//set previous to point to next
      current->~Node();//Remove current
      return;//Stop recursion
    }
  }
  else{
    remove(head, current->getNext(), current, input);
  }  
}

void average(Node* current, float total, float count){
  count++;//Add count
  total += current->getStudent()->getGPA();//Add current students GPA to total
  if(current->getNext() == NULL){//If this is last node
    float average = (total/count);//Average total/count
    cout << "Average: " << setprecision(2) << fixed << average << endl;//Print average to two decimals
    return;//Stop recursion
  }
  else{
    average(current->getNext(), total, count);//Call the method on next node
  }
}
