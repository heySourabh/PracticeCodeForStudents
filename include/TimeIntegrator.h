/* 
 * File:   TimeIntegrator.h
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 1:48 PM
 */

#ifndef TIMEINTEGRATOR_H
#define	TIMEINTEGRATOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "data.h"

    void updateCells(Cell cells[], int rkStep, double dt);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMEINTEGRATOR_H */

