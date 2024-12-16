#include <stdio.h>

void nhapMang(int arr[], int n);
int main() {
    int arr[100]; 
    int n = 0;
    int choice;

    while (choice!=6) {
        printf("\nMENU\n");
        printf("1. Nhap do dai mang va so phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");

        printf("Chon chuc nang (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu trong mang: ");
                scanf("%d", &n);
                nhapMang(arr, n);
                break;
            case 2:
                if (n > 0) {
                    hienThiMang(arr, n);
                } else {
                    printf("Chua co mang, ban vui long chon 1 de dien mang\n");
                }
                break;
            case 3:
                if (n > 0) {
                    printf("Do dai mang la: %d\n", tinhDoDaiMang(n));
                } else {
                    printf("Chua co mang, ban vui long chon 1 de dien mang\n");
                }
                break;
            case 4:
                if (n > 0) {
                    printf("Tong cac phan tu trong mang la: %d\n", tinhTongMang(arr, n));
                } else {
                    printf("Chua co mang, ban vui long chon 1 de dien mang\n");
                }
                break;
            case 5:
                if (n > 0) {
                    printf("Phan tu lon nhat trong mang la: %d\n", timPhanTuLonNhat(arr, n));
                } else {
                    printf("Chua co mang, ban vui long chon 1 de dien mang.\n");
                }
                break;
            case 6:
                printf("Thoat khoi chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon cua ban khong hop le. Vui long nhap lai.\n");
                break;
        }
    }

    return 0;
}

void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu mang %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int arr[], int n) {
    printf("Các ph?n t? trong m?ng: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhDoDaiMang(int n) {
    return n;
}

int tinhTongMang(int arr[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}

int timPhanTuLonNhat(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

