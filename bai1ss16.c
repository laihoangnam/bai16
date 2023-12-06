#include<stdio.h>
//C:\\Users\\Admin\\Desktop\\BT01.txt
int main(){
	FILE *filePointer;
	char buffer[] = "Hello";
	printf("nhap mot chuoi bat ky:\n");
	gets(buffer);
	filePointer=fopen("C:\\Users\\Admin\\Desktop\\BT01.txt","w+");
	fwrite(buffer, sizeof(char), sizeof(buffer), filePointer);
	printf("noi dung van ban la: %s",buffer);
	fclose(filePointer);
	return 0;
}
