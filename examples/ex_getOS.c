//
// Created by Julian Richter on 6/26/25.
//
#include <stdio.h>
#include <coreutils/osDetection.h>
#include <coreutils/library.h>

int main() {
    int os = getOs();
    
    if(os == ptrOsTypes->MacOS) {
        printf("Hello, macOS!\n");
    } else if(os == ptrOsTypes->Linux) {
        printf("Hello, Linux!\n");
    } else {
        printf("Hello, Unknown!\n");
    }
    
    return 0;
}