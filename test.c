#include <stdio.h>
#include "fx_s1615_double.h"
#include "fx_1615_longlong.h"
#include <time.h>
#include <limits.h>

void fx_1615_longlong_mul1_test(void) {
    fx_s1615 divisor = 62764;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_MUL1(i, divisor);
    }
}

void fx_1615_longlong_mul2_test(void) {
    fx_s1615 divisor = 62764;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_MUL2(i, divisor);
    }
}

void fx_1615_longlong_mul3_test(void) {
    fx_s1615 divisor = 62764;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_MUL3(i, divisor);
    }
}

void fx_1615_longlong_div1_test(void) {
    fx_s1615 divisor = 3194858;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_DIV1(i, divisor);
    }
}

void fx_1615_longlong_div2_test(void) {
    fx_s1615 divisor = 3194858;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_DIV2(i, divisor);
    }
}

void fx_1615_longlong_div2_test1(void) {
    fx_s1615 divisor = 3194858;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_DIV21(i, divisor);
    }
}void fx_1615_longlong_div2_test2(void) {
    fx_s1615 divisor = 3194858;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_DIV22(i, divisor);
    }
}void fx_1615_longlong_div2_test3(void) {
    fx_s1615 divisor = 3194858;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_DIV23(i, divisor);
    }
}


void fx_1615_longlong_div3_test(void) {
    fx_s1615 divisor = 3194858;
    for (int i = 0; i < 100000000; ++i) {
        FX_1615_LONGLONG_DIV3(i, divisor);
    }
}

int main() {
    
    fx_1615_longlong_mul1_test();
    fx_1615_longlong_mul2_test();
    fx_1615_longlong_mul3_test();

    fx_1615_longlong_div1_test();
    fx_1615_longlong_div2_test();
    fx_1615_longlong_div2_test1();
    fx_1615_longlong_div2_test2();
    fx_1615_longlong_div2_test3();
    fx_1615_longlong_div3_test();

/*
    for (int i = 0; i < 10; ++i) {
        fx_s1615 k = 0x50000;
        fx_s1615 in;
        scanf("%x", &in);

        printf("DIV1: %x\n", (fx_s1615)FX_1615_LONGLONG_DIV1(k, in));
        printf("DIV2: %x\n", (fx_s1615)FX_1615_LONGLONG_DIV2(k, in));
        printf("DIV3: %x\n", (fx_s1615)FX_1615_LONGLONG_DIV3(k, in));
    }
*/

        // 20.08.16 sine 함수 테스트
    /*
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
    */
    /* 오차가 발생하는 주기 찾기
    double da;
    double db;
    scanf("%lf %lf",&da, &db);
    
    fx_s1615 fa,fb,fc;
    fa =FX_S1615_DOUBLE_TO_INT(da);
    fb =FX_S1615_DOUBLE_TO_INT(db);
    
    printf("Test  multiplication\n");
    
    fc =FX_1615_LONGLONG_MUL1(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
           da*db - FX_S1615_INT_TO_DOUBLE(fc));
    
    fc =FX_1615_LONGLONG_MUL2(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
              da*db - FX_S1615_INT_TO_DOUBLE(fc));
    
    fc =FX_1615_LONGLONG_MUL3(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da*db, FX_S1615_INT_TO_DOUBLE(fc),
              da*db - FX_S1615_INT_TO_DOUBLE(fc));
    
    printf("\nTest division\n");
    fc =FX_1615_LONGLONG_DIV1(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
           da/db - FX_S1615_INT_TO_DOUBLE(fc));
    
    fc =FX_1615_LONGLONG_DIV2(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
    da/db - FX_S1615_INT_TO_DOUBLE(fc));
    
    fc =FX_1615_LONGLONG_DIV3(fa,fb);
    printf("Exact answer = %f func result = %f, error = %f\n",da/db, FX_S1615_INT_TO_DOUBLE(fc),
    da/db - FX_S1615_INT_TO_DOUBLE(fc));
    */

    

/*
    clock_t start = clock();
    volatile long long sum = 0;
    for(int i = 0 ; i < INT_MAX ; i++) {
        
        double a = 20.0, b = 30.0;
        fx_s1615 fxa = FX_S1615_DOUBLE_TO_INT(a), fxb = FX_S1615_DOUBLE_TO_INT(b);
#ifndef TEST
        printf("%f %d %f %d\n", a, fxa, b, fxb);
#endif
        fx_s1615 fxc = FX_S1615_DIV(fxa, fxb);
#ifndef TEST
        printf("%d %f\n", fxc, FX_S1615_INT_TO_DOUBLE(fxc));
#endif  
        double d = 50.0;
        fx_s1615 fxd = FX_S1615_DOUBLE_TO_INT(d);
#ifndef TEST
        printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxd), FX_S1615_INT_TO_DOUBLE(sqrt_fx_s1615_int(fxd)));
#endif
        double e = 3.0;
        fx_s1615 fxe = FX_S1615_DOUBLE_TO_INT(e);
#ifndef TEST
        printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxe), FX_S1615_INT_TO_DOUBLE(power_fx_s1615_int(fxe, 4)));
#endif
        double f = 30.0;
        fx_s1615 fxf = FX_S1615_DOUBLE_TO_INT(f);
#ifndef TEST
        printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxf), FX_S1615_INT_TO_DOUBLE(sine_fx_s1615_int(fxf)));    
#endif
        sum = fxa + fxb + fxc + fxd + fxe + fxf;
    }
    clock_t end = clock();
    
    printf("Dummy sum: %lld\n", sum);

    printf("Total run time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
*/
    return 0;
}
