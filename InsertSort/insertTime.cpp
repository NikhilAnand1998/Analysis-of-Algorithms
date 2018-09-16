/****************************************************
**Program: Insertsort.cpp
**Author: Nikhil Anand
**Date: 6/29/2018
**Input: Data.txt
**Output: Insert.out
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

/*
  *Description: This function runs the insertionSort on the unsorted array that is created from the data.txt file.
  *It takes in the vector of the array called data_array in this function, and takes in the size of the vector as the parameters.
  *It runs the insertion sort to sort the vector and uses pass by reference to make sure that it is changed outside of the scope of this function.
 */
void insertionSort (vector<int> &data_array, int sizes){

  int i;
  int holder;
  int comparer;

for(i = 1; i<sizes;i++)
{
  holder = data_array[i];                           //Takes the first "unsorted element" in the vector
  comparer = i-1;                                   //The comparer variable gets set to the index of the last "sorted" element
  while(comparer >= 0 && data_array[comparer] > holder)       //this while loop runs as long as the index for the last sorted element is greater than or equal to 0 and that value is larger than the unsorted element
  {
    data_array[comparer+1] = data_array[comparer];           //This loop shifts the elements to the right to make room for the unsorted element
    comparer = comparer -1;
  }
  data_array[comparer+1] = holder;                            //This puts the unsorted element into its sorted position
}



}
/*
  *Description: This function creates random integers between 0 and 10000 and populates a vector called myArray with the integers.
  *It then calls the function insertionSort and passes the vector and the size of the vector. After this it prints out the size of the vector and runtime of the algorithm, then repeats with numbers from 5000 to 70000.
 */
int main () {



int a;
int size;
srand (time(NULL));
clock_t start,stop;
vector<int>myArray;                          //creates a vector of type int
                           //This for loop makes the program repeat for numbers ranging from 5000-70000 at 5000 size intervals.
      for(size = 5000; size<=70000;size+=5000){


      for(int x = 0; x<size;x++){                       //this for loop populates the vector with random numbers.
        a = rand() % 10000;
        myArray.push_back(a);
      }


        start=clock();                                    //starts the timer
      insertionSort(myArray, size);                       //calls the sorting algorithm
        stop=clock();                                     //stops the timer

        cout<<"The time it took to sort: "<<size<< " Elements was: "<< (stop-start)/(CLOCKS_PER_SEC/1000)<<" Miliseconds."<<endl;                   //prints out the information
        myArray.clear();                                  //clears the vector and loops back if the size was under 70000

}

return 0;
}
