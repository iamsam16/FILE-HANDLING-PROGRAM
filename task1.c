#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100] = "example.txt";
    char data[100];

    // -------- 1. Create and Write to the File --------
    fp = fopen(filename, "w"); // "w" mode creates a file for writing
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter data to write to the file:\n");
    fgets(data, sizeof(data), stdin); // Take input with spaces
    fputs(data, fp); // Write to file
    fclose(fp); // Close the file
    printf("Data written to %s successfully.\n\n", filename);

    // -------- 2. Read from the File --------
    fp = fopen(filename, "r"); // "r" mode for reading
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("Reading data from file:\n");
    while (fgets(data, sizeof(data), fp)) {
        printf("%s", data);
    }
    fclose(fp);
    printf("\n\n");

    // -------- 3. Append Data to the File --------
    fp = fopen(filename, "a"); // "a" mode for appending
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return 1;
    }

    printf("Enter data to append to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended to %s successfully.\n\n", filename);

    // -------- 4. Final Read from the File --------
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for final read.\n");
        return 1;
    }

    printf("Final content of the file:\n");
    while (fgets(data, sizeof(data), fp)) {
        printf("%s", data);
    }
    fclose(fp);

    return 0;
}
