#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int to_abs(int v){
	return (v>=0) ? v : v*-1;
}
void eu_mod(int x, int y, int *q, int *p){
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
int de_hard(int a, int b, int c, int *x, int *y){
	int q, p;
	eu_mod(a, b, &q, &p);
	if(q==0){
		if(c%b == 0){
			*y = (c/b)%p;
			*x = (c/b - *y)/p;
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(de_hard(b, q, c, x, y)){
			int x1 = *x;
			*x = *y;
			*y = x1 - *x * p;
			assert(a*(*x) + b*(*y) == c);
			return 1;
		}
		return 0;
	}
}

int de(int a, int b, int c, int *x, int *y){
	if(c == 0){
		*x = 0;
		*y = 0;
		return 1;
	}
	if(a == 0){
		if(b == 0){
			return 0;
		}
		if(c%b == 0){
			*x = 0;
			*y = c/b;
			return 1;
		}
		return 0;
	}
	if(b == 0){
		if(c%a == 0){
			*x = c/a;
			*y = 0;
			return 1;
		}
		return 0;
	}
	return de_hard(a, b, c, x, y);
}

void read_input(int *pa, int *pb, int *pc){
	int nitems = scanf("%d%d%d", pa, pb, pc);
	if(nitems != 3){
		printf("Ошибка: Неправильный ввод.");
		abort();
	}
	assert(nitems == 3);
}

void test_eu_mod(){
	int q, p;
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

void test_de(){
	int x, y;
	assert(de(1, 1, 1, &x, &y) == 1);
	assert(1*x + 1*y == 1 && "1");
	assert(de(3, 3, 2, &x, &y) == 0 && "2");
	assert(de(1, -1, 1, &x, &y) == 1);
	assert(1*x + (-1)*y == 1 && "3");

	assert(de(15, -6, 8, &x, &y) == 0 && "4");
	//assert(15*x + (-6)*y == 8 && "4");
	assert(de(-15, -6, 8, &x, &y) == 0 && "5");
	//assert((-15)*x + (-6)*y == 8 && "5");
	assert(de(-15, 6, 8, &x, &y) == 0 && "6");
	//assert((-15)*x + 6*y == 8 && "6");
	assert(de(-15, -6, -8, &x, &y) == 0 && "7");
	//assert((-15)*x + (-6)*y == -8 && "7");
	assert(de(15, -6, -8, &x, &y) == 0 && "8");
	//assert(15*x + (-6)*y == -8 && "8");
	assert(de(-15, 6, -8, &x, &y) == 0 && "9");
	//assert((-15)*x + 6*y == -8 && "9");
	assert(de(1, 0, 17, &x, &y) == 1);
	assert(1*x + 0*y == 17 && "10");
	assert(de(-1, 0, 17, &x, &y) == 1);
	assert((-1)*x + 0*y == 17 && "11");
	assert(de(1, 0, -17, &x, &y) == 1);
	assert(1*x + 0*y == -17 && "12");
	assert(de(-1, 0, -17, &x, &y) == 1);
	assert((-1)*x + 0*y == -17 && "13");
	assert(de(0, 1, 17, &x, &y) == 1);
	assert(0*x + 1*y == 17 && "14");
	assert(de(0, -1, 17, &x, &y) == 1);
	assert(0*x + (-1)*y == 17 && "15");
	assert(de(0, 1, -17, &x, &y) == 1);
	assert(0*x + 1*y == -17 && "16");
	assert(de(0, -1, -17, &x, &y) == 1);
	assert(0*x + (-1)*y == -17 && "17");
	assert(de(1, 1, 5, &x, &y) == 1);
	assert(1*x + 1*y == 5 && "18");
	assert(de(1, -1, 5, &x, &y) == 1);
	assert(1*x + (-1)*y == 5 && "19");
	assert(de(-1, 1, 5, &x, &y) == 1);
	assert((-1)*x + 1*y == 5 && "20");
	assert(de(-1, -1, 5, &x, &y) == 1);
	assert((-1)*x + (-1)*y == 5 && "21");
	assert(de(-1, -1, -5, &x, &y) == 1);
	assert((-1)*x + (-1)*y == -5 && "22");
	assert(de(14, 15, 3, &x, &y) == 1);
	assert(14*x + 15*y == 3 && "23");
	assert(de(-14, 15, 3, &x, &y) == 1);
	assert((-14)*x + 15*y == 3 && "24");
	assert(de(14, -15, 3, &x, &y) == 1);
	assert(14*x + (-15)*y == 3 && "25");
	assert(de(-14, -15, 3, &x, &y) == 1);
	assert((-14)*x + (-15)*y == 3 && "26");
	assert(de(-14, -15, -3, &x, &y) == 1);
	assert((-14)*x + (-15)*y == -3 && "27");
	assert(de(14, -15, -3, &x, &y) == 1);
	assert(14*x + (-15)*y == -3 && "28");
	assert(de(-14, 15, -3, &x, &y) == 1);
	assert((-14)*x + 15*y == -3 && "29");
	assert(de(-14, 15, -3, &x, &y) == 1);
	assert((-14)*x + 15*y == -3 && "30");
	
	assert(de(16, 16, 4, &x, &y) == 0 && "31");
	assert(de(15, 15, 12, &x, &y) == 0 && "32");
	assert(de(6, 6, -5, &x, &y) == 0 && "33");
	assert(de(-3, 6, 4, &x, &y) == 0 && "34");
	assert(de(3, 6, 4, &x, &y) == 0 && "35");
	assert(de(6, 3, 4, &x, &y) == 0 && "36");
	assert(de(-6, 3, 4, &x, &y) == 0 && "37");
	assert(de(6, -3, 4, &x, &y) == 0 && "38");
	assert(de(3, -6, 4, &x, &y) == 0 && "39");
	assert(de(-3, -6, 4, &x, &y) == 0 && "40");
	assert(de(-6, -3, 4, &x, &y) == 0 && "41");
	assert(de(-3, 6, -4, &x, &y) == 0 && "42");
	assert(de(3, 6, -4, &x, &y) == 0 && "43");
	assert(de(6, 3, -4, &x, &y) == 0 && "44");
	assert(de(-6, 3, -4, &x, &y) == 0 && "45");
	assert(de(6, -3, -4, &x, &y) == 0 && "46");
	assert(de(3, -6, -4, &x, &y) == 0 && "47");
	assert(de(-3, -6, -4, &x, &y) == 0 && "48");
	assert(de(-6, -3, -4, &x, &y) == 0 && "49");

	assert(de(15, -6, 0, &x, &y) == 1);
	assert(15*x + (-6)*y == 0 && "50");
	assert(de(-4, 8, 0, &x, &y) == 1);
	assert((-4)*x + 8*y == 0 && "51");
	assert(de(-37, 15, 0, &x, &y) == 1);
	assert((-37)*x + 15*y == 0 && "52");
	assert(de(68, -93, 0, &x, &y) == 1);
	assert(68*x + (-93)*y == 0 && "53");
	assert(de(42, 6, 0, &x, &y) == 1);
	assert(42*x + 6*y == 0 && "54");
	assert(de(4, 583, 0, &x, &y) == 1);
	assert(4*x + 583*y == 0 && "55");
	assert(de(-43, -52, 0, &x, &y) == 1);
	assert((-43)*x + (-52)*y == 0 && "56");
	assert(de(-13, -6, 0, &x, &y) == 1);
	assert((-13)*x + (-6)*y == 0 && "57");

	assert(de(0, 0, 0, &x, &y) == 1);
	assert(0*x + 0*y == 0 && "58");

	assert(de(0, -6, 0, &x, &y) == 1);
	assert(0*x + (-6)*y == 0 && "59");
	assert(de(0, 7, 0, &x, &y) == 1);
	assert(0*x + 7*y == 0 && "60");

	assert(de(32, 0, 0, &x, &y) == 1);
	assert(32*x + 0*y == 0 && "61");
	assert(de(-4, 0, 0, &x, &y) == 1);
	assert((-4)*x + 0*y == 0 && "62");

	assert(de(0, -6, 0, &x, &y) == 1);
	assert(0*x + (-6)*y == 0 && "63");
	assert(de(0, 15, 0, &x, &y) == 1);
	assert(0*x + (15)*y == 0 && "64");

	assert(de(0, 0, -5, &x, &y) == 0 && "65");
	assert(de(0, 0, 6, &x, &y) == 0 && "66");
	assert(de(0, 0, -164, &x, &y) == 0 && "67");
	assert(de(0, 0, 909, &x, &y) == 0 && "68");

	assert(de(32, 0, 64, &x, &y) == 1);
	assert(32*x + 0*y == 64 && "69");
	assert(de(3, 0, -9, &x, &y) == 1);
	assert(3*x + 0*y == -9 && "70");
	assert(de(-2, 0, 14, &x, &y) == 1);
	assert((-2)*x + 0*y == 14 && "71");
	assert(de(-6, 0, -36, &x, &y) == 1);
	assert((-6)*x + 0*y == -36 && "72");

	assert(de(3, 0, 7, &x, &y) == 0 && "73");
	assert(de(-4, 0, 9, &x, &y) == 0 && "74");
	assert(de(12, 0, -2, &x, &y) == 0 && "75");
	assert(de(-37, 0, -90, &x, &y) == 0 && "76");

	assert(de(0, 4, 64, &x, &y) == 1);
	assert(0*x + 4*y == 64 && "77");
	assert(de(0, 3, -9, &x, &y) == 1);
	assert(0*x + 3*y == -9 && "78");
	assert(de(0, -14, 14, &x, &y) == 1);
	assert(0*x + (-14)*y == 14 && "79");
	assert(de(0, -6, -36, &x, &y) == 1);
	assert(0*x + (-6)*y == -36 && "80");

	assert(de(0, 24, 8, &x, &y) == 0 && "81");
	assert(de(0, -5, 23, &x, &y) == 0 && "82");
	assert(de(0, 64, -54, &x, &y) == 0 && "83");
	assert(de(0, -111, -745, &x, &y) == 0 && "84");
}

int main() {
	//test_eu_mod();
	//test_de();

	int a, b, c, x, y;
  	read_input(&a, &b, &c);
	if(de(a, b, c, &x, &y) == 1){
		printf("%d %d\n", x, y);
	}
	else{
		printf("NONE\n");
	}
	
  	return 0;
}

