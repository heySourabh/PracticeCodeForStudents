/* 
 * File:   SolutionReconstructor.c
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 1:27 PM
 */
#include "SolutionReconstructor.h"
#include "data.h"
#include "config.h"

void reconstructSolution(Cell cells[], int rkStep) {
    // TODO: Exercise for students - Increase the order of the reconstruction
    int i;
    for (i = NUM_GHOST_CELLS - 1; i < NUM_CELLS + NUM_GHOST_CELLS + 1; i++) {
        // Simple first order reconstruction
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[i].UWest[var] = cells[i].U[rkStep][var];
            cells[i].UEast[var] = cells[i].U[rkStep][var];
        }
    }
}