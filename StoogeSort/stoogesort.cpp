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

  fstream data_file;                            //Creates a name for opening my datafile named data_file
  data_file.open("data.txt");                   //opens data.txt
  ofstream write_file;
  write_file.open("stooge.out");

  int a;
  int size;
  vector<int>myArray;                          //creates a vector of type int
  while (data_file >> a)
    {
        size = a;                             //This while loop goes through the data file and pushes the values onto my vector while there is a integer that exists in the file
        for(int x = 0; x<size;x++){
          data_file>>a;
          myArray.push_back(a);

        }



        stoogeSort(myArray,0,size-1);       //calls stoogeSort function with array, initial index, and ending index

        myArray.clear();                   //clears vector
        for(int i =0; i <size; i++){       //uses for loop to write the sorted arrays to the output file
            write_file<<myArray[i]<<" ";
          }
          write_file<<endl;
}
        return 0;

}
