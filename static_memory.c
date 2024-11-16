#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA_LEN 26

char *string_malloc(size_t size);
char *string_calloc(size_t size);
char *string_realloc(char *str, size_t size);
void fill_lowercase(char *str, size_t len);
void fill_uppercase(char *str, size_t len);

int main(void){
	
	char *str = string_malloc(ALPHA_LEN + 1);
	//char *str1 = string_calloc(ALPHA_LEN + 1); 
	fill_lowercase(str, ALPHA_LEN + 1);
	printf("%s\n", str);
	str = string_realloc(str, (2 * ALPHA_LEN) + 1);
	fill_uppercase(&str[ALPHA_LEN], ALPHA_LEN + 1);
	printf("%s\n", str);
	//fill_uppercase(str1, ALPHA_LEN + 1);
	//printf("%s\n", str1);

	free(str);
	//free(str1);
	return 0;
}


void fill_lowercase(char *str, size_t len){
	
	if(len > ALPHA_LEN + 1) len = ALPHA_LEN + 1;
	for(size_t i=0; i<len-1; ++i){
		str[i] = 'a' + i;
	}
	str[len-1] = '\0';
}

void fill_uppercase(char *str, size_t len){
	
	if(len > ALPHA_LEN + 1) len = ALPHA_LEN + 1;
	for(size_t i=0; i<len-1; ++i){
		str[i] = 'A' + i;
	}
	str[len-1] = '\0';
}

char *string_malloc(size_t size){
	char *ptr = malloc(sizeof(char) * size);
	if(ptr == NULL){
		fprintf(stderr, "Out of Memory");
		exit(EXIT_FAILURE);
	}
	memset(ptr, '\0', size);
	return ptr;
}

char *string_calloc(size_t size){
	char *ptr = calloc(size, sizeof(char));
	if(ptr == NULL){
		fprintf(stderr, "Out of Memory");
		exit(EXIT_FAILURE);
	}
	return ptr;
}

char *string_realloc(char *str, size_t size){
	str = realloc(str, size);
	if(str == NULL){
		fprintf(stderr, "Out of Memory");
		exit(EXIT_FAILURE);
	}
	return str;
}
