#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    char input[100];
    char *end;
    long value;

    while (1) {
        printf("%s", prompt);

        if (fgets(input, sizeof input, stdin) == NULL) {
            return 0;
        }

        value = strtol(input, &end, 10);

        if (end != input) {
            while (*end == ' ' || *end == '\t' ||
                   *end == '\n' || *end == '\r') {
                end++;
            }

            if (*end == '\0' &&
                value >= -2147483647L - 1 &&
                value <= 2147483647L) {
                return (int)value;
            }
        }

        printf("Invalid integer. Try again.\n");
    }
}

double readDouble(const char *prompt)
{
    char input[100];
    char *end;
    double value;

    while (1) {
        printf("%s", prompt);

        if (fgets(input, sizeof input, stdin) == NULL) {
            return 0.0;
        }

        value = strtod(input, &end);

        if (end != input) {
            while (*end == ' ' || *end == '\t' ||
                   *end == '\n' || *end == '\r') {
                end++;
            }

            if (*end == '\0') {
                return value;
            }
        }

        printf("Invalid number. Try again.\n");
    }
}

void readLine(const char *prompt, char *buffer, int size)
{
    size_t length;
    int ch;

    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    length = strlen(buffer);

    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    } else {
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Discard excess characters. */
        }
    }
}

void pauseScreen(void)
{
    char input[10];

    printf("\nPress Enter to continue...");
    fgets(input, sizeof input, stdin);
}