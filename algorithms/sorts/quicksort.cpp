//QUICK SORT
//Elisabeth Bruesewitz

/*Sorts a vector of ints by recursively partitioning the data/picking a pivot.
Moves all values less than the pivot to the left of it.
Moves all values greater than the pivot to the right of it.

this is done IN PLACE

W(n) = n^2
A(n) = nlogn
B(n) = nlogn
*/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

void quickSort(vector<int>&, int, int);
int partition(vector<int>&, int, int);

void quickSort(vector<int>& data){
  quickSort(data, 0, (data.size() - 1));
}

/*recursively partitions/sorts data.
partition partitions data so all vals lower than pos are to the left and all higher are to the right.
first all values to the left are sorted, then all to the right
*/
void quickSort(vector<int>& data, int low, int high){
  if(high > low){
    int pos = partition(data, low, high);
    quickSort(data, low, pos-1);
    quickSort(data, pos+1, high);
  }
  return;
}

int partition(vector<int>& data, int low, int high){
  int moveright = low;
  int moveleft = high + 1;
  int x = data[low];//our pivot point
  while(moveright < moveleft){//start from either end and work towards each other
    do{
      moveright++;
    }while(data[moveright] < x);//keep moving until data is greater than our pivot
    do{
      moveleft--;
    }while(data[moveleft] > x);//keep moving until data is less than our pivot
    if(moveright < moveleft){//swap values to keep lower values to the left and higher ones to the right.
      int temp = data[moveright];
      cout << temp;
      data[moveright] = data[moveleft];
      data[moveleft] = temp;
    }
  }
  int pos = moveleft;//at this point all data at and before moveleft will be less than the pivot
  data[low] = data[pos];//put this value to the left half of the list
  data[pos] = x;//place the pivot in the "middle"
  return pos;
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
  quickSort(myList);
  
  cout << "Sorted: " << endl;
  printList(myList);
  
  return 0;
}
