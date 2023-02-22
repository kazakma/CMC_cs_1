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

int cmp(long long int f, long long int s){//������� ���������
    k2++;
    return llabs(f) < llabs(s);
    }

void bubble(long long int *a, int n){
    int i, j;
    for (i = 0; i < n - 1; i++)//��������� �� ���������� �������� �� �������������
        for (j = 0; j < n - i - 1; j++)//����� ������� ������� ���������� �������� ���������������
            if (cmp(a[j], a[j + 1])) swap(&a[j], &a[j + 1]);
}

void quick(long long int *a, int n){
    q(a, 0, n - 1);
}

void q(long long int *a, int l, int r){
  long long int x;
  int i = l, j = r;
  x = a[(l + r) / 2];//���� ������� � ������ �������
  while (i < j){
    while (cmp(x, a[i])) i++;//���� ����� ������ �������
    while (cmp(a[j], x)) j--;//���� ������ ������ �������
    if (i <= j){
        if (i != j) swap(&a[i], &a[j]);//����� �� ������������� ��� � �����
        i++; j--;
    }
  }
  if (l < j) q(a, l, j);//��������� � ����� �����
  if (i < r) q(a, i, r);//��������� � ������ �����
}

void check(int n){//������� ��� �������� ������ ���������� �� ����������� ��������
    long long int a[n];
    long long int aw[n];
    printf("Array: ");
    for (int i = 0; i < n; i++){//������ ������ � ����� �� ������ ��� �����
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
    for (int i = 0; i < n; i++) a[i] = (rand() - RAND_MAX) * rand() * rand();//��������� ���������� ����������
}

void straight(long long int *a, int n){
    for (int i = 0; i < n; i++) a[i] = i;//��������� �������������� ����������
}

void rev(long long int *a, int n){
    for (int i = 0; i < n; i++) a[i] = n - 1 -i;//��������� ���������� � �������� �������
}

void print(long long int *a, int n){
    if (n <= 10) for (int i = 0; i < n; i++) printf("%lld ", a[i]);//������� ������
}

void part(long long int *a, int n){//��������� ���������, ���������������, ��������������� � �������� ������� ������� ����� n �� ������ �� ����������
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
