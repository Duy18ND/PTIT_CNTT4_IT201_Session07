#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    //B1: Khoi tao mang 2 mang con ben trai va ben phai
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int leftArr[leftLength], rightArr[rightLength];

    //B2: Copy cac gia tri tu mang vao 2 mang con
    for (int i = 0; i < leftLength; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightLength; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    //B3: Tron 2 mang con lai trong mang ban dau
    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int arrIndex = left;

    while (leftArrIndex < leftLength && rightArrIndex < rightLength) {
        if (leftArr[leftArrIndex] <= rightArr[rightArrIndex]) {
            arr[arrIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
        } else {
            arr[arrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
        }
        arrIndex++;
    }

    while (leftArrIndex < leftLength) {
        arr[arrIndex] = leftArr[leftArrIndex];
        leftArrIndex++;
        arrIndex++;
    }

    while (rightArrIndex < rightLength) {
        arr[arrIndex] = rightArr[rightArrIndex];
        rightArrIndex++;
        arrIndex++;
    }
}

void mergeSort(int arr[], int left, int right) {
    //Xay dung dieu kien dung
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;

    //Giai quyet bai toan con voi mang ben trai
    mergeSort(arr, left, mid);
    //Giai quyet bai toan con voi mang ben phai
    mergeSort(arr, mid + 1, right);
    //Tien hanh tron 2 bai toan con lai trong mang
    merge(arr, left, mid, right);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int size;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &size);

    if (size <= 0 || size > 1000) {
        printf("So luong khong hop le!\n");
        return 1;
    }

    int arr[size];

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Mang sau khi sap xep (tang dan):\n");
    printArray(arr, size);

    return 0;
}
