/* 
 * File:   FluidProperties.h
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 8:45 PM
 */

#ifndef FLUIDPROPERTIES_H
#define	FLUIDPROPERTIES_H

#ifdef	__cplusplus
extern "C" {
#endif

#define GAMMA 1.4
#define R 287.0
#define CV (R / (GAMMA - 1.0))

    double EOS_P(double rho, double temperature);

    double EOS_T(double p, double rho);

    double EOS_RHO(double p, double temperature);


#ifdef	__cplusplus
}
#endif

#endif	/* FLUIDPROPERTIES_H */

