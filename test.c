#include <stdio.h>
#include "fx_s1615_double.h"
#include "fx_1615_longlong.h"

#ifdef MULTIPLE_TIME_TEST
static void fx_1615_double_mul_test(void) {
    fx_s1615 divisor = 62764;
    fx_s1615 a = 0;
    int i=0;
    for (i = 0; i < 100000000; ++i) {
        a = FX_S1615_MUL((i), (divisor));
    }
}

static void fx_1615_longlong_mul1_test(void) {
	fx_s1615 divisor = 62764;
	fx_s1615 a = 0;
	int i=0;
	for (i = 0; i < 100000000; ++i) {
		a = FX_1615_LONGLONG_MUL1((i), (divisor));
	}
}

static void fx_1615_longlong_mul2_test(void) {
	fx_s1615 divisor = 62764;
	fx_s1615 a = 0;
	int i=0;
	for (i = 0; i < 100000000; ++i) {
		a=FX_1615_LONGLONG_MUL2((i), (divisor));
	}
}

static void fx_1615_longlong_mul3_test(void) {
	fx_s1615 divisor = 62764;
	fx_s1615 a = 0;
	int i=0;
	for ( i = 0; i < 100000000; ++i) {
		a=FX_1615_LONGLONG_MUL3((i), (divisor));
	}
}
#endif

#ifdef DIVISION_TIME_TEST
static void fx_1615_double_test(void) {
    fx_s1615 divisor = 3194858;
    fx_s1615 a = 0;
    int i=0;
    for (i = 0; i < 100000000; ++i) {
        a=FX_S1615_DIV((i),(divisor));
    }
}

static void fx_1615_longlong_div01_test(void) {
	fx_s1615 divisor = 3194858;
	fx_s1615 a = 0;
	int i=0;
	for (i = 0; i < 100000000; ++i) {
		a=FX_1615_LONGLONG_DIV01((i),(divisor));
	}
}

static void fx_1615_longlong_div02_test(void) {
	fx_s1615 divisor = 3194858;
	fx_s1615 a = 0;
	int i=0;
	for ( i = 0; i < 100000000; ++i) {
		a=FX_1615_LONGLONG_DIV02((i),(divisor));
	}
}

static void fx_1615_longlong_div03_test(void) {
	fx_s1615 divisor = 3194858;
	fx_s1615 a = 0;
	int i=0;
	for ( i = 0; i < 100000000; ++i) {
		a=FX_1615_LONGLONG_DIV03((i),(divisor));
	}
}
#endif


int main(void) {

#ifdef MULTIPLE_TIME_TEST
    fx_1615_double_mul_test();
	fx_1615_longlong_mul1_test();
	fx_1615_longlong_mul2_test();
	fx_1615_longlong_mul3_test();
#endif


#ifdef DIVISION_TIME_TEST
    fx_1615_double_test();
	fx_1615_longlong_div01_test();
	fx_1615_longlong_div02_test();
	fx_1615_longlong_div03_test();
#endif

	// 20.08.16 sine 함수 테스트
#ifdef SIN_PRECISION_TEST
	 fx_s1615 fa1 = 0x002D0000;
	 fx_s1615 fa2 = 0x00590000;
	 fx_s1615 fa3 = 0x00B40000;

	 int j  = 0;
	 for (int i = 0x002D0000; i > 0; i = i - 0x4000) {
	 fa1 = fa1 - 0x4000;
	 printf("%6d", sine_fx_s1615(fa1));

	 j++;
	 if (j % 10 == 0) {
	 puts("");
	 }
	 }
#endif


#ifdef FX_MUL_TEST
	 double da;
	 double db;
	 scanf("%lf %lf",&da, &db);

	 fx_s1615 fa,fb,fc;
	 fa =FX_S1615_DOUBLE_TO_INT(da);
	 fb =FX_S1615_DOUBLE_TO_INT(db);

	 printf("Test  multiplication\n");

    fc = FX_S1615_MUL(fa, fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
    da*db - FX_S1615_INT_TO_DOUBLE(fc));
    
	 fc =FX_1615_LONGLONG_MUL1(fa,fb);
	 printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
	 da*db - FX_S1615_INT_TO_DOUBLE(fc));

	 fc =FX_1615_LONGLONG_MUL2(fa,fb);
	 printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
	 da*db - FX_S1615_INT_TO_DOUBLE(fc));

	 fc =FX_1615_LONGLONG_MUL3(fa,fb);
	 printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
	 da*db - FX_S1615_INT_TO_DOUBLE(fc));
#endif
    
#ifdef FX_DIV_TEST
        double da;
        double db;
        scanf("%lf %lf",&da, &db);

        fx_s1615 fa,fb,fc;
        fa =FX_S1615_DOUBLE_TO_INT(da);
        fb =FX_S1615_DOUBLE_TO_INT(db);
	 printf("\nTest division\n");
    fc =FX_S1615_DIV(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
    da/db - FX_S1615_INT_TO_DOUBLE(fc));
    
	 fc =FX_1615_LONGLONG_DIV01(fa,fb);
	 printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
	 da/db - FX_S1615_INT_TO_DOUBLE(fc));

	 fc =FX_1615_LONGLONG_DIV02(fa,fb);
	 printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
	 da/db - FX_S1615_INT_TO_DOUBLE(fc));

	 fc =FX_1615_LONGLONG_DIV03(fa,fb);
	 printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
	 da/db - FX_S1615_INT_TO_DOUBLE(fc));
#endif

	
	return 0;
}
