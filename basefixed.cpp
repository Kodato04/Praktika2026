#include <stdio.h>

int main()
{
    int n;
    printf("Введите количество элементов массива:\n");
    printf("n = ");
    scanf("%d", &n);

    int a[100];
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;\
        }
        a[j + 1] = key;
    }

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    FILE * file;
    file = fopen("/home/user/projects/result.txt", "w");
    fprintf(file, "Отсортированный по возрастанию массив из %d элементов:\n", n);
    for (int i = 0; i < n; i++)
        fprintf(file, "%d ", a[i]);
    fprintf(file, "\n");
    fclose(file);

    printf("Результат выполнения программы записан в файл /home/user/projects/result.txt\n");
    return 0;
}
