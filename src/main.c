/* 
 * File:   main.c
 * Author: Sourabh Bhat
 *
 * Created on 1 February, 2017, 9:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "data.h"
#include "SetupCellGeometryData.h"
#include "Initializer.h"
#include "FluidProperties.h"
#include "TimeStepCalculator.h"
#include "GhostCellUpdater.h"
#include "TimeIntegrator.h"
#include "SolutionReconstructor.h"
#include "FluxCalculator.h"
#include "debug.h"
#include "FileWriter.h"
#include "SolutionCopier.h"

/*
 * 
 */
int main(int argc, char** argv) {

    /* ========================== Start of algorithm ============================ */
    // Steps of the complete algorithm:
    // Create cell array, Set dx, cx
    // Initialize all cells
    // time = 0.0
    // time loop, timeIter = [0 ... MAX_TIME_ITER]:
    //     calculate dt based on CFL
    //     if time + dt > STOPPING_TIME:
    //         dt = STOPPING_TIME - time
    //         lastTimeStep = true
    //         
    //     for each Runge-Kutta step:
    //         apply boundary conditions
    //         reconstruct solution
    //         calculate flux (Riemann Solver)
    //         update cells values
    // 
    //     copy cell values from (n+1) to n
    // 
    //     time = time + dt
    //     if lastTimeStep: break
    //
    // write solution to file
    /* =========================== End of algorithm ============================= */


    /* ========================================================================== */
    // and finally here begins the actual code... 

    // Create cell array, Set dx, cx
    Cell cells[NUM_CELLS + 2 * NUM_GHOST_CELLS];
    setUpGeometry(cells);

    // Initialize all cells
    initializeSolution(cells);

    bool lastTimeStep = false;
    // time = 0.0
    double time = 0.0;

    // time loop, timeIter = [0 ... MAX_TIME_ITER]:
    long timeIter;
    printf("\nStarting time iterations...\n");
    for (timeIter = 0; timeIter < MAX_TIME_ITER; timeIter++) {
        // calculate dt based on CFL
        double dt = getTimeStep(cells);
        if (time + dt > STOPPING_TIME) {
            dt = STOPPING_TIME - time;
            lastTimeStep = true;
        }

        // For each Runge-Kutta intermediate step
        int rkStep;
        for (rkStep = 0; rkStep < NUM_RK_STEPS; rkStep++) {
            updateGhostCells(cells, rkStep);
            reconstructSolution(cells, rkStep);
            calculateFlux(cells, rkStep);
            updateCells(cells, rkStep, dt);
        }

        // copy cell values from (n+1) to n
        copyBackToLevelN(cells);

        time = time + dt;
        printf("\ntime = %.4e, dt = %.4e", time, dt);
        if (lastTimeStep) {
            break;
        }
    }

    printf("\nTime iterations done.\n");
    writeSolutionToFile(cells);
    return (EXIT_SUCCESS);
}

