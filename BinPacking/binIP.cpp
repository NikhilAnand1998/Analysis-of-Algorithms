/****************************************************
**Program: binIP.cpp
**Author: Nikhil Anand
**Date: 8/14/2018
**Input: binEC.txt
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
#include <stdio.h>
#include <stdlib.h>

using namespace std;







int main () {

  fstream data_file;                            //Creates a name for opening my datafile named data_file
  data_file.open("bin.txt");                   //opens data.txt
  int test_case;
  ofstream output_file;
  string filestart = "testcase";
  string filetype = ".ltx";                   //I use these strings to construct the file names so that I can output the data to testcase1, testcase2, and testcase3
  string filename;
  int numbers=1;
  ostringstream temp;

  int capacity;
  int size;
  vector<int>weights;
  int a;



  data_file>>a;
  test_case = a;
  int answer1;
  int answer2;
  int g =1;

  while (data_file >> a)                         //This while loop reads from the file while there is lines that exist
    {

        capacity = a;
        data_file>>a;
        size = a;
        for(int i =0; i <size;i++){
          data_file>>a;
          weights.push_back(a);
        }

        for(int i =0; i<size;i++){
          output_file<<weights[i]<<" ";
        }
        output_file<<endl;
        weights.clear();
        g++;

      filestart = "testcase";                     //this puts together the file name that will be outputted to
      filetype = ".ltx";
      temp<<numbers;
      string filenumber = temp.str();
      filename = filestart + filenumber+ filetype;
      temp.str("");
      temp.clear();
      output_file.open(filename.c_str());

output_file<<"min       ";                                //the following lines create the output for the lindo code using simple print statements and loops
for(int i=1;i<=size;i++){
  if(i != size){
    output_file<<"Y"<<i<<" + ";
  }
  else
    output_file<<"Y"<<i;
}
output_file<<endl<<endl;
output_file<<"ST"<<endl;
output_file<<"    ";
for(int i=1;i<=size;i++){
  if(i != size){
    output_file<<"Y"<<i<<" + ";
}
else
  output_file<<"Y"<<i;
}
output_file<<" >= 1"<<endl;
output_file<<endl<<endl;

for(int i=1;i<=size;i++){
  output_file<<"    ";
  for(int j =1;j<=size;j++){
    if(j != size){
    output_file<<weights[j-1]<<"X"<<i<<j<<" + ";
  }
  else{
    output_file<<weights[j-1]<<"X"<<i<<j<<" -"<<capacity<<"Y"<<i<<"  <= 0";

  }
}
 output_file<<endl;
}
output_file<<endl<<endl;

for(int i=1;i<=size;i++){
  output_file<<"    ";
  for(int j =1;j<=size;j++){
    if(j != size){
    output_file<<"X"<<j<<i<<" + ";
  }
  else{
    output_file<<"X"<<j<<i;
  }
}
 output_file<<"   = "<<1<<endl;
}

output_file<<endl<<endl;

for(int i=1;i<=size;i++){
  output_file<<"    "<<"Y"<<i<<" >= 0"<<endl;
}
output_file<<endl<<endl;
for(int i=1;i<=size;i++){
  output_file<<"    "<<"Y"<<i<<" <= 1"<<endl;
}
output_file<<endl<<endl;
for(int j = 1;j<=size;j++){
for(int i =1; i<=size;i++){
  output_file<<"    "<<"X"<<j<<i<<"  >= 0  "<<endl;
}
output_file<<endl<<endl;
}

for(int j = 1;j<=size;j++){
for(int i =1; i<=size;i++){
  output_file<<"    "<<"X"<<j<<i<<"  <= 1  "<<endl;
}
output_file<<endl<<endl;
}

output_file<<endl;
output_file<<"END"<<endl<<endl;

for(int i =1;i<=size;i++)
{
  output_file<<"   GIN Y"<<i<<endl;
}
output_file<<endl;
for(int j = 1;j<=size;j++){
for(int i =1; i<=size;i++){
  output_file<<"   GIN X"<<j<<i<<endl;
}
output_file<<endl<<endl;
}

numbers++;                                      //increases numbers, so that the outputs print to file 1,2,3 etc..
output_file.close();
}


}
