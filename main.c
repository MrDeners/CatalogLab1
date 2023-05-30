#include "func.h"

int main()
{
    int n, choice = 0, index = 0;
    Building *buildings = NULL;
    printf("Введите количество зданий: ");
    n = enter();
    system("CLS");
    buildings = create_buildings_array(n);
    enter_elements(buildings, n);
    performance(n, buildings, index, choice);
    for (int i = 0; i < n; i++)
    {
        free(buildings[i].street);
    }
    free(buildings);
    return 0;
}