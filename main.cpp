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
#include "Population.h"
using namespace sdds;
int main() {
    char postal_code_prefix[4]{};
    while (getPostalCode(postal_code_prefix)) {
        if (load("PCpopulations.csv", postal_code_prefix)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}


