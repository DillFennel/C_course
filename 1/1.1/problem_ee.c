#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long to_abs(long long v){
	return (v>=0) ? v : v*-1;
}
void eu_mod(long long x, long long y, long long *q, long long *p){
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
long long ee(long long x, long long y, long long *a, long long *b, long long *d){
	long long q, p;
	eu_mod(x, y, &q, &p);
	if(q==0){
		*d = to_abs(y);
		*a = 0;
		if(y<0){
			*b = -1;
		}
		else{
			*b = 1;
		}
	}
	else{
		ee(y, q, a, b, d);
		long long a1 = *a;
		long long b1 = *b;
		*a = b1;
		*b = a1 - b1*p;
	}
	assert(*d > 0);
	assert(*a != 0 || *b != 0);
}

void read_input(long long *px, long long *py){
	int nitems = scanf("%lld%lld", px, py);
	if(nitems != 2 || *px == 0|| *py ==  0){
		printf("Ошибка: Неправильный ввод.");
		abort();
	}
	assert(nitems == 2);
	assert(*px != 0);
	assert(*py != 0);
}

void test_eu_mod(){
	long long q, p;
	eu_mod(5, 2, &q, &p);
	assert(q == 1 && p == 2 && "1");
	eu_mod(-3, 2, &q, &p);
	assert(q == 1 && p == -2 && "2");
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
	eu_mod(698917, -102089, &q, &p);
	assert(q == 86383 && p == -6 && "15");
	eu_mod(698917, 102089, &q, &p);
	assert(q == 86383 && p == 6 && "16");
	eu_mod(-698917, 102089, &q, &p);
	assert(q == 15706 && p == -7 && "17");
	eu_mod(-698917, -102089, &q, &p);
	assert(q == 15706 && p == 7 && "18");
	eu_mod(-1, -1, &q, &p);
	assert(q == 0 && p == 1 && "19");
	eu_mod(-1, 1, &q, &p);
	assert(q == 0 && p == -1 && "21");
	eu_mod(1, -1, &q, &p);
	assert(q == 0 && p == -1 && "22");
	eu_mod(14, -8, &q, &p);
	assert(q == 6 && p == -1 && "23");
	eu_mod(-14, 8, &q, &p);
	assert(q == 2 && p == -2 && "24");
	eu_mod(-14, -8, &q, &p);
	assert(q == 2 && p == 2 && "25");
	eu_mod(-12, 1, &q, &p);
	assert(q == 0 && p == -12 && "26");
	eu_mod(12, -1, &q, &p);
	assert(q == 0 && p == -12 && "27");
	eu_mod(-12, -1, &q, &p);
	assert(q == 0 && p == 12 && "28");
	eu_mod(-3, 3, &q, &p);
	assert(q == 0 && p == -1 && "29");
	eu_mod(-3, -3, &q, &p);
	assert(q == 0 && p == 1 && "30");
	eu_mod(-18, 446, &q, &p);
	assert(q == 428 && p == -1 && "31");
	eu_mod(18, -446, &q, &p);
	assert(q == 18 && p == 0 && "32");
	eu_mod(-18, -446, &q, &p);
	assert(q == 428 && p == 1 && "33");
}
void test_ee(){
	long long a, b, d;
	ee(2, 1, &a, &b, &d);
	assert(a == 0 && b == 1 && d == 1 && "1");
	ee(3, 2, &a, &b, &d);
	assert(a == 1 && b == -1 && d == 1 && "2");
	ee(2, 4, &a, &b, &d);
	assert(a == 1 && b == 0 && d == 2 && "3");
	ee(180, 150, &a, &b, &d);
	assert(a == 1 && b == -1 && d == 30 && "4");
	ee(1, 2, &a, &b, &d);
	assert(a == 1 && b == 0 && d == 1 && "5");
	ee(2, 3, &a, &b, &d);
	assert(a == -1 && b == 1 && d == 1 && "6");
	ee(4, 2, &a, &b, &d);
	assert(a == 0 && b == 1 && d == 2 && "7");
	ee(150, 180, &a, &b, &d);
	assert(a == -1 && b == 1 && d == 30 && "8");
	ee(36, 1, &a, &b, &d);
	assert(a == 0 && b == 1 && d == 1 && "9");
	ee(1, 36, &a, &b, &d);
	assert(a == 1 && b == 0 && d == 1 && "10");
	ee(36, 48, &a, &b, &d);
	assert(a == -1 && b == 1 && d == 12 && "11");
	ee(48, 36, &a, &b, &d);
	assert(a == 1 && b == -1 && d == 12 && "12");
	ee(37, 37, &a, &b, &d);
	assert((a == 0 && b == 1 || a == 1 && b == 0) && d == 37 && "13");
	ee(37, 37, &a, &b, &d);
	assert((a == 0 && b == 1 || a == 1 && b == 0) && d == 37 && "14");
	ee(127, 35, &a, &b, &d);
	assert(a == 8 && b == -29 && d == 1 && "15");
	ee(35, 127, &a, &b, &d);
	assert(a == -29 && b == 8 && d == 1 && "16");
	ee(-14, 8, &a, &b, &d);
	assert(a*(-14)+b*8==2 && d == 2 && "17");
	ee(14, -8, &a, &b, &d);
	assert(a*14+b*(-8)==2 && d == 2 && "18");
	ee(-14, -8, &a, &b, &d);
	assert(a*(-14)+b*(-8)==2 && d == 2 && "19");
	ee(14, 8, &a, &b, &d);
	assert(a*14+b*8==2 && d == 2 && "20");
	ee(-37, -37, &a, &b, &d);
	assert(a*(-37)+b*(-37)==37 && d == 37 && "21");
	ee(37, -37, &a, &b, &d);
	assert(a*37+b*(-37)==37 && d == 37 && "22");
	ee(-37, 37, &a, &b, &d);
	assert(a*(-37)+b*37==37 && d == 37 && "23");
	ee(-100, -25, &a, &b, &d);
	assert(a*(-100)+b*(-25)==25 && d == 25 && "24");
	ee(100, -25, &a, &b, &d);
	assert(a*100+b*(-25)==25 && d == 25 && "25");
	ee(-100, 25, &a, &b, &d);
	assert(a*(-100)+b*25==25 && d == 25 && "26");
	ee(-25, -100, &a, &b, &d);
	assert(a*(-25)+b*(-100)==25 && d == 25 && "27");
	ee(25, -100, &a, &b, &d);
	assert(a*25+b*(-100)==25 && d == 25 && "28");
	ee(-25, 100, &a, &b, &d);
	assert(a*(-25)+b*100==25 && d == 25 && "29");
	ee(-8, -14, &a, &b, &d);
	assert(a*(-8)+b*(-14)==2 && d == 2 && "30");
	ee(8, -14, &a, &b, &d);
	assert(a*8+b*(-14)==2 && d == 2 && "31");
	ee(-8, 14, &a, &b, &d);
	assert(a*(-8)+b*14==2 && d == 2 && "32");
}

int main() {
	test_eu_mod();
	test_ee();

	long long x, y, a, b, d;
  	read_input(&x, &y);
  	ee(x, y, &a, &b, &d);
  	printf("%lld %lld %lld\n", a, b, d);
	
  	return 0;
}

