#include <stdio.h>
int main() 
{
    FILE *file;
    char filename[100];
    char ch;
    int lines = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) 
    {
        if (ch == '\n') {
            lines++;
    }
    }
    if (ch != '\n' && lines > 0) 
    {
    lines++;
    }
    fclose(file);
    printf("Number of lines in file: %d\n", lines);
    return 0;
}