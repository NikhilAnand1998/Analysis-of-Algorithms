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
  *Description: This function reads the textfile data.txt and populates a vector called myArray with the integers from that file.
  *It then calls the function insertionSort and passes the vector and the size of the vector. After this it prints out the sorted vector.
 */
int main () {

fstream data_file;                            //Creates a name for opening my datafile named data_file
data_file.open("data.txt");                   //opens data.txt
ofstream write_file;
write_file.open("insert.out");
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

      insertionSort(myArray, size);

                                        //Writes the sorted array to the output file by looping through the vector for size of the vector.
      for(int i =0; i <size; i++){
          write_file<<myArray[i]<<" ";
        }
        write_file<<endl;
        myArray.clear();

  }
    write_file.close();
    data_file.close();

return 0;
}
