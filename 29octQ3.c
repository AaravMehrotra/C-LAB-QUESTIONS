#include <stdio.h>
int main() {
    FILE *file;        
    char ch;           
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error! File not found.\n");
        return 1;   
    }
    printf("Contents of the file:\n\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
    return 0;
}