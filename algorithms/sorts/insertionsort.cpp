//INSERTION SORT
//Elisabeth Bruesewitz

/*Sort an array of ints by shifting values to make room to insert an element into the correct spot
no extra storage (except for a few additional variables)

W(n) = O(n^2)
B(n) = O(n)
*/

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

//insertion sort function. pass vector of ints by reference to sort.
void insertionSort(vector<int>& data){
  int pos;
  int curr;
  for(int i = 1; i < data.size(); i++){
    pos = i-1;
    curr = data[i];
    while(pos >= 0 && curr < data[pos]){
      data[pos + 1] = data[pos];//shift values up to make room for curr
      pos--;
    }
    data[pos + 1] = curr;//values to the left of i are now sorted
  }
}

void printList(vector<int> data){//iterate through and print vector
  for(int i = 0; i < data.size() - 1; i++){
    cout << data[i] << ", ";
  }
  cout << data[data.size() - 1] << endl;
}

int main(){
  srand(time(0));
  //create a vector of 20 random ints from 0 to 99
  vector<int> myList;
  for(int i = 0; i < 20; i++){
    myList.push_back(rand() % 100);
  }
  cout << "Randomly generated list:" << endl;
  printList(myList);
  //sort the vector to increasing order
  insertionSort(myList);
  
  cout << "Sorted: " << endl;
  printList(myList);
  
  return 0;
}
