# battle_c_1

첫 번째 프로젝트 : fx_s1615
sign bit를 포함한 fixed point 수의 arithmetic 구현

## Role

| 조원이름 | 학번 | 역할분담 |
| ---- | ---- | ---- |
| 고예준 | 201820742 | README 파일 작성 |
| 김지원 | 201720771 | fixed point arithmetic 구현 |
| 조시호 | 201520659 | README 파일 작성 |

## What is fixed point sXXYY?

sXXYY는 2진수로 소수를 표현하는 방법 중 하나이다.   
(1 + XX + YY)개의 비트로 수를 표현하며 1bit s는 부호, XX는 정수부의 비트 수,  YY는 소수부의 비트 수를 나타낸다.   
우리가 구현할 s1615의 경우 32비트를 사용하며 각 비트별로 갖는 의미는 다음과 같다.

| sign bit | 정수부(XX) | 소수부(YY) |
| ---- | ---- | ---- |
| 0 : 양수, 1 : 음수 | 16 bits | 15 bits |

+15000.75라는 수가 있을 때 s1615 고정소수점은 000011101010011000110000000000000로 표현된다.
```
sign bit: 0 = positive 
정수부:  00011101010011000(2) = 15000(10)   
소수부:  0.110000000000000(2) = 0.75(10)
```

s1615를 10진수로 표현하는 방법은 간단하다.   
부호비트를 제외한 31비트 2진수를 10진수로 나타낸 수를 2의 YY승으로 나누어주면 된다.    
```
00011101010011000110000000000000(2) = 491544576(10)   
491544576 / 2^15 = 15000.75
```


## Fixed point arithmetic

### macro
p2_15 32768.0   // 2^15
15자리를 shifting하기 위해 필요한 2^15를 정의


fx_s1615_to_double(a)
fx_s1615로 표현한 숫자를 double로 형변환하는 macro 함수

double_to_fx_s1615(a) 
double로 표현한 숫자를 fx_s1615로 형변환하는 macro 함수



fx_add(a, b) 
fx_s1615로 표현된 두 값을 더해주는 macro 함수

fx_sub(a, b)
fx_s1615로 표현된 두 값을 빼는 macro 함수

fx_mul(a, b) 
fx_s1615로 표현된 두 값을 곱해주는 macro 함수

fx_div(a, b) 
fx_s1615로 표현된 두 값을 나눠주는 macro 함수


### function
fx_s1615 fx_sine(fx_s1615 a);
fx_s1615로 표현된 값의 sin 을 구해주는 함수

fx_s1615 fx_sqrt(fx_s1615 a);
fx_s1615로 표현된 값의 제곱근을 구해주는 함수

fx_s1615 fx_power(fx_s1615 a, double n);
fx_s1615로 표현된 값의 n승을 구해주는 함수



