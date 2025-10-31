#include <stdio.h>
int main() 
{
FILE *file;
long size;
file = fopen("test.txt", "r");
if (file == NULL) 
{
printf("File does not exist!\n");
return 1;
}
fseek(file, 0, SEEK_END);
size = ftell(file);
fclose(file);
if (size == 0) 
{
printf("File is empty!\n");
} else 
{
printf("File contains %ld bytes of text.\n", size);
}
return 0;
}