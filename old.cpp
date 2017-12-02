#include <iostream>
#include <limits>
#include <vector>
#include "localtypes.h"

using namespace std;


//RandomFillSurface()
template <typename T>
void FillSurface(Frame1d<T> *pSurf, PatternType pat)
{
    for (UINT32 i = 0; i < pSurf->size(); i++)
    {
        switch(pat)
        {
            case PatternType::ASCENDING:
                (*pSurf)[i] = i;
                break;
            case PatternType::DESCENDING:
                (*pSurf)[i] = pSurf->size() - i;
                break;
            case PatternType::RANDOM:
            default:
                printf("Unsupported filler type %u\n",
                        static_cast<UINT32>(pat));
                return;
        }
    }
    return;
}

template <typename T>
void PrintSurface(const Frame1d<T> surf)
{
    printf("dumping the surface:\n");
    int c = 1;
    for (auto &i : surf)
    {
        printf(" 0x%04x,", static_cast<UINT32>(i));
        if (c == 16)
        {
            printf("\n");
            c = 1;
        }
        else
        {
            c++;
        }
    }
}

int main()
{
    //CASE 0:
    Frame1d<UINT16> s0(32);
    FillSurface(&s0, PatternType::ASCENDING);
    PrintSurface(s0);

    //printf("size of s0 %u\n", static_cast<UINT32>(s0.size()));
    return 0;
}


