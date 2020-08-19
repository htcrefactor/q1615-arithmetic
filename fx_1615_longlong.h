#ifndef S1615_LONGLONG_H_
#define S1615_LONGLONG_H_

typedef int fx_s1615;
typedef long long fixed64;

// 32 bit 컴퓨터에서는 성능이 낮아짐. 그러나 overflow 확률이 적고 정밀도도 가장 높음.
// 64 bit 컴퓨터라면 당연히 MUL1을 사용해야 함! 
#define FX_1615_LONGLONG_MUL1(a, b) (fx_s1615) (((fixed64)(a) * (b)) >> 15)
// overflow 확률 높음
// 32 bit 컴퓨터인데 성능이 중요하다면  MUL2나 MUL3 사용
#define FX_1615_LONGLONG_MUL2(a, b) ((a) * (b)) >> 15
#define FX_1615_LONGLONG_MUL3(a, b) ((a >> 8) * (b >> 7))

#define FX_1615_LONGLONG_DIV0(a,b) (fx_s1615)((fixed64)((a >> 15) / (b >> 15)) << 15)
// #define FX_1615_LONGLONG_DIV1(a,b) (fx_s1615)(((fixed64)((a) << 15) / b))
#define FX_1615_LONGLONG_DIV1(a,b) (fx_s1615)((((fixed64)(a << 4) / (b >> 4)) << 7))

#define FX_1615_LONGLONG_DIV2(a,b) (((a << 8) / (b >> 4)) << 3)    // DIV2 속도 테스트 1위
#define FX_1615_LONGLONG_DIV3(a,b) ((a << 8) / (b >> 7))
#define FX_1615_LONGLONG_DIV21(a,b) (((a << 4) / (b >> 4)) << 7) // DIV2 속도 테스트 3위
#define FX_1615_LONGLONG_DIV22(a,b) (((a << 5) / (b >> 6)) << 4) // DIV2 속도 테스트 4위
#define FX_1615_LONGLONG_DIV23(a,b) (((a << 7) / (b >> 4)) << 4) // DIV2 속도 테스트 2위

extern fx_s1615 sine_fx_s1615_longlong(fx_s1615 angle);

#endif