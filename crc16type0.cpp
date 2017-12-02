#include <iostream>
#include <bitset>
#include <iomanip>
#include "localtypes.h"
#include "reverse.hpp"
#include "logCrc.hpp"
#include "fillTestVec.hpp"

//GP = x^16 + x^5 + x^3 + x^2 + 1 =  0x10025
using namespace std;

uint16 Crc16(uint08 * pMessage, uint32 numBytes, uint16 GP)
{
    uint16 byte = 0;
    uint16 crc = 0xFFFF;

    for (uint32 i = 0; i < numBytes; i++)
    {
        uint16 tmp_2B = pMessage[i];
        ReverseBits<uint16>(tmp_2B, &byte);
        cout << "Work upon byte: " << std::hex << (uint32)pMessage[i] <<
            " ~byte: " << std::hex << (uint32)byte;
        for (uint32 j = 0; j < 8; j++)
        {
            if ((int16)(crc ^ byte) < 0)
            {
                crc = (crc << 1) ^ GP;
            }
            else
            {
                crc <<= 1;
            }
            byte <<= 1;
        }
        cout <<"\t~CRC till byte "<< i<< ": 0x"
            << std::hex << setfill('0') << setw(4) << crc << '\n';
    }
    uint16 nc = 0;
    //ReverseBits<uint16>(crc, &nc);
    ReverseBits<uint16>(~crc, &nc);
    return nc;
}

void testCRC()
{

    uint32 crc = 0;
    cout << "Test All 8 zeros\n";
    vector <uint08> me_all_0(8, 0);
    crc = Crc16(&me_all_0[0], me_all_0.size(), 0x25);
    cout << "CRC = 0x" << std::hex << crc << endl;
    DumpMessageAndCRC("All8Zeros.txt", crc, me_all_0);

    cout << "Test All 8 bytes = 0xFF\n";
    vector <uint08> me_all_0x1(8, 0xFF);
    crc = Crc16(&me_all_0x1[0], me_all_0x1.size(), 0x25);
    cout << "CRC = 0x" << std::hex << crc<< endl;
    DumpMessageAndCRC("All8_FF.txt", crc, me_all_0x1);
/*
    cout << "Test 32 bytes all #\n";
    vector <uint08> me_all_0x23(32, 35);
    crc = Crc16(&me_all_0x23[0], me_all_0x23.size(), 0x25);
    cout << "CRC = 0x" << std::hex << crc<< endl;
    DumpMessageAndCRC("All8_0x23.txt", crc, me_all_0x23);

    cout << "Walking ones 32 bytes\n";
    vector <uint08> me_all_w1s(32, 0);
    FillWalkingOnes<uint08>(&me_all_w1s, 32);
    crc = Crc16(&me_all_w1s[0], me_all_w1s.size(), 0x25);
    cout << "CRC = 0x" << std::hex << crc<< endl;
    DumpMessageAndCRC("All32_W_1s.txt", crc, me_all_w1s);

    cout << "Walking Zeroes 32 bytes\n";
    vector <uint08> me_all_w0s(32, 0);
    FillWalkingZeros<uint08>(&me_all_w0s, 32);
    crc = Crc16(&me_all_w0s[0], me_all_w0s.size(), 0x25);
    cout << "CRC = 0x" << std::hex << crc<< endl;
    DumpMessageAndCRC("All32_W_0s.txt", crc, me_all_w0s);
*/
    return;
}

int main()
{
    /*
    string pass = testReverse8Bits() ? "OK": "Not OK";
    printf ("ReverseBits8 func = %s\n", pass.c_str());
    pass = testReverse16Bits() ? "OK": "Not OK";
    printf ("ReverseBits16 func = %s\n", pass.c_str());
    */

    testCRC();

    return 0;
}
