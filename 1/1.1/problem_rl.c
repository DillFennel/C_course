#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void to_abs(int *pv);
unsigned long long gcd(int x, int y) {
  to_abs(&x);
  to_abs(&y);
  int q = y;
  if (y > x)
    return gcd(y, x);
  assert(y > 0);
  assert(x > 0);
  do{
	y = q;
	q = x % y;
	assert(y>q);
	x = y;
  }while(q!=0);
  return y;
}
void to_abs(int * pv){
	if(*pv <0){
		*pv *= -1;
	}
	assert(*pv > 0);
}
void read_input(int *px, int *py){
	int nitems = scanf("%d%d", px, py);
	if(nitems != 2 || *px == 0|| *py ==  0){
		printf("Ошибка: Неправильный ввод.");
		abort();
	}
	assert(nitems == 2);
	assert(*px != 0);
	assert(*py != 0);
}

void test_gcd(){
	assert(gcd(12, 1) == 1);
	assert(gcd(1, 12) == 1);
	assert(gcd(14, 8) == 2);
	assert(gcd(8, 14) == 2);
	assert(gcd(12, 12) == 12);
	assert(gcd(3, 3) == 3);
	assert(gcd(1, 1) == 1);
	assert(gcd(18, 446) == 2);
	assert(gcd(446, 18) == 2);
	assert(gcd(698917, -102089) == 7853);
	assert(gcd(-698917, 102089) == 7853);
	assert(gcd(-698917, -102089) == 7853);
	assert(gcd(-1, -1) == 1);
	assert(gcd(-1, 1) ==  1);
	assert(gcd(1, -1) ==  1);
	assert(gcd(14, -8) == 2);
	assert(gcd(-14, 8) == 2);
	assert(gcd(-14, -8) == 2);
	assert(gcd(-12, 1) == 1);
	assert(gcd(12, -1) == 1);
	assert(gcd(-12, -1) == 1);
	assert(gcd(-3, 3) == 3);
	assert(gcd(3, -3) == 3);
	assert(gcd(-3, -3) == 3);
	assert(gcd(-18, 446) == 2);
	assert(gcd(18, -446) == 2);
	assert(gcd(-18, -446) == 2);
}

int main() {
	test_gcd();
  int x = 0, y = 0, g;
  read_input(&x, &y);
  g = gcd(x, y);
  printf("%d\n", g);
  return 0;
}

