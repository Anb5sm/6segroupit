#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkUnterminatedComments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }  

    char ch, prev = 0;
    int inComment = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (inComment) {
            if (prev == '*' && ch == '/') {
                inComment = 0;
            }
        } else {
            if (prev == '/' && ch == '*') {
                inComment = 1;
            }
        }
        prev = ch;
    }

    fclose(file);

    if (inComment) {
        printf("Unterminated multi-line comment detected.\n");
        return 1;
    } else {
        printf("No unterminated multi-line comments detected.\n");
        return 0;
    }
}

int main() {
    char filename[100];
    printf("Enter the path to the C program: ");
    scanf("%99s", filename);

    checkUnterminatedComments(filename);

    return 0;
}