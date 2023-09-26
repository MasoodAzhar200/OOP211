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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    bool startsWith(const char* cString, const char* subString);

    struct Population {
        char postalCode[4];
        int population;
    };

    bool getPostalCode(char* postal_code_prefix);
    bool load(const char* filename, const char* partial_postal_code_prefix);
    void display();
    void deallocateMemory();
}

#endif // SDDS_POPULATION_H_
