//
// Created by Julian Richter on 6/26/25.
//
#include <coreutils/osDetection.h>
#include "coreutils/library.h"

#define OS_UNKNOWN 0
#define OS_WINDOWS 1
#define OS_MACOS 2
#define OS_LINUX 3
#define OS_FREEBSD 4
#define OS_OPENBSD 5
#define OS_UNIX 6
/**
 * @file osDetection.c
 * @brief Defines the constant `osTypes` which maps operating systems to integer values.
 *
 * The `osTypes` constant stores identifier values for supported operating systems,
 * enabling easy identification and comparison of operating systems throughout the application.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
static const OSTypes osTypes = {
    .Windows =OS_WINDOWS,
    .MacOS = OS_MACOS,
    .Linux = OS_LINUX,
    .FreeBSD = OS_FREEBSD,
    .OpenBSD = OS_OPENBSD,
    .Unix = OS_UNIX,
    .Unknown = OS_UNKNOWN
};

/**
 * @file osDetection.h
 *
 * @brief Pointer to the static system types structure holding constants for various operating system identifiers.
 *
 * The `ptrOsTypes` variable points to a statically defined `OSTypes` structure, which contains integer identifiers
 * for supported operating systems. These identifiers can be used in system or platform checking functionality.
 * It includes constants like `Windows`, `MacOS`, `Linux`, and others, as well as a `Unknown` identifier for undefined systems.
 *
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
const OSTypes* ptrOsTypes = &osTypes;


/**
 * Determines the operating system of the current environment.
 *
 * This method checks the underlying system and returns an integer
 * that represents the corresponding operating system. It supports
 * detecting Windows, macOS, Linux, FreeBSD, OpenBSD, Unix, and will
 * return a default value indicating an unknown operating system if none match.
 *
 * The returned integer corresponds to predefined constants for each OS,
 * allowing identification or conditional handling of system-specific logic.
 *
 * @return An integer representing the operating system:
 *         - 1 for Windows
 *         - 2 for macOS
 *         - 3 for Linux
 *         - 4 for FreeBSD
 *         - 5 for OpenBSD
 *         - 6 for Unix
 *         - 0 for Unknown
 *
 * @file osDetection.c
 * @author Julian Richter
 * @version 1.0
 * @since 2025-06-26
 */
int getOs() {
    if (isWindows()) return osTypes.Windows;
    if (isMacos()) return osTypes.MacOS;
    if (isLinux()) return osTypes.Linux;
    if (isFreeBSD()) return osTypes.FreeBSD;
    if (isOpenBSD()) return osTypes.OpenBSD;
    if (isUnix()) return osTypes.Unix;
    return osTypes.Unknown;
}

