#include <stdio.h>
#include <ctype.h>
#include <string.h>


void nhapChuoi(char *str);
void inChuoi(char *str);
int demChuCai(char *str);
int demChuSo(char *str);
int demKyTuDacBiet(char *str);
int main() {
    char str[100];
    int choice;
    
    while (choice !=6) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Ðem so luong chu cai trong chuoi va in ra\n");
        printf("4. Ðem so luong chu so trong chuoi va in ra\n");
        printf("5. Ðem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                nhapChuoi(str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                printf("So luong chu cai trong chuoi la: %d\n", demChuCai(str));
                break;
            case 4:
                printf("So luong chu so trong chuoi la: %d\n", demChuSo(str));
                break;
            case 5:
                printf("So luung ky ty dac biet trong chuoi la: %d\n", demKyTuDacBiet(str));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    }

    return 0;
}
void nhapChuoi(char *str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void inChuoi(char *str) {
    printf("Chuoi ban da nhap: %s\n", str);
}

int demChuCai(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int demChuSo(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int demKyTuDacBiet(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str)) {
            count++;
        }
        str++;
    }
    return count;
}


