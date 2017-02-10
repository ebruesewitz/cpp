/*Elisabeth Bruesewitz
University of Cincinnati
Computer Science 
Class of 2019
*/

//singly linked list

#include <iostream>
#include <stdlib.h>

struct node_t{
  int data;
  node_t* next;
}; 

class LList{
  public:
  LList(){//starts a new empty list
    head = NULL;
    list_size = 0;
  }
  
  ~LList(){//clears list to prevent mem. leaks
    node_t* temp = head;
    while(temp){
      node_t* to_delete = temp;
      temp = temp -> next;
      delete to_delete;
    }
    head = NULL;
  }
  
  int getSizeQuick(){//returns the stored size of list (number of nodes)
    return list_size;
  }
  
  int getSizeTraversing(){//returns size of list through traversal
    if(head ==NULL){
      return 0;
    }
    node_t* temp = head;
    int traversal_size = 0;
    while(temp->next){//will stop at second to last node
      temp = temp->next;
      traversal_size++;
    }
    return traversal_size + 1;//add 1 to account for the last node
  }
  
  void pushFront(int value){//push a value to the front of the list, making it the first item
    node_t* front = new node_t;//dynamically allocate mem for new node
    front->data = value;
    front->next = head;
    head = front;//set the front node as the new head
    list_size++;
  }
  
  void pushBack(int value){//push a value to the back of a list, making it the last item
    if(head == NULL){//if the list is empty
      pushFront(value);//just push the value to the front of the list
      return;//finished adding value to list
    }
    list_size++;
    node_t* temp = head;
    while(temp->next){//goes to the second to last node
      temp = temp->next;
    }
    node_t* back = new node_t;
    back->data = value;
    back->next = NULL;//make the new node the end of the list
    temp->next = back;//redirect the old end of list to the new back node
  }
  
  void remove(int pos){//remove the nth position from a list
    if(pos == 0){
      node_t* to_delete = head;
      head = head-> next;
      delete to_delete;
      list_size--;
      return;
    }
    node_t* temp = head;
    int i = 0;
    while((temp) && i != pos-1){//takes us to the position right before the node to be deleted
      temp = temp->next;
      i++;
    }
    node_t* to_delete = temp->next;
    if(temp->next->next){//if the node to be deleted isn't the end of the list 
      temp->next = temp->next->next;//linked list "skips over" the node to be deleted
    }else{
      temp->next = NULL;//make the second to last node the last node
    }
    delete to_delete;
    list_size--;
  }
  
  void printList(){//print out a string of the linked list
    if(getSizeQuick() == 0){
      std::cout << "empty" << std::endl;
      return;
    }
    std::cout << "[";
    node_t* temp = head;
    while(temp->next){
      std::cout << temp->data << ", " ;
      temp = temp->next;
    }
    std::cout << temp->data;
    std::cout << "]" << std::endl;
  }
  
  void reverseList(){//print out a string of the list but in reverse
    if(getSizeQuick() == 0){
      std:: cout << "empty" << std::endl;
      return;
    }else if(getSizeQuick() == 1){
      printList();
      return;
    }
    std::cout << "[";
    reverseList(head);
    std::cout << "]" << std::endl;
  }
  
  void reverseList(node_t* n){//recursively iterate through list to get to last element then print all data
    if(n != NULL){
      reverseList(n->next);
      std::cout << n->data << ", ";
    }
  }
  
  private:
    node_t* head; //points to first element in list
    int list_size; //stores length of my list
};
