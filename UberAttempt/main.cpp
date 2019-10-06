#include <iostream>
#include <fstream>

using namespace std;
ifstream inFile;

int main()
{
    ifstream fout;
    fout.open("rfidData.csv");

    // Check if file failed to open
    if(!fout.is_open())
    {
        cout << "Error opening data file." << endl;
    }

    else
    {
        cout << "Reading in file data:"
        string id_tag = "", name = "", room = "", time = "";

        // Read in to variables from csv RFID data file
        while (!(getline(fout,id_tag,',').eof())) {
            getline(fout,name,',');
            getline(fout,room,',');
            getline(fout,time,'\n');
        }
    }

	return 0;
}


