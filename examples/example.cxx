//
// Created by Julian Richter on 6/26/25.
//
#include <coreutils/library.h>
#include <coreutils/osDetection.h>
#include <iostream>

int main() {
    if (isFreeBSD()) {
        std::cout << "Hello, FreeBSD!" << std::endl;
    } else if (isLinux()) {
        std::cout << "Hello, Linux!" << std::endl;
    } else {
        std::cout << ptrOsTypes->Unknown << std::endl;
    }
    return 0;
}
