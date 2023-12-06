#include <stdio.h>
//C:\\Users\\Admin\\Desktop\\BT03.txt
int main() {
    FILE *file;
    char ten_file[] = "C:\\Users\\Admin\\Desktop\\BT03.txt";
    int so_dong;
    file = fopen(ten_file, "w");

    if (file == NULL) {
        printf("khong mo duoc file \n");
        return 1;
    }

    printf("Nhap so dong: ");
    scanf("%d", &so_dong);
    char noi_dung_dong[100];
    for (int i = 0; i < so_dong; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        scanf(" %[^\n]", noi_dung_dong);
        fprintf(file, "%s\n", noi_dung_dong);
    }
    fclose(file);
    file = fopen(ten_file, "r");

    if (file == NULL) {
        printf("Khong mo duoc file\n");
        return 1;
    }

    printf("\nNoi dung file %s sau khi nhap:\n", ten_file);

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);

    return 0;
}

