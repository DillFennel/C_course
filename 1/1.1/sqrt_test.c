#include <stdio.h>
#include <math.h>

int main(){
	float x;
	printf("Введите число : ");
	scanf("%f", &x);
	printf("Корень из %f = %f\n", x, sqrt(x));
	return 0;
}
