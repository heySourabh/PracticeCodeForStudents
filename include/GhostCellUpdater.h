/* 
 * File:   GhostCellUpdater.h
 * Author: Sourabh Bhat
 *
 * Created on 3 February, 2017, 12:50 PM
 */

#ifndef GHOSTCELLUPDATER_H
#define	GHOSTCELLUPDATER_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "data.h"

    void updateGhostCells(Cell cells[], int rkStep);

#ifdef	__cplusplus
}
#endif

#endif	/* GHOSTCELLUPDATER_H */

