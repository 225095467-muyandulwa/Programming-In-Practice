



#include <stdio.h>

int main() {
	int numbers[5] = {10, 25, 30, 45, 60};
	int search = 60;
	int found = 0;

	for (int i = 0; i < 5; i++) {
		if (numbers[i] == search) {
			found = 1;
			printf("Value found at position %d\n", i);
			break;
		}
	}

	if (!found) {
		printf("Value not found.\n");
	}

	return 0; 
}