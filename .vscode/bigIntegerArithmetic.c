#include <stdio.h>
#define MAX_LEN 100

int strlen(char *str);
void reverse(char *str);
void add(char *a, char *b, char *c);
void sub(char *a, char *b, char *c);

int main() {
	char a[MAX_LEN+1], b[MAX_LEN+1], c[MAX_LEN+1] = "0";
	
	scanf("%s", a);
	scanf("%s", b);
	
	add(a, b, c);
	printf("%s + %s = %s\n", a, b, c);

	sub(a, b, c);
	printf("%s - %s = %s\n", a, b, c);
	return 0;
}

int strlen(char *str) {
	int i;
	for (i = 0; *(str+i) != 0; i ++);
	return i;
}

void reverse(char *str) {
	int i, len = strlen(str);
	char tmp;
	for (i = 0; i < len/2; i ++) {
		tmp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = tmp;
	}
}
//a가 다섯자리 숫자, b가 세자리 숫자면 ,
void add(char *a, char *b, char *c) {
    int aLen = strlen(a)-1;
    int bLen = strlen(b)-1;

    while(aLen >0 && bLen>0) {
        for(int i=0; i<aLen; i++){
            aLen *= aLen;
        }
        for(int i=0; i<bLen; i++){
            bLen *= bLen;
        }
    }
}

void sub(char *a, char *b, char *c) {
    for(int i=0; i<MAX_LEN; i++){
        c[i] = a[i] - b[i];
    }
}