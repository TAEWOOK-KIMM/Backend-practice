#include <stdio.h>
#define MAX_SIZE 1000000

int N;
int Heights[MAX_SIZE+10];
int MaxArea;


int main() {
	int i, area;
	int stack[MAX_SIZE];
	int top = -1;
	int width, height;
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++) {
		scanf("%d", &Heights[i]);
	}
	MaxArea = 0;
	int j = 1;
	while(j<=N+1) {
		if(top == -1 || (j<=N && Heights[stack[top]] <= Heights[j])) {
			top++;
			stack[top] = j;
			j++;
		}
		else {
			height = Heights[stack[top]];
			top--;
			if(top == -1) {
				width = j-1;
			}
			else {
				width = j-stack[top]-1;
			}
			area = width * height;
			if(area > MaxArea) {
				MaxArea = area;
			}
		}
	}
	

	printf("%d", MaxArea);
	return 0;
}