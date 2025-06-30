#include <stdio.h>

void addArray(int arr[], int size, int index);

void insertionSort(int arr[], int size);

void printArray(int arr[], int size, int index);

int main() {
        //thuat toan sap xep chen
    int size;
    printf("Nhap so luong phan tu ");
    scanf("%d", &size);
    if (size <= 0 || size > 1000) {
        printf("So luong phan tu khong hop le!");
        return 1;
    }
    int arr[size];
    //Nhap cac phan tu cua mang
    addArray(arr, size, 0);
    //Thuat toan sap xep
    insertionSort(arr, size);
    //In
    printArray(arr, size, 0);
    return 0;
}

void addArray(int arr[], int size, int index) {
    if (index >= size)return;
    printf("arr[%d] = ", index);
    scanf("%d", &arr[index]);
    addArray(arr, size, index + 1);
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size, int index) {
    if (index >= size) return;
    printf("arr[%d] = %d\n", index, arr[index]);
    printArray(arr, size, index + 1);
}