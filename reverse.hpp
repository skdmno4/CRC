#pragma once
#include <string>
#include <vector>
#include "localtypes.h"
using namespace std;

template <typename T>
void ReverseBits(const T vIn, T *pvOut)
{
    T tmp = vIn;
    T vOut = 0;
    const uint32 bits = sizeof(T) * 8;
    for(uint32 i = 0; i < bits && tmp; i++)
    {
        vOut |= (tmp & 1 << (bits - 1)) ? 1 << i : 0;
        tmp <<= 1;
    }
    //printf("vIn 0x%0x vOut 0x%0x\n", vIn, vOut);
    *pvOut = vOut;
}

bool testReverse16Bits()
{
    vector <uint16> inVec;
    vector <uint16> revVec;
    vector <uint16> resVec;
    
    inVec.push_back(10);
    revVec.push_back(20480);

    inVec.push_back(127);
    revVec.push_back(65024);

    inVec.push_back(0);
    revVec.push_back(0);

    inVec.push_back(8);
    revVec.push_back(4096);

    inVec.push_back(128);
    revVec.push_back(256);

    for (auto &in : inVec)
    {
        uint16 out;
        ReverseBits<uint16>(in, &out);
        resVec.push_back(out);
    }

    bool status = true;
    for (uint32 i = 0; i < revVec.size(); i++)
    {
        string r = revVec[i] == resVec[i] ? "==" : "!=";
        printf ("[%u]: result %u %s rev %u\n", i, resVec[i], r.c_str(), revVec[i]);
        status = revVec[i] == resVec[i];
    }
    return status;
}
bool testReverse8Bits()
{
    vector <uint08> inVec;
    vector <uint08> revVec;
    vector <uint08> resVec;
    
    inVec.push_back(10);
    revVec.push_back(80);

    inVec.push_back(127);
    revVec.push_back(254);

    inVec.push_back(0);
    revVec.push_back(0);

    inVec.push_back(128);
    revVec.push_back(1);

    for (auto &in : inVec)
    {
        uint08 out;
        ReverseBits<uint08>(in, &out);
        resVec.push_back(out);
    }

    bool status = true;
    for (uint32 i = 0; i < revVec.size(); i++)
    {
        string r = revVec[i] == resVec[i] ? "==" : "!=";
        printf ("[%u]: result %u %s rev %u\n", i, resVec[i], r.c_str(), revVec[i]);
        status = revVec[i] == resVec[i];
    }
    return status;
}


