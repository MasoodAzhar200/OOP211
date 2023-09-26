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
#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    Population* populations = nullptr;
    int numPopulations = 0;

    bool getPostalCode(char* postal_code_prefix) {
        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl;
        cout << "> ";
        cin.getline(postal_code_prefix, 4);
        return postal_code_prefix[0] != '!';
    }

    bool load(const char* filename, const char* partial_postal_code_prefix) {
        FILE* fptr = openFile(filename);

        if (!fptr) {
            cerr << "Error: Cannot open file " << filename << endl;
            return false;
        }

        // Delete any existing data to avoid memory leaks
        if (populations) {
            delete[] populations;
            populations = nullptr;
            numPopulations = 0;
        }

        // Count the number of records (matching or all)
        char postalCode[4];
        int population;
        int matches = 0;

        while (fscanf(fptr, " %3[^,],%d", postalCode, &population) == 2) {
            if (startsWith(postalCode, partial_postal_code_prefix) || strcmp(partial_postal_code_prefix, "all") == 0) {
                matches++;
            }
            char newline;
            if (fscanf(fptr, "%c", &newline) != 1 || newline != '\n') {
                cerr << "Error: Invalid data format in file" << endl;
                closeFile(fptr);
                return false;
            }
        }

        if (matches > 0) {
            // Allocate memory for all records
            Population* allPopulations = new Population[matches];
            rewind(fptr);

            // Load all records into the dynamic array
            int index = 0;
            while (fscanf(fptr, " %3[^,],%d", allPopulations[index].postalCode, &allPopulations[index].population) == 2) {
                if (startsWith(allPopulations[index].postalCode, partial_postal_code_prefix) || strcmp(partial_postal_code_prefix, "all") == 0) {
                    index++;
                }
                char newline;
                if (fscanf(fptr, "%c", &newline) != 1 || newline != '\n') {
                    cerr << "Error: Invalid data format in file" << endl;
                    closeFile(fptr);
                    delete[] allPopulations;
                    return false;
                }
            }

            // Sort the array in ascending order of population
            for (int i = 0; i < matches - 1; i++) {
                for (int j = 0; j < matches - i - 1; j++) {
                    if (allPopulations[j].population > allPopulations[j + 1].population) {
                        // Swap
                        Population temp = allPopulations[j];
                        allPopulations[j] = allPopulations[j + 1];
                        allPopulations[j + 1] = temp;
                    }
                }
            }

            // Copy sorted array to populations
            populations = new Population[matches];
            for (int i = 0; i < matches; i++) {
                populations[i] = allPopulations[i];
            }
            numPopulations = matches;

            delete[] allPopulations; // Deallocate the temporary array
        }

        closeFile(fptr);
        return true;
    }






    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < numPopulations; i++) {
            cout << i + 1 << "- " << populations[i].postalCode << ":  " << populations[i].population << endl;
        }
        cout << "-------------------------" << endl;

        int totalPopulation = 0;
        for (int i = 0; i < numPopulations; i++) {
            totalPopulation += populations[i].population;
        }
        cout << "Population of the listed areas: " << totalPopulation << endl;
    }

    void deallocateMemory() {
        delete[] populations;
        populations = nullptr;
        numPopulations = 0;
    }
}


