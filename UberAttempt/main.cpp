#include <iostream>
#include <fstream>

using namespace std;

void parseFile();

int roomOneOcc = 0, roomTwoOcc = 0;

int main()
{
    bool jump = false, emergency = false;

    parseFile();

    cout << "Number of people in Room A: " << roomOneOcc << endl;
    cout << "Number of people in Room B: " << roomTwoOcc << endl;
    cout << "----------------" << endl;
    cout << "Total number of people in the building: " << (roomOneOcc + roomTwoOcc) << endl;

	return 0;
}

void parseFile()
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
        cout << "Reading in file data: ";

        string id_tag = "", name = "", room = "", time = "", entry = "";

        // Read in to variables from csv RFID data file
        while (!(getline(fout,id_tag,',').eof())) {
            getline(fout,name,',');
            getline(fout,room,',');
            getline(fout,time,',');
            getline(fout,entry,'\n');

            if (room == "1")
                if (entry == "1")
                    ++roomOneOcc;
                else
                    --roomOneOcc;
            else if (room == "2")
                if (entry == "1")
                    ++roomTwoOcc;
                else
                    --roomTwoOcc;
        }

        fout.close();
        cout << "COMPLETE" << endl << endl;
    }
}
