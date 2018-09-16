/****************************************************
**Program: Mergesort.cpp
**Author: Nikhil Anand
**Date: 6/29/2018
**Input: Data.txt
**Output: Merge.out
**Sources: https://www.geeksforgeeks.org/merge-sort/
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

/*
  *Description: This function runs the merge part of the mergesort. It merges the subvectors created within the mergesort function.
  *The first half being start-middle and the second half is middle+1 - end of the subvector which are stored in temp vectors called firstArray and secondArray.
  *It first compares the first element in the subvectors until one of the subarrays is empty.
  *Then it goes in and fills the rest of the vector with the subvector that wasn't emptied during the first part.
 */
void merge(vector<int> &data_array, int start,int middle, int end){


  int first_half = middle-start+1;
  int second_half = end-middle;

vector<int>firstArray;
vector<int>secondArray;
  for(int i =0; i<first_half;i++){
    firstArray.push_back(data_array[i+start]);
  }
  for(int x =0; x<second_half;x++){
    secondArray.push_back(data_array[x+middle+1]);   // ERROR
  }


int i = 0;
int x = 0;
int j = start;

while(i <first_half && x < second_half){
  if(firstArray[i]<= secondArray[x])
  {

    data_array[j]=firstArray[i];
    i++;
  }
  else{
    data_array[j]=secondArray[x];
    x++;
  }
  j++;
}
while(i <first_half){
  data_array[j] = firstArray[i];
  i++;
  j++;
}
while(x <second_half){
  data_array[j] = secondArray[x];
  x++;
  j++;
}
firstArray.clear();
secondArray.clear();


}

/*
  *Description: The mergesort function uses recursion to split the vectors by providing different indexes by which to sort them later.
  *The recursion works until the start is equal to or greater than the ending index which means that the vector has been split into 1 and 1's which is what this function is trying to acomplish.
  *Once the first half of the vector is split into 1 and 1's then the second half of the vector will be split with the second mergesort call, and finally once the second half is also split into 1 and 1's.
  *The merge function pieces all the subvectors back together in sorted order.
 */
void mergesort(vector<int> &data_array, int start, int end){




  if(start < end)
  {
  int middle = (start+end)/2;
  //splitting the first half of the vector
  mergesort(data_array, start, middle);
  //Splitting the second half of the vector

  mergesort(data_array,middle+1,end);
//Merge Function call
  merge(data_array,start,middle,end);
}
}


int main () {


  int a;
  int size =70000;
  srand(time(NULL));
  clock_t start,stop;
  vector<int>myArray;                          //creates a vector of type int
for(size=5000;size<=70000;size+=5000){         //This for loop makes the program repeat for numbers ranging from 5000-70000 at 5000 size intervals.


  for(int x = 0; x<size;x++){                  //this for loop populates the vector with random numbers.
    a = rand() % 10000;
    myArray.push_back(a);
  }
        start = clock();                      //starts clock.
        mergesort(myArray,0, size-1);         //calls sorting algorithm
        stop=clock();                         //stops clock.


          cout<<"The time it took to sort: "<<size<< " Elements was: "<< (stop-start)/(CLOCKS_PER_SEC/1000)<<" Miliseconds."<<endl;
          myArray.clear();                    //clear array.

}

  return 0;
}
