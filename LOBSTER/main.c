#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "HOMARI.h"

int main()
{
    // Variable declaration
    unsigned long long bag_size, lobster_number = 0;
    clock_t start, end;

    start = clock();

    FILE *input, *output;  // I/O files

    lobster* lobster_collection = malloc(sizeof(lobster)); // vector to keep track of all available lobsters

    // I/O initialization
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    // Error handling
    if (input == NULL || output == NULL)
    {
        fprintf(stderr, "Failed to open files\n");
        return 1;
    }

    // Input
    fscanf(input, "%llu", &bag_size);

    // Reading each lobster's attributes in the lobster collection. It is assumed the input is correctly formatted
    while (fscanf(input, "%s %llu %llu",
                  lobster_collection[lobster_number].name,
                  &lobster_collection[lobster_number].size,
                  &lobster_collection[lobster_number].value) != EOF)
    {
        if (lobster_collection[lobster_number].size <= bag_size) // Only consider the lobsters if they can fit in the bag
        {
            lobster_number++;
            lobster_collection = realloc(lobster_collection, sizeof(lobster) * (lobster_number + 2));
        }
    }

    // Function call
    dynamic_programming_lobster(lobster_collection, lobster_number, bag_size, output);

    end = clock();

    fprintf(output, "\nTime: %lf seconds\n", (double)((end - start)) / CLOCKS_PER_SEC);

    // Cleaning up
    free(lobster_collection);

    fclose(input);
    fclose(output);

    return 0;
}
