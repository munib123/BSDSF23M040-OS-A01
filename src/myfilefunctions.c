#include "../include/myfilefunctions.h"
#include <stdio.h>  // For FILE
#include <stdlib.h> // For malloc
#include <ctype.h>  // For isspace
#include <string.h>
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file) return -1;
    *lines = *words = *chars = 0;
    int ch;
    int in_word = 0;
    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;
        if (ch == '\n') (*lines)++;
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*words)++;
        }
    }
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str) return -1;
    *matches = NULL;
    int count = 0;
    int capacity = 10;  // Initial array size
    *matches = malloc(capacity * sizeof(char*));
    if (!*matches) return -1;

    char line[1024];  // Assume lines < 1024 chars
    rewind(fp);  // Reset to start
    while (fgets(line, sizeof(line), fp)) {
        // Simple substring search (case-sensitive)
        int i = 0, j = 0;
        while (line[i]) {
            if (line[i] == search_str[j]) {
                j++;
                if (search_str[j] == '\0') {  // Match found
                    if (count >= capacity) {
                        capacity *= 2;
                        *matches = realloc(*matches, capacity * sizeof(char*));
                        if (!*matches) return -1;
                    }
                    (*matches)[count] = malloc(strlen(line) + 1);
                    strcpy((*matches)[count], line);
                    count++;
                    break;
                }
            } else {
                j = 0;
            }
            i++;
        }
    }
    return count;
}