
#include "func.h"
//! ВВОД ЗНАЧЕНИЙ
int enter_num()
{
    int choice = 0;
    while (!scanf_s("%d", &choice) || getchar() != '\n' || choice < 0 || choice > 9)
    {
        printf("Ошибка!\nПопробуйте ещё раз:");
        rewind(stdin);
    }
    return choice;
}
// ВВОД ЗНАЧЕНИЙ
int delete_inx(int n)
{
    int index = 0;
    while (!scanf_s("%d", &index) || getchar() != '\n' || index < 0 || index >= n)
    {
        printf("Ошибка!\nПопробуйте ещё раз:");
        rewind(stdin);
    }
    return index;
}
// ВВОД ЗНАЧЕНИЙ
int enter()
{
    int tutu = 0;
    while (!scanf_s("%d", &tutu) || getchar() != '\n')
    {
        printf("Ошибка!\nПопробуйте ещё раз:");
        rewind(stdin);
    }
    return tutu;
}
// ВВОД ЗНАЧЕНИЙ
int enter_color()
{
    int color = 0;
    while (!scanf_s("%d", &color) || getchar() != '\n' || color < 0 || color > 3)
    {
        printf("Ошибка!\nПопробуйте ещё раз:");
        rewind(stdin);
    }
    return color;
}

//! НАБОР ВЗАИМОДЕЙСТВУЮЩИХ ФУНКЦИЙ КОТОРЫЕ СОРТИРУЮТ ПО КРИТЕРИЯМ: "срок службы" "цена" "высота" "цвет"
void shellSort(Building *buildings, int arraySize, int (*cmp)(const void *, const void *))
{
    int j = 0;
    struct Building temp;
    for (int gap = arraySize / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arraySize; i++)
        {
            temp = buildings[i];
            for (j = i; j >= gap && cmp(&buildings[j - gap], &temp) > 0; j -= gap)
            {
                buildings[j] = buildings[j - gap];
            }
            buildings[j] = temp;
        }
    }
}
// НАБОР ВЗАИМОДЕЙСТВУЮЩИХ ФУНКЦИЙ КОТОРЫЕ СОРТИРУЮТ ПО КРИТЕРИЯМ: "срок службы" "цена" "высота" "цвет"
int cmp_service_life(const void *a, const void *b)
{
    const Building *s1 = (const Building *)a;
    const Building *s2 = (const Building *)b;
    return s1->service_life - s2->service_life;
}
// НАБОР ВЗАИМОДЕЙСТВУЮЩИХ ФУНКЦИЙ КОТОРЫЕ СОРТИРУЮТ ПО КРИТЕРИЯМ: "срок службы" "цена" "высота" "цвет"
int cmp_price(const void *a, const void *b)
{
    const Building *s1 = (const Building *)a;
    const Building *s2 = (const Building *)b;
    return s1->price - s2->price;
}
// НАБОР ВЗАИМОДЕЙСТВУЮЩИХ ФУНКЦИЙ КОТОРЫЕ СОРТИРУЮТ ПО КРИТЕРИЯМ: "срок службы" "цена" "высота" "цвет"
int cmp_height(const void *a, const void *b)
{
    const Building *s1 = (const Building *)a;
    const Building *s2 = (const Building *)b;
    return s1->height - s2->height;
}
// НАБОР ВЗАИМОДЕЙСТВУЮЩИХ ФУНКЦИЙ КОТОРЫЕ СОРТИРУЮТ ПО КРИТЕРИЯМ: "срок службы" "цена" "высота" "цвет"
int cmp_color(const void *a, const void *b)
{
    const Building *s1 = (const Building *)a;
    const Building *s2 = (const Building *)b;
    return s1->color - s2->color;
}

//! Функция для создания массива структур
Building *create_buildings_array(int n)
{
    Building *buildings = (Building *)malloc(n * sizeof(Building));
    if (buildings == NULL)
    {
        printf("Ошибка выделения памяти!");
        return NULL;
    }
    return buildings;
}

//! Функция для вывода массива структур на экран
void print_buildings_array(Building *buildings, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Здание %d: \n", i + 1);
        printf("По улице: %s", buildings[i].street);
        printf("Срок службы в годах: %d\n", buildings[i].service_life);
        printf("Цена: %d\n", buildings[i].price);
        printf("Высота: %d\n", buildings[i].height);
        printf("Цвет: %d\n(0 - Красный, 1 - Голубой, 2 - Зелёный, 3 - Жёлтый)\n\n", buildings[i].color);
        // printf("Здание %d:\nПо улице: %d\nСрок службы: %d\nЦена: %d\nВысота: %d\nЦвет: %d\nЦвета: (0 - Красный сарай , 1 - Голубой, просто голубой... , 2 - Зелёный лес, 3 - Жёлтый, не оранжевый )\n\n", i + 1, buildings[i].streat, buildings[i].service_life, buildings[i].price, buildings[i].height, buildings[i].color);
    }
}

//! Функция для инициализации экземпляра структуры
Building init_building(int service_life, int price, int height, Color color, char *streat)
{
    Building building;
    building.service_life = service_life;
    building.price = price;
    building.height = height;
    building.color = color;
    building.street = streat;
    return building;
}

//! Функция для сортировки массива по полю "цвет" и "срок службы"
//! массив структур будет отсортирован по цвету здания, а затем по сроку его службы,
//! причем здания одного цвета будут расположены рядом.
void sort_by_color_and_service_life(Building *buildings, int n)
{
    Building temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (buildings[j].color > buildings[j + 1].color)
            {
                temp = buildings[j];
                buildings[j] = buildings[j + 1];
                buildings[j + 1] = temp;
            }
            if (buildings[j].color == buildings[j + 1].color && buildings[j].service_life > buildings[j + 1].service_life)
            {
                temp = buildings[j];
                buildings[j] = buildings[j + 1];
                buildings[j + 1] = temp;
            }
        }
    }
}

