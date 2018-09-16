/****************************************************
**Program: act.cpp
**Author: Nikhil Anand
**Date: 7/21/2018
**Input: act.txt
**Output:
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


/*
  *Description: This function implements the greedy algorithm based on the selection criteria of "Last starting time".
  * This function gets passed in a vector with starting times, a vector with activity numbers, the size of the vectors, and an
  * empty vector for which to fill with the answer to the problem. It assumes that the vectors are in sorted order by the last starting time.
  * It first puts in the first activity in the list because that is what the greedy choice is. Then it checks if the next item in the lists have a ending time
  * that is before or equal to the starting time of the previous selected item, if it is it adds it to the answer vector otherwise it moves on to the next item.
 */
void MaxActivities (vector<int>s,vector<int>f,vector<int>Activity,int n, vector<int>&Answer){
int i = 0;

Answer.push_back(Activity[i]);

for(int j =1; j < n;j++)
{
  if(f[j]<=s[i])
  {
    Answer.push_back(Activity[j]);
    i = j;
  }
}



}
/*
  *Description: This function runs the insertionSort on the unsorted array that is created from the data.txt file.
  *It takes in the vector of the array called data_array in this function, and takes in the size of the vector as the parameters.
  *It runs the insertion sort to sort the vector and uses pass by reference to make sure that it is changed outside of the scope of this function.
 */
void insertionSort (vector<int> &data_array, int sizes,vector<int> &activityNumb, vector<int> &finish){

  int i;
  int holder;
  int holder1;
  int holder2;
  int comparer;

for(i = 1; i<sizes;i++)
{
  holder = data_array[i];                           //Takes the first "unsorted element" in the vector
  holder1 = activityNumb[i];
  holder2 = finish[i];
  comparer = i-1;                                   //The comparer variable gets set to the index of the last "sorted" element
  while(comparer >= 0 && data_array[comparer] < holder)       //this while loop runs as long as the index for the last sorted element is greater than or equal to 0 and that value is larger than the unsorted element
  {
    data_array[comparer+1] = data_array[comparer];           //This loop shifts the elements to the right to make room for the unsorted element
    activityNumb[comparer+1] = activityNumb[comparer];
    finish[comparer+1] = finish[comparer];
    comparer = comparer -1;
  }
  data_array[comparer+1] = holder;                            //This puts the unsorted element into its sorted position
  activityNumb[comparer+1]=holder1;
  finish[comparer+1] = holder2;
}



}
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

/*
  *Description: This main function reads in values from the act.txt file, it stores the first value in the file as the activity number, then the next as the start value,
  * and the third as the finish time. Then repeats this for every line. It also stores the top value as the number of activities so it knows how many times to repeat the for loop.
  *Next it copies the activity number vector into a temp vector called Number_Copy, then it calls a mergesort to sort the activities from 1---n, then it compares the sorted
  * Vector with the number_copy vector which is unsorted and when it notices disrepencies it switches the start and finish values thus insurring that the correct start and finish times
  * are indexed with the correct activity number. It then calls an insertion sort and merge sort which changes all three vectors in order of decreasing sorting times, and makes sure they
  * are indexed correctly, as anytime theres a start switch it changes those indexes for the other two vectors. Then it calls the max activities function, and reverses the answer because it is
  * stored in the reverse order that you would do the activities since the search criteria is based on last starting time. Then it prints the result.
 */
int main () {

fstream data_file;                            //Creates a name for opening my datafile named data_file
data_file.open("act.txt");                   //opens data.txt
int temp;
int temp_index;
int temp2;
int a;
int y;
int set_numb =1;
int numb_activities;
vector<int>Start;                      //creates a vector of type int
vector<int>Finish;
vector<int>ActivityNumber;
vector<int>Number_Copy;
vector<int>Answer;
while (data_file >> a)
  {
      numb_activities = a;                             //This while loop goes through the data file and pushes the values onto my vector while there is a integer that exists in the file

      for(int x = 0; x<numb_activities;x++){
        data_file>>a;
        ActivityNumber.push_back(a);
        data_file>>a;
        Start.push_back(a);
        data_file>>a;
        Finish.push_back(a);

      }
      for(int i =0; i<numb_activities;i++){
          y = ActivityNumber[i];
          Number_Copy.push_back(y);
      }
      mergesort(ActivityNumber,0, numb_activities-1);

      for(int i =0;i<numb_activities;i++){

          if(ActivityNumber[i] != Number_Copy[i]){

            temp_index = Number_Copy[i]-1;
            temp = Start[i];
            temp2 = Start[temp_index];
            Start[i] = temp2;
            Start[temp_index] = temp;
            //
            temp = Finish[i];
            temp2 = Finish[temp_index];
            Finish[i] = temp2;
            Finish[temp_index] = temp;
            //
            temp = ActivityNumber[i];
            temp2 = ActivityNumber[temp_index];
            Number_Copy[i] = temp;
            Number_Copy[temp_index] = temp2;

          }
      }
        insertionSort(Start, numb_activities,ActivityNumber,Finish);
        MaxActivities(Start,Finish, ActivityNumber,numb_activities,Answer);
        reverse(Answer.begin(),Answer.end());
        cout<<"Set "<<set_numb<<endl;
        cout<<"Number of activities selected = "<<Answer.size()<<endl;
        cout<<"Activities: ";
        for(int k =0; k<Answer.size();k++){
          cout<<Answer[k]<<" ";
        }
        cout<<endl<<endl;






      Start.clear();
      Finish.clear();
      ActivityNumber.clear();
      Number_Copy.clear();
      Answer.clear();
      set_numb++;

  }

    data_file.close();

return 0;
}
