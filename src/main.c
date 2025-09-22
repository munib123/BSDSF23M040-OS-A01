#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    const char* test_str = "Hello, World!";
    char buf[50];

    printf("mystrlen(\"%s\") = %d\n", test_str, mystrlen(test_str));  // Expected: 13

    mystrcpy(buf, test_str);
    printf("mystrcpy: %s\n", buf);

    mystrncpy(buf, test_str, 5);
    printf("mystrncpy (n=5): %s\n", buf);  // "Hello"

    mystrcpy(buf, "Hello");
    mystrcat(buf, ", World!");
    printf("mystrcat: %s\n", buf);

    printf("\n--- Testing File Functions ---\n");
    FILE* test_file = fopen("test.txt", "w+");  // Create a test file
    if (!test_file) {
        perror("File open failed");
        return 1;
    }
    fprintf(test_file, "Line 1: Hello World\nLine 2: Foo Bar\nLine 3: Search me");
    rewind(test_file);

    int lines, words, chars;
    if (wordCount(test_file, &lines, &words, &chars) == 0) {
        printf("wordCount: Lines=%d, Words=%d, Chars=%d\n", lines, words, chars);  // Expected: 3, 8, ~50
    }

    rewind(test_file);
    char** matches;
    int match_count = mygrep(test_file, "Search", &matches);
    if (match_count > 0) {
        printf("mygrep found %d matches:\n", match_count);
        for (int i = 0; i < match_count; i++) {
            printf("%s", matches[i]);
            free(matches[i]);
        }
        free(matches);
    }

    fclose(test_file);
    remove("test.txt");  // Clean up
    return 0;
}