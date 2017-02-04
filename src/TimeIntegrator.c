/* 
 * File:   TimeIntegrator.h
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 3:37 PM
 */

#include "config.h"
#include "data.h"


void updateCells(Cell cells[], int rkStep, double dt) {
    // TODO: Higher order time integration
    // assuming dx is uniform
    double dx = cells[0].dx;
    
    int i;
    for (i = NUM_GHOST_CELLS; i < NUM_CELLS + NUM_GHOST_CELLS; i++) {
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[i].U[1][var] 
                    = cells[i].U[0][var] - dt / dx *  cells[i].totalFlux[var];
        }
    }
}