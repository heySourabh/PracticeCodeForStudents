/* 
 * File:   config.h
 * Author: Sourabh Bhat
 *
 * Created on 2 February, 2017, 1:34 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NUM_CELLS 200
#define NUM_GHOST_CELLS 1
#define MIN_X (-0.5)
#define MAX_X (+0.5)

#define CFL 0.5
#define STOPPING_TIME 5.5e-4

#define NUM_RK_STEPS 1
#define MAX_TIME_ITER 1000000

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

