/****************************************************
**Program: wrestler.cpp
**Author: Nikhil Anand
**Date: 7/29/2018
**Input: wrestler/1/2.txt
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


struct graph {
  vector<int>vertx;
  vector < vector < int > > Matrix;


};

/*
  *Description: This functions checks to see if the function is bipartite or not, it is called by the isBi_helper function
  * it returns true if it is, if its not it returns false and the main function will print "IMPOSSIBLE". While the queue isn't empty
  * it runs the bfs algorithm and sets the alternating color if an edge exists from v to V and v is uncolored.
 */

bool isBi(graph &graphs, int start,int size,vector<int> &colorArray){

  queue<int>q;
  colorArray[start]=1;



  q.push(start);

  while(!q.empty()){

    int u = q.front();
    q.pop();
    if(graphs.Matrix[u][u]==1)
      return false;

    for(int v = 0; v<size;++v){
      if(graphs.Matrix[u][v]&& colorArray[v]==-1)
      {
        colorArray[v]=1-colorArray[u];
        q.push(v);
      }
      else if(graphs.Matrix[u][v] && colorArray[v]==colorArray[u])
        return false;
    }
  }



  return true;



  }

  /*
    *Description: Sets one to the matrix location that is set by the index's n and v
   */
void addEdge(int v, int n,graph &graphs){
  graphs.Matrix[v][n]=1;
}

/*
  *Description: calls the isBi function, and initializes the colorArray as -1
 */
bool isBi_helper(graph &graphs, int start,int size,vector<int> &colorArray){
  for(int i =0;i<size;++i){
      colorArray.push_back(-1);
  }

for(int i=0; i<size;i++){
  if(colorArray[i]==-1)
    if(isBi(graphs,i,size,colorArray)==false)
      return false;
}
}
/*
  *Description: This functions reads in data from a file which name is taken from the command line.  Then it compares the rivals vectors with the wrestlers vector
  * If they are equal it calls the addEdge function to set the matrix index to 1.
 */
int main (int argc, char* argv[]) {

string filename;
filename = argv[1];
ifstream data_file;                            //Creates a name for opening my datafile named data_file
data_file.open(argv[1]);                   //opens data.txt

struct graph graphs;
int a;
int n=0;
int v = 0;                                       //initializes variables and vectors
int numb_wrestlers;
int numb_rivals;

string line;
int size1;
int size;
string temp1;
string temp2;
string temp3;

vector<string>myArray;                          //creates a vector of type int
vector<string>myRivalsLeft;
vector<string>myRivalsRight;
vector<int>colorArray;
vector<string>babyface;
vector<string>heel;


while(data_file.good() )                  //while there exists lines left in the file
  {
         //stores the line as a string, and then converts it to a int

    data_file>>size;
  numb_wrestlers = size;
  size1 = size;
    graphs.Matrix.assign(size1,vector< int >(size1,0));
    // for (int i = 0; i < graphs.Matrix.size(); i++) {
    //     for (int j = 0; j < graphs.Matrix[i].size(); j++)
    //       cout << graphs.Matrix[i][j] << " ";
    //       cout << endl;
    //         }
  // cout<<"the size is: "<<a<<endl;

          for(int i =0; i <size;i++){
              data_file>>line;
                myArray.push_back(line);               //stores the numbers into the array
          }

          // for(int i =0; i < size;i++){
          //   cout<<myArray[i]<<endl;
          // }
          data_file>>a;
          size = a;
          numb_rivals = size;
          // cout<<"the size is: "<<a<<endl;

            while (data_file >> line) {
            temp1 = line;
            myRivalsLeft.push_back(line);
            data_file>>line;
            temp3 = line;
            myRivalsRight.push_back(line);




          }

          }




          for(int j =0; j<myRivalsLeft.size();j++){
              for(int i=0;i<size1;i++){

                  if( myRivalsLeft[j] == myArray[i]){

                      n=i;
                      }
                  else if (myRivalsRight[j] == myArray[i]){

                        v=i;
                      }
                    }
              addEdge(n,v,graphs);
              addEdge(v,n,graphs);



}




  for (int i = 0; i < graphs.Matrix.size(); i++) {
      for (int j = 0; j < graphs.Matrix[i].size(); j++)
        cout << graphs.Matrix[i][j] << " ";
        cout << endl;
          }
cout<<"-----------"<<endl;


      if(isBi_helper(graphs,0,size1,colorArray)){

        cout<<"Yes Possible"<<endl;
        for(int i =0;i<size1;i++){
            if(colorArray[i] ==1){
                babyface.push_back(myArray[i]);
            }
            else if(colorArray[i]==0){
              heel.push_back(myArray[i]);
            }
        }
        cout<<"Babyfaces: ";
          for(int i =0;i<babyface.size();i++){
            cout<<babyface[i]<< ' ';
          }
          cout<<endl;
          cout<<"Heels: ";
          for(int i =0; i<heel.size();i++){
            cout<<heel[i]<<' ';
          }
          cout<<endl;
      }
      else{
        cout<<"IMPOSSIBLE"<<endl;
      }





    data_file.close();

return 0;
}
