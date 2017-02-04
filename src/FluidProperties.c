/* 
 * File:   FluidProperties.c
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 8:48 PM
 */
#include "FluidProperties.h"

double EOS_P(double rho, double temperature) {
    return rho * R * temperature;
}

double EOS_T(double p, double rho) {
    return p / rho / R;
}

double EOS_RHO(double p, double temperature) {
    return p / R / temperature;
}