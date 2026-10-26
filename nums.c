#include <stdio.h>
#include <stdlib.h>

int main() {
	int length = 0;
	char fName[100] = "";
	FILE *fptr;
	printf("Length of numbers to calculate (limit 12): \n");
	scanf("%d", &length);
	if (length > 12) {
		printf("Limit is 12, this will result in a very large file, are you sure you want to continue? (y/N)");
		char answer = 'N';
		scanf(" %c", &answer);
		switch (answer) {
			case 'N':
			case 'n':
				exit(0);
			case 'Y':
			case 'y':
				break;
			default:
				exit(0);
		}
	}
	printf("Name of output file: \n");
	scanf("%s", fName);

	long long limit = 1;
	for (int i = 0; i < length; i++) {
		limit *= 10;
	}

	fptr = fopen(fName, "a");
	if (fptr == NULL) {
    	perror("Error opening file");
	}

	for (long long i = 0; i < limit; i++){ 
		fprintf(fptr, "%0*lld\n", length, i);
	}
	fclose(fptr);
}
