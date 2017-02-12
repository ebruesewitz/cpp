/*Playing with Pointers
Elisabeth Bruesewitz
University of Cincinnati
Computer Science 
Class of 2019
*/

//console app for implementing singly and doubly linked lists

#include <iostream>
#include <stdlib.h>
#include <time.h>


#include "linkedlist.h"
#include "doublylinkedlist.h"


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
  
  cout << "Print reverse using recursion:" << endl;//print out but don't store a copy of the reversed list
  l.printReverseList();
  
  cout << "Quick size: " << l.getSizeQuick() << endl;
  cout << "Size through traversal: " << l.getSizeTraversing() << endl;
  
  LList r = l.reverse();//store the reversed list in a new object
  cout << "Create and print a new reversed list:" << endl;
  r.printList();
  
  l.inPlaceReverse();//reverse the original list
  cout << "Reverse original list in place:" << endl;
  l.printList();
  
  LList m(l);//new list using copy constructor
  cout << "Print new list copied from previous" << endl;
  l.clear(); //make sure the copy constructor is a deep copy
  m.printList();
  
  //make sure there aren't any mem leaks when trying to remove invalid positions
  cout << "Checking removing invalid positions" << endl;
  m.remove(0);
  m.remove(-5);
  m.remove(100);
  
  m.remove(5);
  cout << "Remove 5th element. New size: " << m.getSizeQuick() << endl;
  m.printList();
  
  //checking edge cases
  m.remove(1);
  m.remove(18);
  cout << "Remove first and last elements. New size: " << m.getSizeQuick() << endl;
  m.printList();
  
  cout << "\n\nDoubly linked list code" << endl;
  cout << "Display a list of 20 elements: " << endl;
  DLList n;//create a doubly linked list
  for(int i = 0; i < 10; i++){
    n.pushFront2(rand() % 10);
  }
  for(int i = 0; i < 10; i++){
    n.pushBack2(rand() % 10);
  }
  
  n.printList2();
  cout << "Quick size: " << n.getSizeQuick2() << endl;
  cout << "Size Forward: " << n.getSizeTraversingFwd() << endl;
  cout << "Size Backward: " << n.getSizeTraversingBwd() << endl;
  cout << "Print list reversed: " << endl;
  n.printListReverse2();
  cout << "Reverse original list in place: " << endl;
  n.inPlaceReverse2();
  n.printList2();
  
  DLList p(n);//create a new dll using copy constructor
  cout << "New copied list:" << endl;
  n.clear2();//checking to make sure it's a deep copy
  p.printList2();
  
  //make sure there aren't any mem leaks when trying to remove invalid positions
  cout << "Checking removing invalid positions" << endl;
  p.remove2(0);
  p.remove2(-5);
  p.remove2(100);
  
  p.remove2(7);
  cout << "Remove 7th element. New size: " << p.getSizeQuick2() << endl;
  p.printList2();
  
  //checking edge cases
  p.remove2(1);
  p.remove2(18);
  cout << "Remove first and last elements. New size: " << p.getSizeQuick2() << endl;
  p.printList2();
  
  return 0;
}
