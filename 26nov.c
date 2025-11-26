#include <stdio.h>
#include <stdlib.h>
#define FILENAME "numbers.txt"
static int *load_numbers(size_t *count) 
{
FILE *f = fopen(FILENAME, "r");
*count = 0;
if (!f) return NULL;
size_t cap = 64;
int *arr = malloc(cap * sizeof(int));
if (!arr) { fclose(f); return NULL; }
int x;
while (fscanf(f, "%d", &x) == 1) 
{
if (*count >= cap) {
cap *= 2;
int *tmp = realloc(arr, cap * sizeof(int));
if (!tmp) { free(arr); fclose(f); return NULL; }
arr = tmp;
}
arr[(*count)++] = x;
    }
    fclose(f);
    return arr;
}
static int exists_in(int *arr, size_t n, int val) 
{
for (size_t i = 0; i < n; ++i) if (arr[i] == val) return 1;
return 0;
}
static int append_two(int a, int b) {
    FILE *f = fopen(FILENAME, "a");
    if (!f) return 0;
    fprintf(f, "%d %d\n", a, b);
    fclose(f);
    return 1;
}

int main(void) {
    size_t n = 0;
    int *arr = load_numbers(&n);
    int a, b;

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "Invalid input.\n");
        free(arr);
        return 1;
    }

    while ((arr && exists_in(arr, n, a)) || (arr && exists_in(arr, n, b))) {
        if (arr && exists_in(arr, n, a)) printf("First number %d already exists in file.\n", a);
        if (arr && exists_in(arr, n, b)) printf("Second number %d already exists in file.\n", b);
        printf("Please enter two different integers: ");
        if (scanf("%d %d", &a, &b) != 2) {
            fprintf(stderr, "Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    if (!append_two(a, b)) {
        fprintf(stderr, "Failed to write to file.\n");
        free(arr);
        return 1;
    }
    printf("Numbers %d and %d stored in %s\n", a, b, FILENAME);
    free(arr);
    arr = load_numbers(&n);

    for (;;) {
        printf("\nOptions:\n1) Search a number\n2) Display all numbers\n3) Exit\nChoose (1-3): ");
        int opt;
        if (scanf("%d", &opt) != 1) break;
        if (opt == 1) {
            int key;
            printf("Enter number to search: ");
            if (scanf("%d", &key) != 1) break;
            int found = 0;
            int count = 0;
            if (arr) {
                for (size_t i = 0; i < n; ++i) if (arr[i] == key) { found = 1; ++count; }
            }
            if (found) printf("Number %d found (%d occurrence%s).\n", key, count, count>1?"s":"");
            else printf("Number %d not found.\n", key);
        } else if (opt == 2) {
            if (!arr || n == 0) { printf("File is empty.\n"); continue; }
            printf("Numbers in file (%zu):\n", n);
            for (size_t i = 0; i < n; ++i) printf("%d%c", arr[i], (i+1==n)?'\n':' ');
        } else if (opt == 3) {
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    free(arr);
    return 0;
}