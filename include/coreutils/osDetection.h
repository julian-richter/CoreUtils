//
// Created by Julian Richter on 6/26/25.
//

#ifndef OSDETECTION_H
#define OSDETECTION_H

#ifdef __cplusplus
extern "C" {
#endif

 /**
  * @file osDetection.h
  * @brief Contains declarations and definitions related to operating system detection.
  */
typedef struct {
  int Windows;
  int MacOS;
  int Linux;
  int FreeBSD;
  int OpenBSD;
  int Unix;
  int Unknown;
} OSTypes;



    /** @brief Access to OS type constants */
extern const OSTypes* ptrOsTypes;


/**
 * Determines the current operating system and returns an integer code
 * corresponding to the detected operating system. The supported operating
 * systems and their respective codes are defined in the OSTypes structure.
 *
 * @return int A code representing the detected operating system. If the operating
 *             system is not recognized, an integer code corresponding to `Unknown`
 *             is returned.
 *
 * @file osDetection.c
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
int getOs();
#ifdef __cplusplus
}
#endif
#endif //OSDETECTION_H