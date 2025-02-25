#include <stdio.h>

void print_array(int arr[], int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if(i != size - 1) printf(", ");
	}
	printf("]");
}

int main()
{
	int n = 4;
	int arr[4] = {3, 1, 2, 4};

	print_array(arr, 4);
	printf("\n");
	
	int total_operations = 0;
	for(int i = 0; i <= n - 1; i++) {
		for(int j = i + 1; j <= n - 1; j++) {
			total_operations++;
			// swapping
			if(arr[i] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	print_array(arr, 4);
	printf("\n");
	printf("finished after %d operations\n", total_operations);

	return 0;
}
