#pragma once
#include <vector>
#include "localtypes.h"

using namespace std;

template <typename T>
void FillWalkingOnes(vector<T> *pmessage, const uint32 numElems)
{
    T x = 1;
    bool shiftdir = true;
    for (int i = 0; i < numElems; i++)
    {
        if (x == 0)
        {
            shiftdir = (shiftdir) ? false : true;
            x = shiftdir ? 1 : 1 << 7*sizeof(T);
        }
        x = (shiftdir) ? x << 1 : x >> 1;
        (*pmessage)[i] = x;
    }
}

template <typename T>
void FillWalkingZeros(vector<T> *pmessage, const uint32 numElems)
{
    T x = 1;
    bool shiftdir = true;
    for (int i = 0; i < numElems; i++)
    {
        if (x == 0)
        {
            shiftdir = (shiftdir) ? false : true;
            x = shiftdir ? 1 : 1 << 7*sizeof(T);
        }
        x = (shiftdir) ? x << 1 : x >> 1;
        (*pmessage)[i] = ~static_cast <T>(0) ^ x;
    }

}
