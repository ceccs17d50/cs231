#include <stdio.h>

int main() {
	int i, a[100], j, size, small, pos, temp;
	
	printf("Enter size of the array : ");
	scanf("%d", &size);
	
	printf("Enter array\n");
	for (i=0; i<size; i++) {
		scanf("%d", &a[i]);
	}

	for (i=0; i<size; i++) {
		pos = i;
		for (j=i; j<size; j++) {
			if (a[j] < a[pos]) {
				pos = j;
			}
		}
		if (i != pos) {
			temp = a[pos];
			a[pos] = a[i];
			a[i] = temp;
		}
	}
	
	printf("Sorted array\n");
	for (i=0; i<size; i++) {
		printf("%d\n", a[i]);
	}
}
