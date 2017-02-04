/* 
 * File:   GoverningEquations.h
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 1:27 PM
 */

#ifndef GOVERNINGEQUATIONS_H
#define	GOVERNINGEQUATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NUM_VARS 3
#define MAX_VAR_NAME_LENGTH 50

    char** getConservativeVariableNames(char** names);
    char** getPrimitiveVariableNames(char** names);
    void conservativeToPrimitive(double conservativeVariables[], double* primitiveVariables);
    void primitiveToConservative(double primitiveVariables[], double* conservativeVariables);
    void F(double U[], double F[]);
    double getMaxAbsEigenValue(double U[]);

#ifdef	__cplusplus
}
#endif

#endif	/* GOVERNINGEQUATIONS_H */

