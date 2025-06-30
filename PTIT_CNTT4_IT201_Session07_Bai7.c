#include <stdio.h>

void addArray(int arr[], int size, int index);
void wax(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int size;
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Phan tu ban nhap vao khong hop le!\n");
        return 1;
    }

    int arr[size];

    addArray(arr, size, 0);

    printf("Mang truoc khi sap xep: ");
    printArray(arr, size);

    wax(arr, size);

    printf("Mang sau khi sap xep: ");
    printArray(arr, size);

    return 0;
}

void addArray(int arr[], int size, int index) {
    if (index >= size) return;
    printf("arr[%d] = ", index);
    scanf("%d", &arr[index]);
    addArray(arr, size, index + 1);
}

// sap xep
void wax(int arr[], int size) {
    int temp[size];
    int found = 0;

    // sap xep nho hon 0
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            temp[found++] = arr[i];
    }

    // Sap xep = 0
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            temp[found++] = arr[i];
    }

    // sap xep lon hon 0
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            temp[found++] = arr[i];
    }

    // Gan mang
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

// in
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}
