/* 
 * File:   FluxCalculator.c
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 1:41 PM
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "config.h"
#include "GoverningEquations.h"
#include "data.h"
#include "debug.h"

// TODO: Exercise for students - implement other Riemann solvers taught in class

void laxFriedrichRiemannSolver(double UL[], double UR[], double* flux) {
    double FL[NUM_VARS];
    double FR[NUM_VARS];

    F(UL, FL);
    F(UR, FR);

    double maxWaveSpeed = fmax(getMaxAbsEigenValue(UL), getMaxAbsEigenValue(UR));

    int var;
    for (var = 0; var < NUM_VARS; var++) {
        flux[var] = 0.5 * (FL[var] + FR[var]) - 0.5 * maxWaveSpeed * (UR[var] - UL[var]);
    }
}

void calculateFlux(Cell cells[], int rkStep) {
    int i;
    for (i = 0; i < NUM_CELLS + 2 * NUM_GHOST_CELLS; i++) {
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[i].totalFlux[var] = 0.0;
        }
    }

    double flux[NUM_VARS];
    int cellInterface;
    for (cellInterface = NUM_GHOST_CELLS; cellInterface < NUM_CELLS + NUM_GHOST_CELLS + 1; cellInterface++) {
        double* UL = cells[cellInterface - 1].UEast;
        double* UR = cells[cellInterface].UWest;

        laxFriedrichRiemannSolver(UL, UR, flux);

        int var;
        for (var = 0; var < NUM_VARS; var++) {
            cells[cellInterface - 1].totalFlux[var] += flux[var];
            cells[cellInterface].totalFlux[var] -= flux[var];
        }
    }
}