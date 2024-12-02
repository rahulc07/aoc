#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_min_index(int * array, int arraySize) {
	int current_min_index = 0;
	for (int i=1; i<arraySize; i++) {
		if (array[i]<array[current_min_index]) {
			current_min_index = i;
		}
	}
	return current_min_index;

}
void swap(int * array, int index1, int index2) {
	int temp = array[index1];
	array[index1]=array[index2];
	array[index2] = temp;
}

void sort_array(int * array, int arraySize) {
	for (int i=0; i<arraySize; i++) {
		// already have a seperate function and I'm on a timer here
		int *sub = &array[i];
		swap(array, find_min_index(sub, arraySize-i)+i, i);
	}
}

int main() {
	int list1[1000];
	int list2[1000];
	int tempnum1;
	int tempnum2;
	int total_distance = 0;
	FILE * file = fopen("input", "r");
	int current_index = 0;
	while(current_index<1000) {
		fscanf(file, "%d %d", &tempnum1, &tempnum2);
		list1[current_index] = tempnum1;	
		list2[current_index] = tempnum2;
		current_index++;
	}
	fclose(file);
	int array_size = 1000;
	sort_array(list1, array_size);
	sort_array(list2, array_size);
	for (int i=0; i<array_size; i++) {
		total_distance+=abs(list1[i]-list2[i]);
	}
	printf("%d", total_distance);
	return 0;

}
// inital code completition: 3:42 minutes
// debug 6:12 :skull - overlooked the whole subarray index won't be the value in the original thing
