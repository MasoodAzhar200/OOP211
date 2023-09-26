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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include <cstdio>

namespace sdds {
    FILE* openFile(const char filename[]);
    void closeFile(FILE* file);
}

#endif // !SDDS_FILE_H_
