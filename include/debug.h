/* 
 * File:   debug.h
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 5:47 PM
 */

#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "data.h"

    void printPrimitiveVariables(Cell cell, int rkStep);
    void printArray(double array[], int size);

#ifdef __cplusplus
}
#endif

#endif /* DEBUG_H */

