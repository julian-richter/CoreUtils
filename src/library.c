//
// Created by Julian Richter on 6/26/25.
//
#include <coreutils/library.h>
#include <coreutils/osDetection.h>


/**
 * @brief Determines if the system is macOS.
 *
 * This function checks if the current program is running on a Mac operating
 * system by validating both the __APPLE__ and __MACH__ preprocessor definitions.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 * @return Returns true if the system is macOS, otherwise false.
 */
bool isMacos() {
    #if defined(__APPLE__) && defined(__MACH__)
        return true;
    #else
        return false;
    #endif
}


/**
 * @brief Provides a utility function to check if the system is Linux.
 *
 * This function determines if the current program is running on a
 * Linux operating system by checking for the __linux__ preprocessor definition.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 */
bool isLinux() {
    #if defined(__linux__)
        return true;
    #else
        return false;
    #endif
}


/**
 * @brief Checks if the system is running on Windows.
 *
 * This function determines if the current program is being executed on a
 * Windows operating system by assessing the presence of _WIN32 or _WIN64
 * preprocessor definitions.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 * @return Returns true if the system is Windows, otherwise false.
 */
bool isWindows() {
    #if defined(_WIN32) || defined(_WIN64)
        return true;
    #else
        return false;
    #endif
}

/**
 * @brief Checks if the system is a Unix-like operating system.
 *
 * This function evaluates multiple preprocessor definitions to determine
 * if the current program is running on a Unix-compatible environment,
 * including Linux, macOS, and other Unix-based systems.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 * @return Returns true if the system is identified as Unix-like, otherwise false.
 */
bool isUnix() {
    #if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        return true;
    #else
        return false;
    #endif
}

/**
 * @brief Determines if the system is FreeBSD.
 *
 * This function checks if the current program is running on a FreeBSD operating
 * system by verifying the __FreeBSD__ preprocessor definition.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 * @return Returns true if the system is FreeBSD, otherwise false.
 */
bool isFreeBSD() {
    #if defined(__FreeBSD__)
        return true;
    #else
        return false;
    #endif
}

/**
 * @brief Determines if the system is OpenBSD.
 *
 * This function checks whether the current program is running on an OpenBSD
 * operating system based on the `__OpenBSD__` preprocessor definition.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 * @return Returns true if the system is OpenBSD, otherwise false.
 */
bool isOpenBSD() {
    #if defined(__OpenBSD__)
        return true;
    #else
        return false;
    #endif
}


/**
 * @brief Determines if the operating system is unknown.
 *
 * This function evaluates the current environment to identify the operating
 * system. It checks for all known systems, including Windows, macOS, Linux,
 * FreeBSD, OpenBSD, and Unix. If none of these systems are detected, the
 * operating system is classified as unknown.
 *
 * @author Julian Richter
 * @version 1.0.0
 * @since 2025-06-26
 * @return True if the operating system is unknown, otherwise false.
 */
bool isUnknown() {
    return !(isWindows() || isMacos() || isLinux() || isFreeBSD() || isOpenBSD() || isUnix());
}