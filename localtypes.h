#pragma once
#include <vector>
typedef short int       int16;
typedef int             int32;
typedef char            int08;
typedef long long int   int64;
typedef unsigned short int     uint16;
typedef unsigned int           uint32;
typedef unsigned char          uint08;
typedef unsigned long long int uint64;


template <typename T>
using Frame1d = std::vector<T>;
template <typename T>
using Frame2d= std::vector<std::vector<T>>;

enum class PatternType
{
    RANDOM,
    ASCENDING,
    DESCENDING,
};
