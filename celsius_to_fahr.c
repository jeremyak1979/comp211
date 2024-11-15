#include <stdio.h>

int main(void){
	
	double cel, res;

	printf("Enter temp in celsius: ");
	scanf("%lf", &cel);

	res = (cel * 9.0/5.0) + 32.0;
	printf("%.2lf Fahrenheit\n", res);


	return 0;
}
