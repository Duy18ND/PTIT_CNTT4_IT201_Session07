#include <stdio.h>

void addArray(int arr[], int size, int index);
void bubblueSort(int arr[], int size);
void printArray(int arr[], int size, int index);
int main(void) {
        //Sap xep noi bot
    int size;
    printf("Moi ban nhap do dai cua mang");
    scanf("%d", &size);

    if (size <= 0 || size > 1000) {
        printf("Do dai mang khong hop le!");
    }
    int arr[size];

    //Nhap cac phan tu cua mang
    addArray(arr, size, 0);
    //Thuat toan sap xep
    bubblueSort(arr, size);
    //In
    printArray(arr, size, 0);
    return 0;
}

void addArray(int arr[], int size, int index) {
    if (index >= size) return;
    printf("arr[%d] = ",index);
    scanf("%d",&arr[index]);
    addArray(arr, size, index +1);
}

void bubblueSort(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0 ; j < size - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
}

void printArray(int arr[], int size, int index) {
        if (index >= size) return;

    printf("arr[%d] = %d \n", index, arr[index]);
    printArray(arr, size, index + 1);
}