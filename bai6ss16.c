#include <stdio.h>

struct SinhVien {
    char ho_ten[50];
    int tuoi;
    char so_dien_thoai[15];
    char email[50];
};

int main() {
    FILE *file;
    char ten_file[] = "students.txt";
    int so_luong_sv;

    file = fopen(ten_file, "w");

    if (file == NULL) {
        printf("khong mo duoc file\n");
        return 1;
    }

    printf("nhap so luong sinh vien: ");
    scanf("%d", &so_luong_sv);

    struct SinhVien ds_sinh_vien[so_luong_sv];

    for (int i = 0; i < so_luong_sv; i++) {
        printf("nhap thong tin cho sinh vien %d:\n", i + 1);
        printf("ho ten: ");
        scanf(" %[^\n]", ds_sinh_vien[i].ho_ten);
        printf("tuoi: ");
        scanf("%d", &ds_sinh_vien[i].tuoi);
        printf("so dien thoat: ");
        scanf(" %[^\n]", ds_sinh_vien[i].so_dien_thoai);
        printf("Email: ");
        scanf(" %[^\n]", ds_sinh_vien[i].email);

        fprintf(file, "%s %d %s %s\n", ds_sinh_vien[i].ho_ten, ds_sinh_vien[i].tuoi,
                ds_sinh_vien[i].so_dien_thoai, ds_sinh_vien[i].email);
    }

    fclose(file);
    file = fopen(ten_file, "r");

    if (file == NULL) {
        printf("khong mo duoc file\n");
        return 1;
    }

    printf("thong tin cua sinh vien %s:\n", ten_file);

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);

    return 0;
}

