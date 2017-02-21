//MERGESORT
//Elisabeth Bruesewitz

/*Sort a vector of ints by recursively splitting in half to sort and merging sorted halves together.

not in place because of arrays created in merge.

W(n): nlogn
A(n): nlogn
B(n): nlogn*/

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);

//initial mergesort function that's called in main
void mergeSort(vector<int>& data){
  mergeSort(data, 0, data.size() - 1);
}

//overloaded mergesort function that gets called with left & right parameters
void mergeSort(vector<int>& data, int left, int right){
  int mid;
  if(left < right){
    mid = (left + right)/2;
    //recursively split into halves then merge to sort them
    mergeSort(data, left, mid);
    mergeSort(data, mid+1, right);
    merge(data, left, mid, right);
  }
  return;
}

//merge function to combine two (sorted) halves of list
void merge(vector<int>& data, int left, int mid, int right){
  int pos1 = left;
  int pos2 = mid + 1;
  int count = left;
  int temp[data.size()];
  while(pos1 <= mid && pos2 <= right){//while there are still values in each (sorted) half, add (in order) to temp array 
    if(data[pos1] < data[pos2]){
      temp[count] = data[pos1];
      pos1++;
      count++;
    }else{
      temp[count] = data[pos2];
      pos2++;
      count++;
    }
  }

  while(pos1 <= mid){//add remaining values of first half in second half is empty
    temp[count] = data[pos1];
    pos1++;
    count++;
  }
  while(pos2 <= right){//add remaining values of second half if first half is empty
    temp[count] = data[pos2];
    pos2++;
    count++;
  }
  for(int k = left; k < count; k++){//place data in correct location in original array
    data[k] = temp[k];
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
  mergeSort(myList);
  
  cout << "Sorted: " << endl;
  printList(myList);
  
  
  return 0;
}
