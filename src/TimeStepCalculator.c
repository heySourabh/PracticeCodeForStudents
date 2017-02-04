/* 
 * File:   TimeStepCalculator.c
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 7:59 PM
 */

#include "TimeStepCalculator.h"
#include "data.h"
#include "config.h"
#include "GoverningEquations.h"

double getTimeStep(Cell cells[]) {
    const int rkStep = 0;
    // assuming that dx is uniform
    double dx = cells[0].dx;
    double min_dt = dx / getMaxAbsEigenValue(cells[0].U[rkStep]);
    
    int i;
    for (i = 0; i < NUM_CELLS + 2 * NUM_GHOST_CELLS; i++) {
        double dt = dx / getMaxAbsEigenValue(cells[i].U[rkStep]);
        if (dt < min_dt) {
            min_dt = dt;
        }
    }
    
    return min_dt * CFL;
}