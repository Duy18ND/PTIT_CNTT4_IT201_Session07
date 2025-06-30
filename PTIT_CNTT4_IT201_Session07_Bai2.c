#include <stdio.h>

void addArray(int arr[], int size, int index);

void selectionSort(int arr[], int size);

void printArray(int arr[], int size, int index);
int main(void) {
    //Sap xep selection sort

    int size;
    printf("Moi ban nhap so luong cua mang");
    scanf("%d", &size);
    if (size <=0  || size > 1000) {
        printf("So luong phan tu khong hop le!");
        return 1;
    }
    int arr[size];
    //Them gia tri
    addArray(arr, size, 0);
    //Thuat toan sap xep
    selectionSort(arr, size);
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
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int size, int index) {
    if (index >= size) return;
    printf("arr[%d] = %d\n", index, arr[index]);
    printArray(arr, size, index + 1);
}