//
// Created by Julian Richter on 6/26/25.
//
#ifndef COREUTILS_LIBRARY_H
#define COREUTILS_LIBRARY_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


  /** @brief Returns true if it's MacOS */
bool isMacos();

  /** @brief Returns true if it's Linux */

bool isLinux();

  /** @brief Returns true if it's FreeBSD */
bool isFreeBSD();

  /** @brief Returns true if it's OpenBSD */
bool isOpenBSD();

  /** @brief Returns true if OS is Windows */
bool isWindows();

  /** @brief Returns true if the OS is Unix Like */
bool isUnix();


    /** @brief Returns true if OS cannot be identified */
bool isUnknown();




#ifdef __cplusplus
}
#endif

#endif //COREUTILS_LIBRARY_H
