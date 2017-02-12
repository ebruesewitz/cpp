#include <iostream>
#include <stdlib.h>

struct dlnode{//doubly linked node pointing to prev and next nodes
  int dldata;
  dlnode* prev;
  dlnode* next;
};

class DLList{
  public:
    DLList(){//create a new empty list
      head = NULL;
      tail = NULL;
      dllist_size = 0;
    }
    
    DLList(const DLList& l){//copy constructor
      head = NULL;
      tail = NULL;
      dllist_size = 0;
      dlnode* temp = l.head;
      while(temp != NULL){
        pushBack2(temp->dldata);
        temp = temp->next;
      }
    }
    
    ~DLList(){//clear list to prevent mem leaks
      clear2();
      std::cout << "cleared" << std::endl;//double checking to make sure destructor is called
    }
    
    void clear2(){//clear list to prevent mem leaks
      dlnode* temp = head;
      while(temp){
        dlnode* to_delete = temp;
        temp = temp->next;
        delete to_delete;
      }
      head = NULL;
      tail = NULL;
    }
    
    int getSizeQuick2(){//return the size of list stored in this class
      return dllist_size;
    }
    
    int getSizeTraversingFwd(){//find the size through forward traversal
      if(!head){
        return 0;
      }
      dlnode* temp = head;
      int mysize;
      while(temp->next){//counts up to second to last node
        temp = temp->next;
        mysize++;
      }
      return mysize + 1;//accounting for last node
    }
    
    int getSizeTraversingBwd(){//find size through backward traversal
      if(!head){
        return 0;
      }
      dlnode* temp = tail;
      int size;
      while(temp->prev){//takes us to second node
        temp = temp->prev;
        size++;
      }
      return size + 1;//account for first node
    }
    
    void pushFront2(int value){//add number to the front of the list
      dlnode* toadd = new dlnode;
      if(!head){//if list is empty
        toadd->prev = NULL;
        toadd->next = head;
        toadd->dldata = value;
        head = toadd;
        tail = toadd;
        dllist_size++;
        return;
      }
      toadd->prev = NULL;
      toadd->next = head;
      toadd->dldata = value;
      head->prev = toadd;
      head = toadd;//set new node as head
      dllist_size++;
    }
    
    void pushBack2(int value){ //add number to the end of the list
      if(!head){//if the list is empty, just push value to the front
        pushFront2(value);
        return;
      }
      dlnode* toadd = new dlnode;
      toadd->prev = tail;
      toadd->next = NULL;
      toadd->dldata = value;
      tail->next = toadd;
      tail = toadd;//set new node as the tail
      dllist_size++;
    }
    
    void remove2(int pos){//removes the nth element from the list
      if(pos == 1){//removes first element in list (aka: head)
        dlnode* to_delete = head;
        head = head->next;
        head->prev = NULL;
        delete to_delete;
        dllist_size--;
        return;
      }else if(pos < 1 || pos > getSizeQuick2()){
        std::cout << "Position not in list." << std::endl;
        return;
      }
      dlnode* temp = head;
      int i = 1;
      while((temp) && i != pos-1){//takes us to the position right before the node to delete
        temp = temp->next;
        i++;
      }
      dlnode* to_delete = temp->next;
      if(temp->next->next){//if the node to be deleted isn't at the end of the list
        temp->next = temp->next->next;
        temp->next->prev = temp; 
      }
      else{//if the node to be deleted is at the end of the list
        temp->next = NULL;
        tail = temp;//make the node before it the tail
      }
      delete to_delete;
      dllist_size--;
    }
    
    void printList2(){//prints out the data in the list
      if(getSizeQuick2() == 0){
        std::cout << "empty" << std::endl;
        return;
      }
      dlnode* temp = head;
      std::cout << "[";
      while(temp->next){
        std::cout << temp->dldata << ", ";
        temp = temp->next;
      }
      std::cout << temp->dldata  << "]" << std::endl;
    }
    
    void printListReverse2(){//prints the list in reverse
      if(getSizeQuick2() == 0){
        std::cout << "empty" << std::endl;
        return;
      }else if(getSizeQuick2() == 1){
        printList2();
        return;
      }else{
        dlnode* temp = tail;
        std::cout << "[";
        while(temp->prev){
          std::cout << temp->dldata << ", ";
          temp = temp->prev;
        }
        std::cout << temp->dldata << "]" << std::endl;
      }
    }
    
    void inPlaceReverse2(){//reverse the actual list in place by switching pointers to avoid doubling storage
      dlnode* prev = NULL;
      dlnode* next = NULL;
      dlnode* curr = head;
      head = tail;
      tail = curr;
      while(curr != NULL){
        prev = curr->prev;
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        curr = next;
      } 
    }
    

  private:
    int dllist_size;
    dlnode* head;//pointer to start of list
    dlnode* tail;//pointer to end of list
};

