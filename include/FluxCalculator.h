/* 
 * File:   FluxCalculator.h
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 1:39 PM
 */

#ifndef FLUXCALCULATOR_H
#define	FLUXCALCULATOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "data.h"

    void calculateFlux(Cell cells[], int rkStep);


#ifdef	__cplusplus
}
#endif

#endif	/* FLUXCALCULATOR_H */