//! Удаление структуры
Building *delete(Building *buildings, int *n, int index)
{
    if ((*n) == 0)
    {
        exit(-1);
    }

    for (int i = index; i < (*n) - 1; i++)
    {
        buildings[i] = buildings[i + 1];
    }

    if (*n != 0)
    {
        (*n)--;
        buildings = (Building *)realloc(buildings, (*n) * sizeof(Building));
    }

    printf("Здание %d было удалено.\n", index);
    return buildings;
}
Building *add_build(Building *buildings, int *n)
{
    (*n)++;
    buildings = (Building *)realloc(buildings, (*n) * sizeof(Building));
    if (buildings == NULL)
    {
        return NULL;
    }

    int service_life, price, height, color;
    char *street = NULL;
    street = calloc(255, sizeof(char));
    if (street == NULL)
    {
        printf("Ошибка выделения памяти!");
        exit(-1);
    }
    printf("Введите название улицы для здания %d: ", (*n));
    fgets(street, 254, stdin);
    int size_char = strlength(street);
    if (size_char == 0)
    {
        printf("Ошибка выделения памяти!");
        exit(-1);
    }
    printf("Срок службы в годах: ");
    service_life = enter();
    printf("Цена: ");
    price = enter();
    printf("Высота: ");
    height = enter();
    printf("Цвет: (0 - Красный, 1 - Голубой, 2 - Зелёный, 3 - Жёлтый): ");
    color = enter_color();
    buildings[(*n) - 1] = init_building(service_life, price, height, color, street);
    system("CLS");
    return buildings;
}
// сортировка хаора по улицам в алфавитном порядке
void qsortSort(Building *buildings, int N)
{
    qsortSortRecursion(buildings, 0, N - 1);
}
void qsortSortRecursion(Building *buildings, int low, int high)
{
    if (low < high)
    {
        int pivot_index = patrition(buildings, low, high);
        qsortSortRecursion(buildings, low, pivot_index - 1);
        qsortSortRecursion(buildings, pivot_index + 1, high);
    }
}
int patrition(Building *buildings, int low, int high)
{
    int i = low;
    char *pivot_value = buildings[high].street;
    Building temp;
    for (int j = low; j < high; j++)
    {
        if (strcmp(buildings[j].street, pivot_value) < 0)
        {
            temp = buildings[i];
            buildings[i] = buildings[j];
            buildings[j] = temp;
            i++;
        }
    }

    temp = buildings[i];
    buildings[i] = buildings[high];
    buildings[high] = temp;

    return i;
}

//! Функция налаживает взаимодействие между функциями выше
int performance(int n, Building *buildings, int index, int choice)
{
    do
    {
        printf("\nВыберите опцию:\n");
        printf("1. Вывести список зданий\n");
        printf("2. Сортировать по сроку службы\n");
        printf("3. Сортировать по цене\n");
        printf("4. Сортировать по высоте\n");
        printf("5. Сортировать по цвету\n");
        printf("6. Сортировка по цвету и сроку службы\n");
        printf("7. Снести здание\n");
        printf("8. Отсортировать по улицам\n");
        printf("9. Построить здание\n");
        printf("0. Выход\nВаш выбор:");
        choice = enter_num();
        system("CLS");
        int (*cmp)(const void *, const void *);
        switch (choice)
        {
        case 1:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            print_buildings_array(buildings, n);
            break;
        case 2:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            cmp = &cmp_service_life;
            shellSort(buildings, n, cmp);
            printf("Отсортировать по сроку службы.\n");
            break;
        case 3:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            cmp = &cmp_price;
            shellSort(buildings, n, cmp);
            printf("Отсортировано по цене.\n");
            break;
        case 4:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            cmp = &cmp_height;
            shellSort(buildings, n, cmp);
            printf("Отсортировано по высоте.\n");
            break;
        case 5:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            cmp = &cmp_color;
            shellSort(buildings, n, cmp);
            printf("Отсортировано по цвету.\n");
            break;
        case 6:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            sort_by_color_and_service_life(buildings, n);
            printf("Сортировка по цвету и сроку службы.\n");
            break;
        case 7:
            if (n == 0)
            {
                printf("У вас нет зданий! Добро пожаловать на улицу.\n");
                break;
            }
            printf("Введите номер здания которое надо снести (начиная с 0): ");
            index = delete_inx(n);
            buildings = delete (buildings, &n, index);
            break;
        case 8:
            printf("Отсортированно по улицам.\n");
            qsortSort(buildings, n);
            break;
        case 9:
            buildings = add_build(buildings, &n);
            break;
        case 0:
            printf("Пока!\n");
            exit(0);
            break;
        default:;
        }
    } while (choice != 0);
    return n;
}
// по сути ввод элементов
void enter_elements(Building *buildings, int n)
{
    for (int i = 0; i < n; i++)
    {
        int service_life, price, height, color;
        char *street = NULL;
        street = calloc(255, sizeof(char));

        printf("Введите название улицы для здания %d: ", i + 1);
        fgets(street, 254, stdin);

        printf("Срок службы в годах: ");
        service_life = enter();
        printf("Цена: ");
        price = enter();
        printf("Высота: ");
        height = enter();
        printf("Цвет: (0 - Красный, 1 - Голубой, 2 - Зелёный, 3 - Жёлтый): ");
        color = enter_color();
        buildings[i] = init_building(service_life, price, height, color, street);
        system("CLS");
    }
}

int strlength(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
