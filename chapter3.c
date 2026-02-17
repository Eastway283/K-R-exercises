#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50 /* Размера массива для бинарного поиска */

int generate(int min, int max); /* генерирует целое число в диапазоне min - max */

int partition(int* arr, int low, int high); /* Вспомогательные функции быстрой сортировки */ 

void swap(int* a, int* b);

void quick_sort(int* arr, int low, int high); /* Быстрая сортировка в диапазоне low - high */

int binSearch(int x, int arr[], int size); /* Функция бинарного поиска, возвращает индекс искомого элемента, -1 в случае его отсувствия */

int main(void)
{
    srand(time(NULL));

    int i, target;

    int* arr = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
        arr[i] = generate(0, 100);

    quick_sort(arr, 0, SIZE - 1);
    printf("Random array after qsort: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    putchar('\n');

    printf("Enter target element to find\n> ");
    scanf("%d", &target);

    int result_index = binSearch(target, arr, SIZE);
    if (result_index >= 0)
        printf("Index of your element: %d\n", result_index);
    else
        printf("Your target element not found!\n");

    free(arr);

    return 0;
}

int generate(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int i, j, pivot;
    i = low - 1;
    pivot = arr[high];

    for (j = low; j < high; j++)
        if (arr[j] <= pivot)
            swap(&arr[j], &arr[++i]);

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pivIndex = partition(arr, low, high);

        quick_sort(arr, low, pivIndex - 1);
        quick_sort(arr, pivIndex + 1, high);
    }
}

int binSearch(int x, int* arr, int size)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low < high)
    {
        mid = ((low + high) / 2) + 1;
        if (x < arr[mid])
            high = mid - 1;
        else 
            low = mid;
    }

    return (x == arr[low]) ? low : -1;
}
