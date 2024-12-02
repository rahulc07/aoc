// why partb?
#include <stdio.h>
#include <stdlib.h>

int count_occurences(int * array, int val) {
	int co = 0;
	for (int i = 0; i<1000; i++) {
		if (array[i] == val) {
		  co++;
		}
	}
	return co;
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

	int simscore = 0;
	for (int i = 0; i<1000; i++) {
		simscore+=list1[i] * count_occurences(list2, list1[i]);
	}
	printf("%d\n", simscore);
	return 0;
	

}

// inital time: 2:31 minutes
// debug time: 35 seconds
