#ifndef __S1615_LONGLONG_H_
#define __S1615_LONGLONG_H_

typedef int fx_s1615;
typedef long long fixed64;

// 오버플로우는 없지만 캐스팅하므로 성능 저하 
#define FX_1615_LONGLONG_MUL1(a, b) (((a) * (b)) >> 15)
// 적절? 
#define FX_1615_LONGLONG_MUL2(a, b) (((a >> 4) * (b >> 4)) >> 7)    // 이건 대략적으로? 직접 해봐야할듯
// a는 2^7 미만, b는 2^8 미만 손실 발생 
#define FX_1615_LONGLONG_MUL3(a, b) ((a >> 8) * (b >> 7)) 
// MUL3는 캐스팅 없이도 연산이 빠르게 할 수 있도록.. 곱하는 값들의 크기가 -1 ~ 1 사이 작은 값 -> 손실 걱정 없이..?
// -1 

fx_s1615 sine_fx_s1615(fx_s1615 angle);

#endif