#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "localtypes.h"
#include <iomanip>

using namespace std;

void DumpMessageAndCRC(const string &fname, const uint16 crc, const vector<uint08> &message)
{
    fstream fs;
    fs.open(fname.c_str(), fstream::out);
    fs <<"\t\t\t\tFile: " << fname.c_str() << endl;
    fs << "Message size " << message.size()<<'\n';
    fs << "Message bytes:\n{\n";
    for (int i = 0, col = 1; i < message.size(); i++, col++)
    {
        if (col%16 == 1)
        {
            fs << std::hex << i << "-->\t";
        }
        
        fs << "0x"<< std::hex << (uint16)message[i] <<", ";
        if (col  == 16)
        {
            col = 0;
            fs<<'\n';
        }
    }
    fs << "\n}\n--------------------------\n";
    fs<< "\t\tCRC = 0x"<< std::hex << setfill('0') << setw(4) << crc <<endl;
}
