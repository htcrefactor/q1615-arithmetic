#ifndef __S1615_DOUBLE_H_
#define __S1615_DOUBLE_H_

typedef int fx_s1615;

#define P2_15 32768.0   // 2^15
#define FX_S1615_INT_TO_DOUBLE(a) ((a) / P2_15)
#define FX_S1615_DOUBLE_TO_INT(a) (int)((a) * P2_15)

#define FX_S1615_ADD(a, b) ((a) + (b))
#define FX_S1615_SUB(a, b) ((a) - (b))
#define FX_S1615_MUL(a, b) FX_S1615_DOUBLE_TO_INT(FX_S1615_INT_TO_DOUBLE(a) * FX_S1615_INT_TO_DOUBLE(b))
#define FX_S1615_DIV(a, b) FX_S1615_DOUBLE_TO_INT(FX_S1615_INT_TO_DOUBLE(a) / FX_S1615_INT_TO_DOUBLE(b))

extern fx_s1615 sine_fx_s1615_int(fx_s1615 a);
extern fx_s1615 sqrt_fx_s1615_int(fx_s1615 a);
extern fx_s1615 power_fx_s1615_int(fx_s1615 a, double n);

#endif
