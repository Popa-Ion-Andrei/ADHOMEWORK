#include <stdio.h>
#include <stdlib.h>

#define min_lobster_name 3
#define max_lobster_name 20

int main() {
    /// Variable declaration
    unsigned long number_of_lobsters, index, bag_size;
    unsigned long min_lobster_value, max_lobster_value, min_lobster_size, max_lobster_size;
    FILE *output, *input;
    short unsigned name_length, j;

    /// Open input and output files
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    /// Error handling
    if (input == NULL || output == NULL) {
        fprintf(stderr, "Failed to open files");
        return 1;
    }

    /// Input
    fscanf(input, "%lu", &bag_size);
    fscanf(input, "%lu", &number_of_lobsters);
    fscanf(input, "%lu", &min_lobster_value);
    fscanf(input, "%lu", &max_lobster_value);
    fscanf(input, "%lu", &min_lobster_size);
    fscanf(input, "%lu", &max_lobster_size);

    /// Generating randomized output
    fprintf(output, "%lu\n", bag_size);
    for (index = 0; index < number_of_lobsters; index++) {
        if (index % 100000 == 0) printf("generating...\n");

        name_length = min_lobster_name + rand() % (max_lobster_name - min_lobster_name);

        for (j = 0; j < name_length; j++)
            fprintf(output, "%c", 'a' + rand() % ('z' - 'a'));

        fprintf(output, " %lu", min_lobster_size + rand() % (max_lobster_size - min_lobster_size));
        fprintf(output, " %lu\n", min_lobster_value + rand() % (max_lobster_value - min_lobster_value));
    }

    /// Clean up
    fclose(input);
    fclose(output);

    return 0;
}
