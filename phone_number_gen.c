#include <stdio.h>
#include <stdlib.h>

int main(void){

	FILE *file = fopen("phone_numbers.txt", "w");
	if(file == NULL){
		printf("file failed to open\n");
		return 1;
	}

	for(int j=0; j<100; j++){
		for(int i=0; i<10; i++){
			int g = rand() % 10;
			fprintf(file, "%d", g);	
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
	fclose(file);

	return 0;
}
