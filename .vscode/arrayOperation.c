#include <stdio.h>   // This enables to use I/O functions
#include <stdbool.h> // This enables to use bool type
#include <limits.h>
#define MAX_SIZE 10  // Maximum size of our array structure

typedef struct _IntArray { // Array structure for integer values
	int items[MAX_SIZE];
	int size;
} IntArray;

// IntArray operations:
void printItems(IntArray *arr);
bool isFull(IntArray *arr);
bool isEmpty(IntArray *arr);
void insert(IntArray *arr, int value, int index);
void delete(IntArray *arr, int index);
int getMax(IntArray *arr);
int getMin(IntArray *arr);
int getSum(IntArray *arr);
int find(IntArray *arr, int value);

int main() {
	IntArray arr = { { 2, 1, 3, 8, 6, 7, 5, 10 }, 8 };	
	
	printf("Initial state\n");
	printItems(&arr);
	
	printf("\nInsert value=9 at index=4\n");
	insert(&arr, 9, 4);
	printItems(&arr);

	printf("\nInsert value=4 at index=7\n");
	insert(&arr, 4, 7);
	printItems(&arr);

	printf("\nInsert value=0 at index=9\n");
	insert(&arr, 0, 9);
	printItems(&arr);
	
	printf("\nStatistics\n");
	printf("Min: %d\n", getMin(&arr));
	printf("Max: %d\n", getMax(&arr));
	printf("Sum: %d\n", getSum(&arr));
	
	printf("\nDelete the minimum value iteratively\n");
	int i = 0, min, index;
	while (!isEmpty(&arr)) {
		printf("[Iteration %d] ", i++);
		min = getMin(&arr);
		index = find(&arr, min);
		printf("Min: %d / ", min);
		delete(&arr, index);
		printItems(&arr);
	}
	return 0;
}

void printItems(IntArray *arr) {
	printf("Array: ");
	for (int i = 0; i < arr->size; i ++) printf("%d ", arr->items[i]);
	printf("(%d items)\n", arr->size);
}

int getSize(IntArray *arr) {
	return arr->size;
}

bool isFull(IntArray *arr) {
    if(arr->size == 10) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty(IntArray *arr) {
    if(arr->size == 0) {
        return true;
    }
    else {
        return false;
    }
}

void insert(IntArray *arr, int value, int index) {
	if (isFull(arr)) {
		printf("Error: you cannot insert new item into full array\n");
		return;
	}
	if (index < 0 || index > arr->size) {
		printf("Error: index is invalid\n");
		return;
    }
    for(int i=index; i<arr->size; i++) {
        arr->items[index] == value;
        arr->items[i+1] = arr->items[i];
    }
}

void delete(IntArray *arr, int index) {
	if (isEmpty(arr)) {
		printf("Error: you cannot delete an item from empty array\n");
		return;
	}
	if (index < 0 || index >= arr->size) {
		printf("Error: index is invalid\n");
		return;
	}
    for(int i=index; i<arr->size; i++) {
        arr->items[index] == NULL;
        arr->items[i] = arr->items[i+1];
    }
   
}

int getMax(IntArray *arr) {
	int max = INT_MIN; 
    for(int i=0; i<arr->size; i++) {
        if(arr->items[i] > max){
            max = arr->items[i];
        }
    }
	return max;
}

int getMin(IntArray *arr) {
	int min = INT_MAX; 
    for(int i=0; i<arr->size; i++) {
        if(arr->items[i] < min) {
            min = arr->items[i];
        }
    }
	return min;
}

int getSum(IntArray *arr) {
	int sum = 0;
    for(int i=0; i<arr->size; i++) {
        sum += arr->items[i];
    }
	return sum;
}

int find(IntArray *arr, int value) {
    for(int i=0; i<arr->size; i++) {
        if(arr->items[i] == value) {
            return i+1;
        }
    }
	return -1;
}