/* 
 * File:   SolutionCopier.h
 * Author: Sourabh Bhat
 *
 * Created on 4 February, 2017, 11:50 AM
 */

#include "SolutionCopier.h"
#include "data.h"

void copyBackToLevelN(Cell cells[]) {
    int i;
    for (i = NUM_GHOST_CELLS; i < NUM_CELLS + NUM_GHOST_CELLS; i++) {
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[i].U[0][var] = cells[i].U[NUM_RK_STEPS][var];
        }
    }
}