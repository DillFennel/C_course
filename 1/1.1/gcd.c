#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int iabs(int x){
	return (x<0) ? -x :x;
}
int eu_mod(int x, int y){
	assert(y != 0);
	int r = x%y;
	if (r<0){
		r += iabs(y);
	}
	return r;
}
int gcd(int x, int y){
	int q = eu_mod(x, y);
	return (q==0) ? y : gcd(y, q);
}
void read_input(int *px, int *py){
	printf("Введите x и y: ");
	int nitems = scanf("%d%d", px, py);
	if(nitems != 2 || py==0){
		printf("Ошибка: неправильный ввод\n");
		abort();
	}
}
int main(){
	int x, y;
	read_input(&x, &y);
	printf("Полученный результ: %d\n", gcd(x, y));
	return 0;
}
