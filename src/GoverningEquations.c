/* 
 * File:   GoverningEquations.c
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 7:15 PM
 */

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "GoverningEquations.h"
#include "FluidProperties.h"

/**
 * To get variable names use the code similar to below:<br>
 * <code>
 * char** names = malloc(sizeof(char*) * NUM_VARS); <br>
 * for(int n = 0; n &lt NUM_VARS; n++) { <br>
 *     names[n] = malloc(sizeof(char) * MAX_VAR_NAME_LENGTH); <br>
 * } <br>
 * getConservativeVariableNames(names); <br>
 * </code>
 * @param names buffer for array of strings
 * @return array of strings
 */
char** getConservativeVariableNames(char* names[]) {
    char* consVarNames[] = {
        "rho", "rho u", "E"
    };
    int var;
    for (var = 0; var < NUM_VARS; var++) {
        strcpy(names[var], consVarNames[var]);
    }
    return names;
}

char** getPrimitiveVariableNames(char* names[]) {
    char* primVarNames[] = {
        "rho", "u", "p"
    };
    int var;
    for (var = 0; var < NUM_VARS; var++) {
        strcpy(names[var], primVarNames[var]);
    }
    return names;
}

void conservativeToPrimitive(double conservativeVariables[], double* primitiveVariables) {
    double rho = conservativeVariables[0];
    double rho_u = conservativeVariables[1];
    double E = conservativeVariables[2];

    double u = rho_u / rho;
    double kineticEnergy = u * u / 2.0;

    double specEnergy = E / rho;
    double internalEnergy = specEnergy - kineticEnergy;
    double T = internalEnergy / CV;

    double p = EOS_P(rho, T);

    double vars[] = {
        rho, u, p
    };
    int var;
    for (var = 0; var < NUM_VARS; var++) {
        primitiveVariables[var] = vars[var];
    }

}

void primitiveToConservative(double primitiveVariables[], double* conservativeVariables) {
    double rho = primitiveVariables[0];
    double u = primitiveVariables[1];
    double p = primitiveVariables[2];

    double T = EOS_T(p, rho);
    double internalEnergy = CV * T;
    double kineticEnergy = u * u / 2.0;
    double specEnergy = internalEnergy + kineticEnergy;

    double vars[] = {
        rho, rho * u, rho * specEnergy
    };
    int var;
    for (var = 0; var < NUM_VARS; var++) {
        conservativeVariables[var] = vars[var];
    }
}

void F(double U[], double* F) {
    double primVar[NUM_VARS];
    conservativeToPrimitive(U, primVar);
    double rho = primVar[0];
    double u = primVar[1];
    double p = primVar[2];
    double E = U[2];

    double flux[] = {
        rho * u,
        rho * u * u + p,
        (E + p) * u
    };

    int var;
    for (var = 0; var < NUM_VARS; var++) {
        F[var] = flux[var];
    }
}

double getMaxAbsEigenValue(double U[]) {
    double primVar[NUM_VARS];
    conservativeToPrimitive(U, primVar);

    double rho = primVar[0];
    double u = primVar[1];
    double p = primVar[2];

    return fabs(u) + sqrt(GAMMA * p / rho);
}