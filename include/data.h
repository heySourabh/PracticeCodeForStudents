/* 
 * File:   data.h
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 1:13 PM
 */

#ifndef DATA_H
#define	DATA_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "GoverningEquations.h"
#include "config.h"

    struct Cell {
        double U[NUM_RK_STEPS + 1][NUM_VARS]; // Average Conservative variables
        double UWest[NUM_VARS]; // Reconstructed values
        double UEast[NUM_VARS]; // Reconstructed values
        double totalFlux[NUM_VARS];
        
        double dx; // width of cell
        double cx; // centroid of cell
    };
    typedef struct Cell Cell;

    typedef enum {
        false, true
    } bool;

#ifdef	__cplusplus
}
#endif

#endif	/* DATA_H */

