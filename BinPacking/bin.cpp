/****************************************************
**Program: bin.cpp
**Author: Nikhil Anand
**Date: 8/14/2018
**Input: bin.txt
**Output: Prints in console
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <climits>
#include <queue>

using namespace std;

/*
  *Description: This function takes in the vector with the weights, the number of weights given "size", and the capacity of the begins
  * Begins by setting the number of bins to 0, then it creates an array to keep the space left in the bins of size n bins.
  * The for loop puts the items into the bin, by first checking which bin can take the item, and places it in. It keeps track of the weights of the begins
  * It also has the bottom if statement that adds a new bin if it can't fit.
 */
int first_fit(vector<int> data_array,int size, int capacity){

  int number_of_bins = 0;

  int leftover[size];
  for(int i=0; i<size;i++){

    int x;
    for(x=0;x<number_of_bins;x++){
        if(leftover[x]>=data_array[i])
        {
          leftover[x] = leftover[x] - data_array[i];
          break;

        }
    }

    if(x==number_of_bins){
      leftover[number_of_bins] = capacity-data_array[i];
      number_of_bins++;
    }

  }
  return number_of_bins;
}
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
  while(comparer >= 0 && data_array[comparer] < holder)       //this while loop runs as long as the index for the last sorted element is greater than or equal to 0 and that value is larger than the unsorted element
  {
    data_array[comparer+1] = data_array[comparer];           //This loop shifts the elements to the right to make room for the unsorted element
    comparer = comparer -1;
  }
  data_array[comparer+1] = holder;                            //This puts the unsorted element into its sorted position
}
}
/*
  *Description: This function calls the insertionSort function to sort the data in decreasing order
  * Then it calls the first_fit function with the sorted data to get a new result, it then returns this result.
 */
int Decrease(vector<int> &data_array,int size, int capacity){


  insertionSort(data_array, size);


  return first_fit(data_array,size,capacity);
}
/*
  *Description: This function runs reads the bin.txt file to get the results of part b, it first reads in the first line of the bin.txt data_file
  * This tells you how many test cases there will be, which is used for displaying the results. Then it begins a while loop that goes until the file is completely read
  * This while loop begins by taking in the capacity, then the number of weights given, then uses the number of weights given to run a for loop that fills a vector with the weights.
  * Then it calls the firstFit function and the Decreasing function and prints the results. And clears the vector for the next test case.
  * For part c this function randomly generates 1000 test cases within a for loop, that repeats 1000 times. It begins by randomly generating a capicity value between 1 and 100, and a size value between 1 and 50
  * Then it fills the vector with size # of elements, using a random generater to create digits that are lower than the capacity which is the condition for the weights.
  * Then it calls the two functions, compares the results and tallies whether the results were the same, or FirstFit had a greater result. Then it prints out the results for part C.
 */
int main () {

  fstream data_file;                            //Creates a name for opening my datafile named data_file
  data_file.open("bin.txt");                   //opens data.txt
  int test_case;
  // ofstream output_file;
  // output_file.open("test.txt");
  int capacity;
  int size;
  vector<int>weights;
  int a;
int tie = 0;
int one_more = 0;
int two_more =0;

  srand(time(NULL));
                              //This while loop goes through the data file and pushes the values onto my vector while there is a integer that exists in the file
  data_file>>a;
  test_case = a;
  int answer1;
  int answer2;
  // for(int g = 0; g<test_case;g++){
  int g =1;

  while (data_file >> a)
    {

        capacity = a;
        data_file>>a;
        size = a;
        for(int i =0; i <size;i++){
          data_file>>a;
          weights.push_back(a);
        }

        // cout<<"The capacity of the data set: "<<capacity<<endl;
        // cout<<"The size of the data set is:" <<size<<endl;
        // cout<<"The weights are:...."<<endl;

        answer1 = first_fit(weights,size,capacity);


        answer2 = Decrease(weights,size,capacity);
        cout<<"TestCase "<<g<< " FirstFit:"<<answer1<<" - FirstFitDecreasing: "<<answer2<<endl;
        weights.clear();
        g++;
      }
      cout<<"________________________________"<<endl;
      cout<<"_____________PART C_____________"<<endl;
      for(int i =0;i<1000;i++){

        capacity = rand()%100+ 1;
        size = rand()%50+1;
        for(int x=0;x<size;x++){
          a = rand()%capacity;
          weights.push_back(a);
        }
        answer1 = first_fit(weights,size,capacity);
        answer2 = Decrease(weights,size,capacity);
        if(answer1 == answer2){
          // cout<<"its a tie!"<<endl;
          tie++;
        }
        else if(answer1>answer2){
          // cout<<"ONE IS GREATER!"<<endl;
          one_more++;
        }


        // cout<<"TestCase "<<i+1<< " FirstFit:"<<answer1<<" - FirstFitDecreasing: "<<answer2<<endl;

        weights.clear();
      }
      cout<<"It was a tie: "<<tie<< " out of 1000 times."<<endl;
      cout<<"firstFit was greater: "<<one_more<< " out of 1000 times."<<endl;



}
