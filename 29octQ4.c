#include <stdio.h>

int main() 
{
    FILE *fp;
    char filename[100];
    char ch;
    int count = 0;
    printf("Enter the file name: ");
    scanf("%s", filename);
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
    return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ')
    count++;
    }
    fclose(fp);
    printf("Number of spaces in the file: %d\n", count);
    return 0;
}