
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enter_num();
int delete_inx(int n);
int enter();
int enter_color();
typedef enum Color
{
    RED,
    BLUE,
    GREEN,
    YELLOW
} Color;
typedef struct Building
{
    int service_life;
    int price;
    int height;
    Color color;
    char *street;
} Building;
void shellSort(Building *buildings, int arraySize, int (*cmp)(const void *, const void *));
int cmp_service_life(const void *a, const void *b);
int cmp_price(const void *a, const void *b);
int cmp_height(const void *a, const void *b);
int cmp_color(const void *a, const void *b);
Building *create_buildings_array(int n);
void print_buildings_array(Building *buildings, int n);
Building init_building(int service_life, int price, int height, Color color, char *street);
void sort_by_color_and_service_life(Building *buildings, int n);
Building *delete(Building *buildings, int *n, int index);
int performance(int n, Building *buildings, int index, int choice);
void qsortSort(Building *buildings, int N);
void qsortSortRecursion(Building *buildings, int low, int high);
int patrition(Building *buildings, int low, int high);
void enter_elements(Building *buildings, int n);
Building *add_build(Building *buildings, int *n);
int strlength(const char *str);
