/****************************************************
**Program: stoogesort.cpp
**Author: Nikhil Anand
**Date: 7/5/2018
**Input: Data.txt
**Output: stooge.out
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

void stoogeSort(vector<int> &data_array, int start,int n)
{
if(start >= n){                                             //if the size of the array is 1 then return
return;
}

if( data_array[start]>data_array[n]){                      //if the first element is bigger than the last then swap them
  swap(data_array[start],data_array[n]);                   //swaps elements using built in function

}
 if((n-start+1)> 2){                                      //same as saying if  (n>2) prevents seg fault

  int m = ceil(((n-start)+1)/3);                          //gets 1/3 of the size to equal m
  stoogeSort(data_array,start,n-m);                       //sorts first 2/3 elements ranging from 0 to n-(1/3 size of array)
  stoogeSort(data_array,start+m,n);                       //sorts last 2/3 elements ranging from start+1/3 size of array to end
  stoogeSort(data_array,start,n-m);                       //re sorts the first 2/3 elements ranging from 0 to (n-1/3 size of the array)

}




}


int main(){


  srand (time(NULL));
  clock_t start,stop;

  int a;
  int size;
  vector<int>myArray;
                         //creates a vector of type int
  for(size = 500; size<=7000;size+=500){


  for(int x = 0; x<size;x++){                       //this for loop populates the vector with random numbers.
    a = rand() % 10000;
    myArray.push_back(a);
  }


        start = clock();
        stoogeSort(myArray,0,size-1);       //calls stoogeSort function with array, initial index, and ending index
        stop = clock();

            myArray.clear();                   //clears vector
          cout<<"The time it took to sort: "<<size<< " Elements was: "<< (stop-start)/(CLOCKS_PER_SEC/1000)<<" Miliseconds."<<endl;                   //prints out the information
}
        return 0;

}
