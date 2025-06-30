#include <stdio.h>
#include <stdlib.h>

void bubbleSortColumn(int **arr, int rows, int cols, int k);
void printArray(int **arr, int rows, int cols);

int main() {
    int rows, cols;
    printf("Nhap rows: ");
    scanf("%d", &rows);
    printf("Nhap cols: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("So luong rows cols khong hop le!\n");
        return 1;
    }

    // Cap phat mang 2 chieu dong
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Nhap mang
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    printf("Nhap cot can sap xep (bat dau tu 0): ");
    scanf("%d", &k);

    if (k < 0 || k >= cols) {
        printf("Cot khong hop le!\n");
        // Giai phong bo nho truoc khi thoat
        for (int i = 0; i < rows; i++) free(arr[i]);
        free(arr);
        return 1;
    }

    printf("Mang truoc khi sap xep:\n");
    printArray(arr, rows, cols);

    bubbleSortColumn(arr, rows, cols, k);

    printf("Mang sau khi sap xep cot %d:\n", k);
    printArray(arr, rows, cols);

    // Giai phong bo nho
    for (int i = 0; i < rows; i++) free(arr[i]);
    free(arr);

    return 0;
}

void bubbleSortColumn(int **arr, int rows, int cols, int k) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - 1 - i; j++) {
            if (arr[j][k] > arr[j+1][k]) {
                int temp = arr[j][k];
                arr[j][k] = arr[j+1][k];
                arr[j+1][k] = temp;
            }
        }
    }
}

void printArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
