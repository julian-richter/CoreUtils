//
// Created by Julian Richter on 6/26/25.
//
#ifndef COREUTILS_LIBRARY_H
#define COREUTILS_LIBRARY_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @file library.h
 * @brief Contains the declaration for the hello() function.
 *
 * This file includes the declaration of a simple function
 * to demonstrate the use of the API.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
void hello(void);

/**
 * @file library.c
 * @brief Determines if the current operating system is macOS.
 *
 * This function checks at compile-time whether the underlying operating system
 * is macOS. It returns an integer indicating the result of the detection.
 *
 * @return 1 if the operating system is macOS, 0 otherwise.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
bool isMacos();

/**
 * @file library.h
 * @brief Provides functions to detect the operating system type.
 *
 * This function checks if the host system is Linux-based.
 * It utilizes preprocessor directives to determine the OS.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 *
 * @return Returns 1 if the host system is Linux, otherwise returns 0.
 */
bool isLinux();

/**
 * @file library.c
 * @brief Provides functionality to identify if the operating system is FreeBSD.
 *
 * This method detects whether the underlying operating system
 * is FreeBSD, which is a free and open-source Unix-like operating system.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 *
 * @return int Returns 1 if the operating system is FreeBSD, otherwise returns 0.
 */
bool isFreeBSD();

/**
 * @file library.c
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 *
 * @brief Detects if the operating system is OpenBSD.
 *
 * This function checks at compile-time using preprocessor directives
 * to determine if the current operating system is OpenBSD.
 * It leverages the __OpenBSD__ macro to identify the system.
 *
 * @return 1 if the operating system is OpenBSD, 0 otherwise.
 */
bool isOpenBSD();

/**
 * @file library.c
 * @brief Provides functions to detect the operating system at runtime.
 *
 * The `isWindows` function determines whether the application is running
 * on a Windows operating system. This function uses preprocessor directives
 * to check if the current compilation environment is targeting Windows.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
bool isWindows();

/**
 * @file library.c
 * @brief Provides utility functions for detecting operating systems.
 *
 * The `isUnix` function determines whether the underlying system
 * satisfies conditions to be recognized as a Unix-like operating system.
 * It checks for predefined macros that indicate a Unix-compatible system,
 * such as Unix, Linux, or macOS.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
bool isUnix();

/**
 * @file library.c
 * @brief Detects if the operating system is unknown.
 *
 * The function evaluates various operating system detections to determine if the
 * current system's operating system cannot be classified as any of the
 * known types: Windows, macOS, Linux, FreeBSD, OpenBSD, or Unix.
 *
 * @return int Returns 1 if the operating system is classified as unknown, otherwise returns 0.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
bool isUnknown();




#ifdef __cplusplus
}
#endif

#endif //COREUTILS_LIBRARY_H
