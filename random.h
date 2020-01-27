#ifndef RANDOMH
#define RANDOMH
/*
Author: Ricardo Mokveld
Date: 27-01-2020
*/
#include <cstdlib>

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);    
}
#endif