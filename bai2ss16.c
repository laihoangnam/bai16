#include <stdio.h>
//C:\\Users\\Admin\\Desktop\\BT01.txt
int main() {
    FILE *file;
    file = fopen("C:\\Users\\Admin\\Desktop\\BT01.txt", "r");
    if (file == NULL) {
        printf("Khong mo dc file.\n");
        return 1;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);

    return 0;
}

