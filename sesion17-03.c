#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char *str);
void inDaoNguoc(char *str);
int demSoLuongTu(char *str);
void soSanhChieuDai(char *str1, char *str2);
void inHoaChuoi(char *str);
void themChuoi(char *str1, char *str2);

int main() {
    char chuoi1[200], chuoi2[100];
    int choice;

    while (choice!=7) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Ðem so luong ty trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");

        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(chuoi1);
                break;
            case 2:
                inDaoNguoc(chuoi1);
                break;
            case 3:
                printf("So luong tu trong chuoi là: %d\n", demSoLuongTu(chuoi1));
                break;
            case 4:
                printf("Nhap chuoi khac de so sánh: ");
                fgets(chuoi2, 100, stdin);
                chuoi2[strcspn(chuoi2, "\n")] = '\0';
                soSanhChieuDai(chuoi1, chuoi2);
                break;
            case 5:
                inHoaChuoi(chuoi1);
                break;
            case 6:
                printf("Nhap chuoi khac de them vao chuoi ban dau: ");
                fgets(chuoi2, 100, stdin);
                chuoi2[strcspn(chuoi2, "\n")] = '\0';
                themChuoi(chuoi1, chuoi2);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon cua ban khong hop le vui long nhap lai.\n");
        }
    }

    return 0;
}

void nhapChuoi(char *str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void inDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int demSoLuongTu(char *str) {
    int count = 0;
    int inWord = 0;

    while (*str) {
        if (isspace(*str)) {
            inWord = 0; 
        } else if (!inWord) {
            inWord = 1; 
            count++;
        }
        str++;
    }
    return count;
}

void soSanhChieuDai(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2) {
        printf("Chuoi thu hai dai hon chuoi dau tien.\n");
    } else if (len1 > len2) {
        printf("Chuoi thu nhat dai hon chuoi thu hai.\n");
    } else {
        printf("Hai chuoi co chieu dai bang nhau.\n");
    }
}

void inHoaChuoi(char *str) {
    while (*str) {
        printf("%c", toupper(*str));
        str++;
    }
    printf("\n");
}

void themChuoi(char *str1, char *str2) {
    strcat(str1, str2);
    printf("Chuoi sau khi them la: %s\n", str1);
}


