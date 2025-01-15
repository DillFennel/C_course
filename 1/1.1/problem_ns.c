#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int to_abs(int v){
	return (v>=0) ? v : v*-1;
}
void eu_mod(unsigned int x, int y, unsigned int *q, unsigned int *p){
    assert(y != 0);
    *q = x%y;
	*p = x/y;
    if (*q<0){
		*q += to_abs(y);
		if(y>0){
			*p -= 1;
		}
		else{
			*p += 1;
		}
    }
    assert(*q >= 0);
	assert(x == *p * y + *q);
}
void ns(unsigned int x, int y) {
  assert(y > 1);
  assert(y < 11);
  assert(x > 0);
  unsigned int q, p;
  eu_mod(x, y, &q, &p);
  if(p > 0){
	ns(p, y);
  }
  printf("%d", x%y);
}

void read_input(unsigned *px, int *py){
	int nitems = scanf("%u%d", px, py);
	if(nitems != 2 || *px <= 0 || *py <=  1 || *py > 10){
		printf("Ошибка: Неправильный ввод.");
		abort();
	}
	assert(nitems == 2);
	assert(*px > 0);
	assert(*py > 1);
	assert(*py < 11);
}

void test_eu_mod(){
	int q, p;
	eu_mod(5, 2, &q, &p);
	assert(q == 1 && p == 2 && "1");
	eu_mod(12, 1, &q, &p);
	assert(q == 0 && p == 12 && "3");
	eu_mod(1, 12, &q, &p);
	assert(q == 1 && p == 0 && "4");
	eu_mod(14, 8, &q, &p);
	assert(q == 6 && p == 1 && "5");
	eu_mod(8, 14, &q, &p);
	assert(q == 8 && p == 0 && "6");
	eu_mod(12, 12, &q, &p);
	assert(q == 0 && p == 1 && "7");
	eu_mod(3, 3, &q, &p);
	assert(q == 0 && p == 1 && "8");
	eu_mod(1, 1, &q, &p);
	assert(q == 0 && p == 1 && "9");
	eu_mod(18, 446, &q, &p);
	assert(q == 18 && p == 0 && "10");
	eu_mod(446, 18, &q, &p);
	assert(q == 14 && p == 24 && "11");
	eu_mod(446, 18, &q, &p);
	assert(q == 14 && p == 24 && "12");
	eu_mod(446, 18, &q, &p);
	assert(q == 14 && p == 24 && "13");
	eu_mod(446, 18, &q, &p);
	assert(q == 14 && p == 24 && "14");
	eu_mod(698917, 102089, &q, &p);
	assert(q == 86383 && p == 6 && "16");
}
/*
void test_ns(){
	assert(ns(15, 2) == 1111 && "1");
	assert(ns(1, 2) == 1 && "2");
	assert(ns(385, 2) == 110000001 && "3");
	assert(ns(128, 2) == 10000000 && "4");
	assert(ns(2, 2) == 10 && "5");
	assert(ns(13, 3) == 111 && "6");
	assert(ns(43, 3) == 1121 && "7");
	assert(ns(27, 3) == 1000 && "8");
	assert(ns(3, 3) == 10 && "9");
	assert(ns(4, 4) == 10 && "10");
	assert(ns(12, 2) == 1100 && "11");
	assert(ns(12, 6) == 20 && "12");
	assert(ns(12, 10) == 12 && "13");
	assert(ns(32, 4) == 200 && "14");
	assert(ns(1279, 4) == 103333 && "15");
	assert(ns(1279, 5) == 20104 && "16");
	assert(ns(28, 5) == 103 && "17");
	assert(ns(21, 6) == 33 && "18");
	assert(ns(329, 6) == 1305 && "19");
	assert(ns(329, 7) == 650 && "20");
	assert(ns(57, 7) == 111 && "21");
	assert(ns(57, 8) == 71 && "22");
	assert(ns(16, 8) == 20 && "23");
	assert(ns(4739, 9) == 6445 && "24");
	assert(ns(4739, 10) == 4739 && "25");
	assert(ns(9, 10) == 9 && "26");
	assert(ns(2000000000, 2) == 1110111001101011001010000000000 && "26");
}
*/

int main() {
	test_eu_mod();
	//test_ns();
	unsigned int x;
	int y;
	read_input(&x, &y);
	ns(x, y);
	printf("\n");
	/*
  	int x, y;
  	read_input(&x, &y);
  	printf("%u\n", ns(x, y));
  	return 0;
	*/
}

