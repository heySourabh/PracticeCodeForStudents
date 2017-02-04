/* 
 * File:   FileWriter.h
 * Author: Sourabh Bhat
 *
 * Created on 4 February, 2017, 10:38 AM
 */

#ifndef FILEWRITER_H
#define FILEWRITER_H


#ifdef __cplusplus
extern "C" {
#endif
#include "data.h"
#define MAX_FILE_NAME_LEN 50

    void writeSolutionToFile(Cell cells[]);


#ifdef __cplusplus
}
#endif

#endif /* FILEWRITER_H */

