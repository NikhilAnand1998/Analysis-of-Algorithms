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
        // int sub_res = table[i-data_array[j]];
        // if(sub_res != INT_MAX && sub_res +1 < table[i]){
        //   temp_numb_used++;
        //   table[i] = sub_res + 1;
        // }
        if(table[i]>1+table[i-data_array[j]])
        {
          table[i]=1+table[i-data_array[j]];
          numb_coins_array[i]=j;
        }

      }

    }

}
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



int main () {

fstream data_file;                            //Creates a name for opening my datafile named data_file
data_file.open("amount.txt");                   //opens data.txt
ofstream write_file;
write_file.open("change.txt");
int a;
int size_of_coins;
int value;
string line;
int size;
int answer;
vector<int>myArray;                          //creates a vector of type int
vector<int>tempArray;
vector<int>valueArray;
vector<int>temp_coins_used;


while(getline(data_file,line))
  {
      istringstream converter(line);
        while(converter>>a){

          myArray.push_back(a);

          }
          getline(data_file,line);
          istringstream converter2(line);
            while(converter2>>a){}
              tempArray.push_back(a);

          value = tempArray[0];
          size_of_coins = myArray.size();
          answer = minCoins(myArray,size_of_coins,value,temp_coins_used);
          for(int i =0; i <myArray.size(); i++){
              cout<<myArray[i]<<" ";
            }
            cout<<endl;
            cout<<value<<endl;

            for(int x =0; x <temp_coins_used.size(); x++){
              cout<<temp_coins_used[x]<<" ";
            }
            cout<<endl;

             cout<<answer<<endl;
              // cout<<endl;
                myArray.clear();
                tempArray.clear();
                temp_coins_used.clear();


              }




    write_file.close();
    data_file.close();

return 0;
}
