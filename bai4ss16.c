#include <stdio.h>
#include <stdlib.h>
//C:\\Users\\Admin\\Desktop\\BT03.txt
int main() {
    FILE *file;
    file = fopen("C:\\Users\\Admin\\Desktop\\BT03.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file.\n");
        exit(EXIT_FAILURE);
    }
    int so_dong = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            so_dong++;
        }
    }
    fseek(file, 0, SEEK_SET);
    printf("Noi dung file:\n");
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    printf("\nSo dong trong file: %d\n", so_dong);
    fclose(file);
    return 0;
}

