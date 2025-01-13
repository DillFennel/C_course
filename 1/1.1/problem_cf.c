#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void to_abs(int *pa){
	if(*pa < 0){
		*pa *= -1;
	}
	assert(*pa >= 0);
}
void print_continued_fraction(int a, int b){ //Дробь вида a/b
	if(a>0 && b<0 || a<0 && b>0){
		printf("-");
	}
	to_abs(&a);
	to_abs(&b);
	int p, q;
	do{
		p = a/b;
		q = a%b;
		printf("%d ", p);
		a = b;
		b = q;
	}while(q > 1);
	if(q == 1){
		printf("%d", a);
	}
	printf("\n");
}

void read_input(int *pa, int *pb){
	int nitems = scanf("%d%d", pa, pb);
	if (nitems != 2 ||  *pb == 0){
		printf("Ошибка: Неправильный ввод");
		abort();
	}
	assert(nitems == 2);
	assert(*pb != 0);
}
int main(){
	int a, b;
	read_input(&a, &b);
	assert(b != 0);
	print_continued_fraction(a, b);
}
