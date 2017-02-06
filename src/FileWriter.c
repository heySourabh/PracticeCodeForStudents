/* 
 * File:   FileWriter.h
 * Author: Sourabh Bhat
 *
 * Created on 4 February, 2017, 10:41 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "FileWriter.h"
#include "GoverningEquations.h"
#include "data.h"

void writeSolutionToFile(Cell cells[]) {
    printf("\nWriting to file... ");
    static int fileIndex = 0;
    char fileName[MAX_FILE_NAME_LEN];
    sprintf(fileName, "solution%05d.dat", fileIndex);
    FILE* file = fopen(fileName, "w");

    char** primVarNames = malloc(NUM_VARS * sizeof (char*));
    int var;
    for (var = 0; var < NUM_VARS; var++) {
        primVarNames[var] = malloc(MAX_VAR_NAME_LENGTH * sizeof (char));
    }
    getPrimitiveVariableNames(primVarNames);

    // Write variable names as header of the file
    fprintf(file, "%-20s", "x");
    for (var = 0; var < NUM_VARS; var++) {
        fprintf(file, "%-20s", primVarNames[var]);
    }

    // Write cell data
    const int RK_STEP = 0;
    int i;
    for (i = NUM_GHOST_CELLS; i < NUM_CELLS + NUM_GHOST_CELLS; i++) {
        fprintf(file, "\r\n%-20f", cells[i].cx);
        double primVar[NUM_VARS];
        conservativeToPrimitive(cells[i].U[RK_STEP], primVar);
        int var;
        for (var = 0; var < NUM_VARS; var++) {
            fprintf(file, "%-20f", primVar[var]);
        }
    }


    fclose(file);

    fileIndex++;
    printf("done.\n");
}