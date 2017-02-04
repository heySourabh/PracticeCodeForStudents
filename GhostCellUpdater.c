/* 
 * File:   GhostCellUpdater.C
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 01:04 PM
 */
#include "GhostCellUpdater.h"
#include "config.h"
#include "GoverningEquations.h"
#include "data.h"

void updateGhostCells(Cell cells[], int rkStep) {
    // TODO: simple extrapolation as of now, needs to be changed
    int gc;
    for (gc = 0; gc < NUM_GHOST_CELLS; gc++) {
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[gc].U[rkStep][var] = cells[NUM_GHOST_CELLS].U[rkStep][var];
        }
    }

    for (gc = NUM_CELLS + NUM_GHOST_CELLS; gc < NUM_CELLS + 2 * NUM_GHOST_CELLS; gc++) {
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[gc].U[rkStep][var] = cells[NUM_CELLS + NUM_GHOST_CELLS - 1].U[rkStep][var];
        }
    }
}