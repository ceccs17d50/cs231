/* stephen thomas
s3 d
50*/
#include<stdio.h>

int main () 
{
	int i=0, found=0, size, ele, a[100];
	
	printf("Enter size of the array : ");
	scanf("%d", &size);

	printf("Enter array\n");
	for (i=0; i<size; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("Enter the element to search : ");
	scanf("%d", &ele);
	
	for (i=0; i<size; i++) {
		if (a[i] == ele) {
			found = 1;
			break;
		}
	}
	
	if (found ==1) {
		printf("Found at %d\n", i+1);
	} else {
		printf("Not found\n");
	}
}
