#include<stdio.h>

int main(){
	typedef struct chow{
		char a[10];
		char b[10];
	}CHOWDARY;
	CHOWDARY p1 = {"NTR", "PRANAV"};
	printf("chow ante %s, %s ante chow",p1.a, p1.b);
}