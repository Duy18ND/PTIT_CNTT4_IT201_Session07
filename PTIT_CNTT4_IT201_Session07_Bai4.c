#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm sắp xếp ký tự trong chuỗi theo bảng chữ cái
void sort(char str[]) {
    int n = strlen(str);
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    // Xoá ký tự xuống dòng nếu có
    str[strcspn(str, "\n")] = '\0';

    if (strlen(str) == 0) {
        printf("Chuoi rong!\n");
        return 0;
    }

    printf("Chuoi truoc khi sap xep: %s\n", str);
    sort(str);
    printf("Chuoi sau khi sap xep: %s\n", str);

    return 0;
}
