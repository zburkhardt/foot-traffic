#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;


   // io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20


int main() {
  int reader1;
  // int roomA=0;
  // int roomB=0;
   int entranceIn=0;
   int entranceOut=0;
   int roomBIn=0;
   int roomBOut=0;
   int emergency=0;
   int jump=0;
  /* if(reader1==0)
   {
       roomAIn++;
       cout<<"number of the people in the room"<<roomAIn<<endl;

   }
   else if(reader1==1)
   {
       roomAOut++;
       cout<<"number of people who just left"<<roomAOut<<endl;
   }
   */
   while(jump==0){
   cout<<"enter the number";
   cin>>reader1;
   switch(reader1)
   {
    case 0:
        entranceIn++;
        cout<<"number of the people who are the building"<<entranceIn<<endl;
        break;
    case 1:
        entranceOut++;
        entranceIn--;
        cout<<"number of people who just left the building"<<entranceOut<<endl;
         cout<<"number of people who are in the building the building"<<entranceIn<<endl;
        break;
    case 2:
        roomBIn++;
        cout<<"number of the people who came into the office"<<roomBIn<<endl;
        break;
    case 3:
        roomBOut++;
        roomBIn--;
         cout<<"number of the people who left the room"<<roomBOut<<endl;
         break;
    };
    cout<<"is there an emergency"<<endl;
    cin>>emergency;

    if (emergency==1)
    {
        jump=1;
    };
   };











    return 0;
}

