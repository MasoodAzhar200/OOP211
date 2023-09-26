/********************************************
*                     Workshop2-P2
Muhammad Masood Azhar
149328221
mazhar17@myseneca.ca
NEE

Authenticity Declaration
This submitted piece of work is entirely of my
own creation.
***********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include <cstdio>

namespace sdds {
    FILE* fptr;

    FILE* openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr;
    }

    void closeFile(FILE* file) {
        if (file) fclose(file);
    }
}
