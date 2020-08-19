#ifndef S1615_LONGLONG_H_
#define S1615_LONGLONG_H_

typedef int fx_s1615;
typedef long long fixed64;

#define FX_1615_LONGLONG_MUL1(a, b) (fx_s1615)((fixed64)(a) * (b)) >> 15)
#define FX_1615_LONGLONG_MUL2(a, b) ((a) * (b)) >> 15
#define FX_1615_LONGLONG_MUL3(a, b) ((a >> 8) * (b >> 7)) 

#define FX_1615_LONGLONG_DIV1(a,b) (((fixed64)(a) << 15) / b)
#define FX_1615_LONGLONG_DIV2(a,b) (((a << 8) / (b >> 4)) << 3)    // DIV2 속도 테스트 1위
#define FX_1615_LONGLONG_DIV3(a,b) ((a << 8) / (b >> 7))
#define FX_1615_LONGLONG_DIV21(a,b) (((a << 4) / (b >> 4)) << 7) // DIV2 속도 테스트 3위
#define FX_1615_LONGLONG_DIV22(a,b) (((a << 5) / (b >> 6)) << 4) // DIV2 속도 테스트 4위
#define FX_1615_LONGLONG_DIV23(a,b) (((a << 7) / (b >> 4)) << 4) // DIV2 속도 테스트 2위


extern fx_s1615 sine_fx_s1615_longlong(fx_s1615 angle);

#endif
