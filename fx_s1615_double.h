#ifndef __S1615_DOUBLE_H_
#define __S1615_DOUBLE_H_

typedef int fx_s1615;

#define p2_15 32768.0   // 2^15
#define fx_s1615_int_to_double(a) ((a) / p2_15)
#define fx_s1615_double_to_int(a) (int)((a) * p2_15)

#define fx_add(a, b) ((a) + (b))
#define fx_sub(a, b) ((a) - (b))
#define fx_mul(a, b) fx_s1615_double_to_int(fx_s1615_int_to_double(a) * fx_s1615_int_to_double(b))
#define fx_div(a, b) fx_s1615_double_to_int(fx_s1615_int_to_double(a) / fx_s1615_int_to_double(b))

fx_s1615 fx_sine(fx_s1615 a);
fx_s1615 fx_sqrt(fx_s1615 a);
fx_s1615 fx_power(fx_s1615 a, double n);

#endif