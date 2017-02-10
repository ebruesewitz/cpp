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
  cout << "Print reverse:" << endl;//print out but don't store a copy of the reversed list
  l.printReverseList();
  cout << "Quick size: " << l.getSizeQuick() << endl;
  cout << "Size through traversal: " << l.getSizeTraversing() << endl;
  
  LList r = l.reverse();//store the reversed list in a new object
  cout << "Print new reversed list:" << endl;
  r.printList();
  
  return 0;
}
