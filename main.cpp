#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;


   // io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20


int main() {
     //initialie the array size
   int arr[20];
   ifstream is("a.txt");
   int cnt= 0;
   int x;
   // check that array is not already full
   while (cnt < arr[30] && is >> x)
   // and read integer from file
   arr[cnt++] = x;
   // print the integers stored in the array
   cout<<"The integers are:"<<"\n";
   for (int i = 0; i < cnt; i++) {
      cout << arr[i] <<' ';
   }
   //close the file
   is.close();
    return 0;
}

