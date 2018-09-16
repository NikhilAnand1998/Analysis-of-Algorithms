/****************************************************
**Program: change.cpp
**Author: Nikhil Anand
**Date: 7/14/2018
**Input: amount.txt
**Output: change.txt
****************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <climits>



using namespace std;

int minCoins(vector<int> &data_array, int numb_coins, int value,vector<int> &tempCoins){

vector<int>numb_coins_used;
int hold;
int table[value+1];
int numb_coins_array[value+1];
table[0] = 0;

for(int i=1; i<=value;i++){
  table[i]=INT_MAX;
  numb_coins_array[i]=-1;
}

for(int i =1;i<=value;i++){
    for(int j =0;j<numb_coins;j++){
      if(data_array[j] <= i)
      {

        if(table[i]>1+table[i-data_array[j]])
        {
          table[i]=1+table[i-data_array[j]];
          numb_coins_array[i]=j;
        }

      }

    }

}
// if(numb_coins_array[value]==-1)
// {
//   cout<<"No possible coins "<<endl;
// }
// else
// {
//   int start =value;
//   int X[numb_coins];
//   for(int h =0;h<numb_coins;h++)
//   {
//     X[h] = 0;
//   }
//   while(start !=0)
//   {
//     int j = numb_coins_array[start];
//     X[j]++;
//     start = start-data_array[j];
//   }
//   for(int i =0; i < numb_coins;i++)
//   {
//     hold = X[i];
//     tempCoins.push_back(hold);
//
//
//   }

// }

return table[value];
}



int main () {


int a;                                          //initializes variables and vectors
int size_of_coins;
int value;
string line;
int size= 0;
int answer;
srand (time(NULL));
clock_t start,stop;
vector<int>myArray;                          //creates a vector of type int
vector<int>tempArray;
vector<int>valueArray;
vector<int>temp_coins_used;
int n_size;

// for(size=1000; size<= 15000;size+=1000)                  //while there exists lines left in the file
for(n_size=1000; n_size<= 15000;n_size+=1000)
  {
    size =n_size;
    for(int x =0; x<n_size;x++)
    {
        a = rand()%200;
        a++;                                   //stores coin denominations between 1 and 200
          myArray.push_back(a);               //stores the numbers into the array

          }

              tempArray.push_back(size);

          value = tempArray[0];                 //gets the value of the temp array
          size_of_coins = myArray.size();        //gets the size of the array, which is the number of coins used
          start= clock();
          answer = minCoins(myArray,size_of_coins,value,temp_coins_used);           //calls function, which has a return value of the minimum number of coins used
          stop = clock();
            cout<<"The time it took to calculate value for n and a of size: "<<n_size<< "  was: "<< (stop-start)/(CLOCKS_PER_SEC/1000)<<" Miliseconds."<<endl;
          // for(int i =0; i <myArray.size(); i++){                                    //prints out the coin denomenations
          //     cout<<myArray[i]<<" ";
          //   }
            // cout<<endl;
            // cout<<value<<endl;                                                //prints out value we are trying to find
            //
            // for(int x =0; x <temp_coins_used.size(); x++){                        //prints out number of each coin used
            //   cout<<temp_coins_used[x]<<" ";
            // }




                myArray.clear();                                                    //clears vectors for next iteration of loop
                tempArray.clear();
                temp_coins_used.clear();


              }






return 0;
}
