/* 
 * File:   TimeIntegrator.h
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 3:37 PM
 */

#include "config.h"
#include "data.h"
#include "TimeIntegrator.h"

double coeffs_U[3][3] = {
    {1.0, 0.0, 0.0},
    {3.0 / 4.0, 1.0 / 4.0, 0.0},
    {1.0 / 3.0, 0.0, 2.0 / 3.0}
};
double coeffs_F[3] = {
    1.0, 1.0 / 4.0, 2.0 / 3.0
};

void updateCells(Cell cells[], int rkStep, double dt) {
    // assuming dx is uniform
    double dx = cells[0].dx;

    int i;
    for (i = NUM_GHOST_CELLS; i < NUM_CELLS + NUM_GHOST_CELLS; i++) {
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            int coeff;
            cells[i].U[rkStep + 1][var] = 0.0;
            for (coeff = 0; coeff < NUM_RK_STEPS; coeff++) {
                cells[i].U[rkStep + 1][var] += coeffs_U[rkStep][coeff] * cells[i].U[coeff][var];
            }
            cells[i].U[rkStep + 1][var] += (-dt / dx) * coeffs_F[rkStep] * cells[i].totalFlux[var];
        }
    }
}