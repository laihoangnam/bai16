#include <stdio.h>
#include <stdlib.h>
void sao_chep_file(const char *file_nguon1, const char *file_nguon2, const char *file_dich) {
    FILE *nguon1, *nguon2, *dich;
    nguon1 = fopen(file_nguon1, "r");
    nguon2 = fopen(file_nguon2, "r");
    dich = fopen(file_dich, "w");

    if (nguon1 == NULL || nguon2 == NULL || dich == NULL) {
        printf("khong mo duoc file\n");
        exit(EXIT_FAILURE);
    }
    char ch;
    while ((ch = fgetc(nguon1)) != EOF) {
        fputc(ch, dich);
    }
    fputc('\n', dich);
    while ((ch = fgetc(nguon2)) != EOF) {
        fputc(ch, dich);
    }
    fclose(nguon1);
    fclose(nguon2);
    fclose(dich);
}
void in_file(const char *ten_file) {
    FILE *file;
    file = fopen(ten_file, "r");

    if (file == NULL) {
        printf("khong mo duoc file\n");
        return;
    }

    printf("noi dung %s:\n", ten_file);

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
int main() {
	const char *ten_file_nguon1 = "C:\\Users\\Admin\\Desktop\\BT01.txt";
    const char *ten_file_nguon2 = "C:\\Users\\Admin\\Desktop\\BT03.txt";
    const char *ten_file_dich = "C:\\Users\\Admin\\Desktop\\BT05.txt";
    sao_chep_file("C:\\Users\\Admin\\Desktop\\BT01.txt", "C:\\Users\\Admin\\Desktop\\BT03.txt", "C:\\Users\\Admin\\Desktop\\BT05.txt");
    printf("Da sao chep noi dung tu bt01.txt va bt03.txt sang bt5.txt.\n");
    printf("noi dung sao chep: \n");
    in_file(ten_file_dich);
    return 0;
}

