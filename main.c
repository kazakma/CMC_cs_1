#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int k1 = 0, k2 = 0;
void swap(long long int *a, long long int *b){
    k1++;
    long long int temp = *a;
    *a = *b; *b = temp;
    return;
}

int cmp(long long int a, long long int b){
    k2++;
    return llabs(a) < llabs(b);
    }

void bubble(long long int *a, int n){
    int i, j;
    for (i = 0; i < n - 1; i++)//��������� �� ���������� �������� �� �������������
        for (j = 0; j < n - i - 1; j++)//����� ������� ������� ���������� �������� ���������������
            if (cmp(a[j], a[j + 1])) swap(&a[j], &a[j + 1]);
}

void quick(long long int *a, int i){
    q(a, 0, i - 1);
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

void check(int n){
    long long int a[n];
    long long int aw[n];
    printf("������:\n");
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        aw[i] = a[i];
    }
    bubble(a, n);
    printf("����� ��������:\n");
    print(a, n);
    printf("\n");
    quick(aw, n);
    printf("����� �������:\n");
    print(aw, n);
}

void cook(long long int *a, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = (rand() - RAND_MAX) * rand() * rand();//��������� ���������� ����������
}

void straight(long long int *a, int n){
    for (int i = 0; i < n; i++) a[i] = i;//
}

void rev(long long int *a, int n){
    for (int i = 0; i < n; i++) a[i] = n - 1 -i;//
}

void print(long long int *a, int n){
    for (int i = 0; i < n; i++) printf("%lld ", a[i]);
}

void part(long long int *a, long long int *aw, int i){
    k1 = 0; k2 = 0;
    printf("\t�������� ������: ");
    print(a, i);
    printf("\n");
    memcpy(aw, a, i * sizeof(long long int));
    k1 = 0; k2 = 0;
    bubble(aw, i);
    printf("\n\t����� ��������: ");
    print(aw, i);
    printf("\n\t ������������: %d ���������: %d\n", k1, k2);
    memcpy(aw, a, i * sizeof(long long int));
    k1 = 0; k2 = 0;
    quick(aw, i);
    printf("\n\t����� �������: ");
    print(aw, i);
    printf("\n\t ������������: %d ���������: %d\n", k1, k2);
    printf("\n");
}

int main(void)
{
    printf("���������� ���������:\n");
    int a; scanf("%d", &a);
    check(a);
    for (int i = 10; i <= 10; i *= 10){
        long long int *a = malloc(i * sizeof(long long int));
        long long int *aw = malloc(i * sizeof(long long int));

        cook(a, i);
        printf("\nC�������� �����\n");
        part(a, aw, i);

        straight(a, i);
        printf("\������ �������\n");
        part(a, aw, i);

        rev(a, i);
        printf("\�������� �������\n");
        part(a, aw, i);

        free(a);
        free(aw);
        printf("\n");
    }
    return 0;
}
