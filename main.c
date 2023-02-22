#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int k1 = 0, k2 = 0;
void swap(long long int *f, long long int *s){
    k1++;
    long long int temp = *f;
    *f = *s; *s = temp;
    return;
}

int cmp(long long int f, long long int s){//Функция сравнения
    k2++;
    return llabs(f) < llabs(s);
    }

void bubble(long long int *a, int n){
    int i, j;
    for (i = 0; i < n - 1; i++)//Подмассив из последнего элемента не рассматриваем
        for (j = 0; j < n - i - 1; j++)//После каждого прохода наибольшие элементы упорядочиваются
            if (cmp(a[j], a[j + 1])) swap(&a[j], &a[j + 1]);
}

void quick(long long int *a, int n){
    q(a, 0, n - 1);
}

void q(long long int *a, int l, int r){
  long long int x;
  int i = l, j = r;
  x = a[(l + r) / 2];//Берём элемент в центре массива
  while (i < j){
    while (cmp(x, a[i])) i++;//Ищем слева больше барьера
    while (cmp(a[j], x)) j--;//Ищем справа меньше барьера
    if (i <= j){
        if (i != j) swap(&a[i], &a[j]);//Чтобы не переставлялся сам с собой
        i++; j--;
    }
  }
  if (l < j) q(a, l, j);//Применяем к левой части
  if (i < r) q(a, i, r);//Применяем к правой части
}

void check(int n){//Функция для проверки работы алгоритмов на собственных примерах
    long long int a[n];
    long long int aw[n];
    printf("Array: ");
    for (int i = 0; i < n; i++){//Вводим массив и сразу же делаем его копию
        scanf("%lld", &a[i]);
        aw[i] = a[i];
    }
    bubble(a, n);
    printf("After bubble: ");
    print(a, n);
    printf("\n");
    quick(aw, n);
    printf("After quick: ");
    print(aw, n);
}

void cook(long long int *a, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = (rand() - RAND_MAX) * rand() * rand();//Заполняем случайными элементами
}

void straight(long long int *a, int n){
    for (int i = 0; i < n; i++) a[i] = i;//Заполняем упорядоченными элементами
}

void rev(long long int *a, int n){
    for (int i = 0; i < n; i++) a[i] = n - 1 -i;//Заполняем элементами в обратном порядке
}

void print(long long int *a, int n){
    if (n <= 10) for (int i = 0; i < n; i++) printf("%lld ", a[i]);//Функция вывода
}

void part(long long int *a, int n){//Прогоняем случайный, отсортированный, отсортированный в обратном порядке массивы длины n по каждой из сортировок
    long long int *aw = malloc(n * sizeof(long long int));
    k1 = 0; k2 = 0;
    if (n == 10) printf("\tOriginal array: ");
    print(a, n);
    printf("\n");
    memcpy(aw, a, n * sizeof(long long int));
    k1 = 0; k2 = 0;
    bubble(aw, n);
    printf("\n\tAfter bubble: ");
    print(aw, n);
    printf("\n\t Permutations: %d Comparisons: %d\n", k1, k2);
    memcpy(aw, a, n * sizeof(long long int));
    k1 = 0; k2 = 0;
    quick(aw, n);
    printf("\n\tAfter quick: ");
    print(aw, n);
    printf("\n\t Permutations: %d Comparisons: %d\n", k1, k2);
    printf("\n");
    free(aw);
}

int main(void)
{
    printf("Number of elements: ");
    int x; scanf("%d", &x);
    check(x);
    for (int i = 10; i <= 10000; i *= 10){
        long long int *a = malloc(i * sizeof(long long int));

        cook(a, i);
        printf("\n\t\t\tN = %d\n", i);
        printf("\nRandom\n");
        part(a, i);

        straight(a, i);
        printf("\nStraight\n");
        part(a, i);

        rev(a, i);
        printf("\nReverse\n");
        part(a, i);

        free(a);
        printf("\n");
    }
    return 0;
}
