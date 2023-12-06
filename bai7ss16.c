#include <stdio.h>
#include <stdlib.h>

struct Sach {
    char ma_sach[10];
    char ten_sach[50];
    char tac_gia[30];
    float gia_tien;
    char the_loai[20];
};

void nhap_thong_tin_sach(struct Sach *sach, int *so_luong) {
    printf("Nhap so luong sach: ");
    scanf("%d", so_luong);

    for (int i = 0; i < *so_luong; i++) {
        printf("Nhap thong tin cho sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", sach[i].ma_sach);
        printf("Ten sach: ");
        scanf("%s", sach[i].ten_sach);
        printf("Tac gia: ");
        scanf("%s", sach[i].tac_gia);
        printf("Gia tien: ");
        scanf("%f", &sach[i].gia_tien);
        printf("The loai: ");
        scanf("%s", sach[i].the_loai);
    }
}

void luu_vao_file(struct Sach *sach, int so_luong) {
    FILE *file;
    file = fopen("books.txt", "w");

    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", so_luong);

    for (int i = 0; i < so_luong; i++) {
        fprintf(file, "%s %s %s %.2f %s\n", sach[i].ma_sach, sach[i].ten_sach, sach[i].tac_gia, sach[i].gia_tien, sach[i].the_loai);
    }

    fclose(file);
}

void hien_thi_tu_file() {
    FILE *file;
    file = fopen("books.txt", "r");

    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        exit(EXIT_FAILURE);
    }

    int so_luong;
    fscanf(file, "%d", &so_luong);

    printf("\nDanh sach sach tu file:\n");
    for (int i = 0; i < so_luong; i++) {
        struct Sach sach;
        fscanf(file, "%s %s %s %f %s", sach.ma_sach, sach.ten_sach, sach.tac_gia, &sach.gia_tien, sach.the_loai);
        printf("%s %s %s %.2f %s\n", sach.ma_sach, sach.ten_sach, sach.tac_gia, sach.gia_tien, sach.the_loai);
    }

    fclose(file);
}

int main() {
    int lua_chon;
    struct Sach books[100];
    int so_luong_sach;

    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Hien thi thong tin sach tu file\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                nhap_thong_tin_sach(books, &so_luong_sach);
                break;
            case 2:
                luu_vao_file(books, so_luong_sach);
                printf("Da luu thong tin sach vao file.\n");
                break;
            case 3:
                hien_thi_tu_file();
                break;
            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (lua_chon != 4);

    return 0;
}
