/*Elisabeth Bruesewitz
University of Cincinnati
Computer Science 
Class of 2019
*/

//implement a singly linked list

#include <iostream>
#include <stdlib.h>
#include <time.h>


#include "linkedlist.h"


using namespace std;

int main(){
  srand(time(0));
  LList l; //create a linked list
  cout << "Singly linked list code" << endl;
  for(int i = 0; i < 10; i++){
    l.pushBack(rand() % 10);
  }
  for(int i = 0; i < 10; i++){
    l.pushFront(rand() % 10);
  }
  
  cout << "Display list of 20 elements:" << endl;
  l.printList();
  cout << "Quick size: " << l.getSizeQuick() << endl;
  cout << "Size through transversal: " << l.getSizeTransversing() << endl;
  
  return 0;
}
