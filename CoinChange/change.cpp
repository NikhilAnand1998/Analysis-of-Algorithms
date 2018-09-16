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
/*
  *Description: This is a dynamic programming algorithm that finds the minimum coins needed
  * to make change for a value. It takes in the coin denominations vector, number of coins, value we are making change off
  * and a temp array that will be filled with the results of how many of each coin is needed to make the change.
 */
int minCoins(vector<int> &data_array, int numb_coins, int value,vector<int> &tempCoins){

vector<int>numb_coins_used;
int hold;
//The table holds the minimum number of coins need (return value for the function)
int table[value+1];
int numb_coins_array[value+1];
table[0] = 0;                   //base case used if Value is 0

for(int i=1; i<=value;i++){                   //Initializes table values to infinite
  table[i]=INT_MAX;
  numb_coins_array[i]=-1;
}
//calculates the minimum number of coins needed for all values 1 to value
for(int i =1;i<=value;i++){
//only looks at coins that are smaller than the actual value we are looking for.
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
//filling the array with the minimum coins used for each denomination. 
if(numb_coins_array[value]==-1)
{
  cout<<"No possible coins "<<endl;
}
else
{
  int start =value;
  int X[numb_coins];
  for(int h =0;h<numb_coins;h++)
  {
    X[h] = 0;
  }
  while(start !=0)
  {
    int j = numb_coins_array[start];
    X[j]++;
    start = start-data_array[j];
  }
  for(int i =0; i < numb_coins;i++)
  {
    hold = X[i];
    tempCoins.push_back(hold);


  }

}

return table[value];
}


/*
  *Description: This function reads the textfile amoutn.txt and populates a vector called myArray with the integers from that file.
  * It then takes the next line and inserts that value into a vector called tempArray, which is the value we are trying to make change for.
  * Then the function mincoins is called, and then the results are written to an output file called change.txt
 */
int main () {

fstream data_file;                            //Creates a name for opening my datafile named data_file
data_file.open("amount.txt");                   //opens data.txt
ofstream write_file;
write_file.open("change.txt");
int a;                                          //initializes variables and vectors
int size_of_coins;
int value;
string line;
int size;
int answer;
vector<int>myArray;                          //creates a vector of type int
vector<int>tempArray;
vector<int>valueArray;
vector<int>temp_coins_used;


while(getline(data_file,line))                  //while there exists lines left in the file
  {
      istringstream converter(line);           //stores the line as a string, and then converts it to a int
        while(converter>>a){

          myArray.push_back(a);               //stores the numbers into the array

          }
          getline(data_file,line);            //stores the next line which is the value, into another temp array
          istringstream converter2(line);
            while(converter2>>a){}
              tempArray.push_back(a);

          value = tempArray[0];                 //gets the value of the temp array
          size_of_coins = myArray.size();        //gets the size of the array, which is the number of coins used
          answer = minCoins(myArray,size_of_coins,value,temp_coins_used);           //calls function, which has a return value of the minimum number of coins used
          for(int i =0; i <myArray.size(); i++){                                    //prints out the coin denomenations
              write_file<<myArray[i]<<" ";
            }
            write_file<<endl;
            write_file<<value<<endl;                                                //prints out value we are trying to find

            for(int x =0; x <temp_coins_used.size(); x++){                        //prints out number of each coin used
              write_file<<temp_coins_used[x]<<" ";
            }
            write_file<<endl;

             write_file<<answer<<endl;

                myArray.clear();                                                    //clears vectors for next iteration of loop
                tempArray.clear();
                temp_coins_used.clear();


              }




    write_file.close();
    data_file.close();

return 0;
}
