#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int *a;
    int choice;

    printf("Выберите способ ввода:\n");
    printf("1 - Ручной ввод\n");
    printf("2 - Генерация случайных чисел\n");
    printf("Выбор: ");
    scanf("%d", &choice);

    printf("Введите количество элементов массива:\n");
    printf("n = ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ошибка: количество элементов должно быть положительным.\n");
        return 1;
    }

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    if (choice == 1)
    {
        printf("Введите элементы массива:\n");
        for (int i = 0; i < n; i++)
        {
            printf("a[%d] = ", i);
            scanf("%d", &a[i]);
        }
    }
    else if (choice == 2)
    {
        int min, max;
        printf("Минимальное значение: ");
        scanf("%d", &min);
        printf("Максимальное значение: ");
        scanf("%d", &max);

        if (max < min)
        {
            printf("Ошибка: максимальное значение должно быть больше или равно минимальному.\n");
            free(a);
            return 1;
        }

        if (n > max - min + 1)
        {
            printf("Предупреждение: количество элементов массива больше количества уникальных чисел в заданном диапазоне.\n");
            printf("Генерация невозможна.\n");
            free(a);
            return 1;
        }

        srand(time(NULL));
        int count = 0;
        while (count < n)
        {
            int num = min + rand() % (max - min + 1);
            int found = 0;
            for (int k = 0; k < count; k++)
            {
                if (a[k] == num)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                a[count] = num;
                count++;
            }
        }

        printf("Сгенерированный массив:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
    {
        printf("Ошибка: неверный выбор.\n");
        free(a);
        return 1;
    }

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    FILE *file;
    file = fopen("/home/artem/praktika_random/result.txt", "w");
    if (file == NULL)
    {
        printf("Ошибка при записи файла.\n");
        free(a);
        return 1;
    }
    fprintf(file, "Отсортированный по возрастанию массив из %d элементов:\n", n);
    for (int i = 0; i < n; i++)
        fprintf(file, "%d ", a[i]);
    fprintf(file, "\n");
    fclose(file);

    printf("Результат выполнения программы записан в файл /home/artem/praktika_random/result.txt\n");
    free(a);
    return 0;
}