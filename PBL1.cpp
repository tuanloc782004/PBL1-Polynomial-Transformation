#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX = 10;

int i, j;
char address[50];
double a[MAX][MAX];

bool isEmpty(FILE *f);
void initRandom(int &n, double &c, double a[MAX][MAX]);
int getRandom(int min, int max);
void initFromFile(int &n, double &c, double a[MAX][MAX], char address[]);
void enterAddressFile(char address[]);
void eraseEnter(char x[]);
void initFromKeyboard(int &n, double &c, double a[MAX][MAX]);
void out(int n, double a[MAX][MAX], double c);
void gen(int n, double c, double a[MAX][MAX], double p);


bool isEmpty(FILE *f) {
    return f == NULL;
}

void initRandom(int &n, double &c, double a[MAX][MAX]) {
    printf("\tINFORMATION");
    n = getRandom(5, MAX);
    printf("\nBac cua da thuc: n = %d", n);
    printf("\nCac he so:");
    for (i = 0; i <= n; i++) {
        a[0][i] = getRandom(-10, 10);
        printf("\na[%d] = %.0lf", n - i, a[0][i]);
    }
    c = getRandom(-10, 10);
    printf("\nGia tri can tinh: c = %.0lf\n", c);
}

int getRandom(int min, int max) {
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

void initFromFile(int &n, double &c, double a[MAX][MAX], char address[]) {
    printf("\n-------------------------------------------------------\n\tINFORMATION\n");
    printf("\nAddress File: %s", address);
    FILE *f;
    f = fopen(address, "r");
    if (isEmpty(f)) {
        printf("\nError!\n");
        return;
    }
    fscanf(f, "%d", &n);
    printf("\nBac cua da thuc: n = %d", n - i);
    for (i = n; i >= 0; i--) {
        fscanf(f, "%lf", &a[0][n - i]);
        printf("\na[%d]= %.2lf", i, a[0][n - i]);
    }
    fscanf(f, "%lf", &c);
    printf("\nGia tri can tinh: c = %.2lf\n", c);
    fclose(f);
}

void enterAddressFile(char address[]) {
    int test = 0;
    fflush(stdin);
    printf("=> Enter Address File *.INP (vidu1/vidu2/vidu3): ");
    fgets(address, 50, stdin);
    eraseEnter(address);
    int size = strlen(address);
    for (j = 0; j < size; j++)
        if (address[j] == '.') {
            test = 1;
            break;
        }
    if (test != 1)
        strcat(address, ".INP");
}

void eraseEnter(char x[]) {
    int size = strlen(x);
    if (x[size - 1] == '\n')
        x[size - 1] = '\0';
}

void initFromKeyboard(int &n, double &c, double a[MAX][MAX]) {
    printf("\tINFORMATION");
    printf("\nBac cua da thuc: n = ");
    scanf("%d", &n);
    printf("Cac he so:\n");
    for (i = 0; i <= n; i++) {
        printf("a[%d] = ", n - i);
        scanf("%lf", &a[0][i]);
    }
    printf("Gia tri can tinh: c = ");
    scanf("%lf", &c);
}

void out(int n, double a[MAX][MAX], double c) {
    printf("\n-------------------------------------------------------\n\tOUTPUT\n");
    FILE *f;
    f = fopen("PBL1.OUT", "w");
    if (isEmpty(f)) {
        printf("Error!");
        return;
    }
    double temp = c;
    if (temp > 0) {
        printf("\np(x-%.2lf) = ", temp);
        fprintf(f, "p(x-%.2lf) = ", temp);
    } else if (temp < 0) {
        printf("\np(x+%.2lf) = ", -temp);
        fprintf(f, "p(x+%.2lf) = ", -temp);
    } else {
        printf("\np(x) = ", temp);
        fprintf(f, "p(x) = ", temp);
    }
    for (i = n; i >= 0; i--) {
        if (i == n) {
            if (a[i][n - i] == 1) {
                printf("(x^%d)", i);
                fprintf(f, "(x^%d)", i);
            } else {
                printf("%.2lf(x^%d)", a[i][n - i], i);
                fprintf(f, "%.2lf(x^%d)", a[i][n - i], i);
            }
        } else if (i == 1) {
            if (a[i][n - i] < 0) {
                printf("%.2lfx", a[i][n - i]);
                fprintf(f, "%.2lfx", a[i][n - i]);
            }
            if (a[i][n - i] > 0) {
                printf("+%.2lfx", a[i][n - i]);
                fprintf(f, "+%.2lfx", a[i][n - i]);
            }
            if (a[i][n - i] == 0)
                continue;
        } else if (i == 0) {
            if (a[i][n - i] < 0) {
                printf("%.2lf", a[i][n - i]);
                fprintf(f, "%.2lf", a[i][n - i]);
            }
            if (a[i][n - i] > 0) {
                printf("+%.2lf", a[i][n - i]);
                fprintf(f, "+%.2lf", a[i][n - i]);
            }
            if (a[i][n - i] == 0)
                continue;
        } else {
            if (a[i][n - i] < 0) {
                printf("%.2lf(x^%d)", a[i][n - i], i);
                fprintf(f, "%.2lf(x^%d)", a[i][n - i], i);
            }
            if (a[i][n - i] > 0) {
                printf("+%.2lf(x^%d)", a[i][n - i], i);
                fprintf(f, "+%.2lf(x^%d)", a[i][n - i], i);
            }
            if (a[i][n - i] == 0)
                continue;
        }
    }
    printf("\n");
    fclose(f);
}

void gen(int n, double c, double a[MAX][MAX]) {
    double p = 0;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n - i; j++) {
            p = p * (-c) + a[i][j];
            a[i + 1][j] = p;
            a[i][j] = p;
        }
        p = 0;
    }
}

int main() {
    int n;
    double c;
    int choice1, choice2;
menu:
    while (1) {
        printf("\n-------------------------------------------------------\n\tMENU\n");
        printf("1- Input\n");
        printf("2- Output\n");
        printf("0- Exit\n");
        printf("\n=> Enter choice: ");
        scanf("%d", &choice1);
        switch (choice1) {
            case 1:
                printf("\n-------------------------------------------------------\n\tMENU-INPUT\n");
                printf("1- Input random\n");
                printf("2- Input from FILE\n");
                printf("3- Input from keyboard\n");
                printf("0- Back to MENU\n");
                printf("\n=> Enter choice: ");
                scanf("%d", &choice2);
                printf("\n-------------------------------------------------------\n");
                switch (choice2) {
                    case 1:
                        initRandom(n, c, a);
                        break;
                    case 2:
                        enterAddressFile(address);
                        initFromFile(n, c, a, address);
                        break;
                    case 3:
                        initFromKeyboard(n, c, a);
                        break;
                    default:
                        goto menu;
                }
                break;
            case 2:
                gen(n, c, a);
                out(n, a, c);
                break;
            default:
                return 0;
        }
    }
}

