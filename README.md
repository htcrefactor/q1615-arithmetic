# battle_c_1

첫 번째 프로젝트 : fx_s1615  
Sign bit를 포함한 fixed point number의 arithmetic 구현  
<br>

## Role

| 이름 | 학번 | 
| ---- | ---- |
| 고예준 | 201820742 | 
| 김지원 | 201720771 | 
| 조시호 | 201520659 | 
| 최형택 | 201620989 | 
<br>

## Table of Contents
- [What is Fixed Point sXXYY?](#what-is-fixed-point-sxxyy-)
  * [Example](#example)
- [Fixed Point vs Floating Point](#fixed-point-vs-floating-point)
- [How to Convert Fixed Point Binary to Decimal](#how-to-convert-fixed-point-binary-to-decimal)
- [Fixed Point Arithmetic Library](#fixed-point-arithmetic-library)
  * [Project1](#project1)
    + [Macros](#macros)
    + [Functions](#functions)
  * [Makefile](#makefile)
  * [gcc -O flag](#gcc--o-flag)
    + [-O flag options](#-o-flag-options)
    + [Optimization Results](#optimization-results)
      - [Theoretical Background](#theoretical-background)
      - [gprof](#gprof)
  * [Project2](#project2)
    + [Macros](#macros-1)
    + [Functions](#functions-1)
  * [Precision Tests](#precision-tests)
  * [Performance Speed Tests](#performance-speed-tests)
  * [Sine](#sine)
    + [Sine Table](#sine-table)
    + [fx_s1615 sine_fx_s1615_longlong(fx_s1615 angle) function에 대하여...](#fx-s1615-sine-fx-s1615-longlong-fx-s1615-angle--function-----)
  * [double vs long long](#double-vs-long-long)
- [0819 Assignment](#0819-assignment)
  * [Requirements Specification](#requirements-specification)
  * [MISRA-C 2012 Conformity Test](#misra-c-2012-conformity-test)
  * [Test Results](#test-results)
- [0820 Assignment](#0820-assignment)




## What is Fixed Point sXXYY?

sXXYY는 2진수로 실수를 표현하는 방법 중 하나다. (1 + XX + YY)개의 비트로 실수를 표현하며 1개 비트는 부호, XX개 비트는 정수부,  YY개 비트는 소수부를 표현한다.  
우리가 구현할 s1615의 경우 32비트를 사용하며 각 비트별로 갖는 의미는 다음과 같다.

| Sign Bit | 정수부 (XX) | 소수부 (YY) |
| ---- | ---- | ---- |
| 0 : 양수, 1 : 음수 | 16 bits | 15 bits |
<br>

```
Maximum : 0111 1111 1111 1111 1111 1111 1111 1111 (2) =  65535.999969482421875 (10)
Minimum : 1111 1111 1111 1111 1111 1111 1111 1111 (2) = -65535.999969482421875 (10)
Resolution : 0000 0000 0000 0000 0000 0000 0000 0001 (2) = 0.000030517578125 (10)
```


### Example

+15000.75라는 수가 있을 때, s1615 고정소수점은 0001 1101 0100 1100 0110 0000 0000 0000<sub>2</sub> 로 표현된다.

```
sign bit: 0 = positive 
정수부:  0011 1010 1001 1000(2) = 15000(10)   
소수부:  0.1100 0000 0000 000(2) = 0.75(10)
```

| Sign Bit | 정수부 (16 bits) | 소수부(15 bits) |
| --- | --- | --- |
| 0 | 0011 1010 1001 1000 | 110 0000 0000 0000 |
| (양수) | 15000 | 1/2 + 1/4 =  0.75 |
<br>

## Fixed Point vs Floating Point
고정 소수점 방식과 다르게, 부동 소수점 방식은 많은 시스템에서 실수를 표현할 때 사용된다 (e.g. `float foo = 3.141592`).  
동일 비트수를 사용할 때 부동 소수점 방식으로 더욱 넓은 범위를 표현할 수 있는 이점이 있기 때문이다.
하지만 부동 소수점만의 표현 방식 때문에 실수를 100% 정확하게 표현할 수 없다는 단점이 있기도 하다.  
이 오차가 누적될 경우 실제로 문제가 되는 경우도 있기 때문에 개발자는 항상 유의해서 코드를 작성해야 한다.  
<br>

## How to Convert Fixed Point Binary to Decimal
s1615를 10진수로 표현하는 방법은 간단하다.   
부호비트를 제외한 31비트 2진수를 10진수로 나타낸 수를 2<sup>YY</sup>로 나눠주면 된다.    

```
0011101010011000110000000000000(2) = 491544576(10)   
491544576 / 2^15 = 15000.75
```  
<br>


## Fixed Point Arithmetic Library


### Project1
#### Macros
* `P2_15 32768.0`

    15자리를 shifting하기 위해 필요한 2<sup>15</sup>를 정의

* `FX_S1615_INT_TO_DOUBLE(a)`

    fx_s1615로 표현한 숫자를 double로 형변환하는 macro

* `FX_S1615_DOUBLE_TO_INT(a)`

    double로 표현한 숫자를 fx_s1615로 형변환하는 macro
<br>
<br>


* `FX_S1615_ADD(a, b)`

    fx_s1615로 표현된 두 값을 더해주는 macro

* `FX_S1615_SUB(a, b)`

    fx_s1615로 표현된 두 값을 빼는 macro

* `FX_S1615_MUL(a, b)`

    fx_s1615로 표현된 두 값을 곱해주는 macro

* `FX_S1615_DIV(a, b)`

    fx_s1615로 표현된 두 값을 나눠주는 macro  
<br>

#### Functions
* `fx_s1615 sine_fx_s1615_int(fx_s1615 a)`

    fx_s1615로 표현된 값의 sine 을 구해주는 함수

* `fx_s1615 sqrt_fx_s1615_int(fx_s1615 a)`

    fx_s1615로 표현된 값의 제곱근을 구해주는 함수

* `fx_s1615 power_fx_s1615_int(fx_s1615 a, double n)`

    fx_s1615로 표현된 값의 n승을 구해주는 함수


### Makefile

1. define : 코드의 재사용성을 증가시키기 위해 반복되는 내용을 정의한다.
```
SRCS := test.c fx_s1615_double.c
OBJS := $(SRCS:.c=.o)
CC := gcc	# pre-defined macro can be redefined!
#CFLAGS = -c -Wall -g
CFLAGS = -c -DTEST -Wall 
```
<br>
<br>


2. 실행 파일 생성  
* $@ : 현재의 target 파일명 
* $^ : 현재 모든 의존 파일들의 명단
* -lm : <math.h> library 추가      
![image](/uploads/39a775cf74f8403d3fbf97ef7b7212f2/image.png)

``` 
test : $(OBJS)
	$(CC) -o $@ $^ -lm
```
<br>
<br>


3. 확장자 규칙 적용 : 일일히 목적 파일들을 gcc로 컴파일하지 않아도 된다. 
* $< : 의존 파일 중 첫번째 파일명   
```
# default rule
.c.o : 
	$(CC) $(CFLAGS) $< -lm
```

<br>
<br>


4. make clean :  .o파일과 실행파일을 지워준다.
```
# dummy target - no dependency 
clean : 
	-rm $(OBJS)
	-rm test
```

<br>
<br>


5. make dep : SRCS에 정의된 파일들이 의존하는 파일을 찾아준다. 
```
# dummy target - no dependency 
dep :
	gccmakedep ${SRCS}  # dependency check
```

### gcc -O flag
#### -O flag options
`[-Olevel]`
- O0 : 최적화를 수행하지 않음 (Default)
- O, -O1 : 코드 크기와 실행 시간을 줄이는 최적화만 수행
- O2 : 메모리 공간과 속도를 희생하지 않는 범위 내의 모든 최적화를 수행
- O3 : -O2 최적화에 인라인 함수와 레지스터에 대한 최적화를 추가로 수행
- Os : -O2 최적화 기능을 사용하지만, 코드 크기를 증가하는 최적화는 제외

#### Optimization Results
for문을 통하여 2,147,483,648(INT_MAX)번의 연산을 반복하는 코드를 작성하고 -O0과 -O2 옵션을 주어 컴파일 한 뒤 실행시간을 측정하였다.

![O2-optimization-result](images/optimization-result.png)

최적화를 하지 않았을 때 for문을 수행하는데 약 5분의 시간이 걸렸으나 -O2 옵션으로 최적화하였을 때 for문을 수행했는가 싶을 정도로 실행시간이 줄어들었음을 확인할 수 있었다.

##### Theoretical Background
실제로 코드가 어떻게 최적화 되었는지 확인하기 위해 gcc -S 옵션을 통해 컴파일된 어셈블리 코드를 분석해 보았다.
```
pi@raspberrypi:~/battle_c_1 $ gcc -S -DTEST -lm test.c
pi@raspberrypi:~/battle_c_1 $ gcc -S -O2 -DTEST -lm test.c -o test_optimization.s
```

복잡한 어셈블리 코드를 전부 해석하지 않고 for문의 시작 시간과 끝난 시간을 알기 위해 호출했던 clock 함수의 위치를 알 수 있다면 그 사이에 수행되는 어셈블리 코드를 통해 최적화 여부를 알 수 있을 것이다.   
실제로 어셈블리 코드는 아직 link 되어있지 않기 때문에 clock 함수의 시그니처가 그대로 남아있었다.

![O2-optimization-assembly](images/O2-optimization-assembly.png)


test.s는 main 라벨에서 처음 clock 함수를 호출한다. 이후 L2 라벨로 이동한뒤 C코드에서 for문에 해당하는 L3 라벨로 이동하고 70줄 가량의 어셈블리 코드를 실행하고 나서야 clock 함수를 호출한다. 라벨을 이동하는 것을 제외하면 C코드와 로직상 다른점이 없다.   
그런데 test_optimization.s는 main 라벨에서 첫 clock 함수를 호출하고 하나의 mov 명령을 수행하자마자 다시 clock 함수를 호출한다. 최적화의 영향인지 for문이 그대로 사라져버렸다.   
실제로 for문 내부에서 실행되는 코드들은 그 안에서만 연산될 뿐 for문 밖의 코드에 영향을 주지 못한다. 외부 변수에 연산의 결과를 저장하거나 출력하는 코드가 없기 때문이다.   
-O2 옵션을 주어 컴파일 하였을 때 컴파일러가 이를 확인하고 어셈블리 코드에 포함시키지 않아 극단적인 성능 차이를 보여준 것으로 보인다.

##### gprof
```
gcc -pg main.c
./a.out #gmon.out is made after running a.out
gprof
```


### Project2
#### Macros
* `typedef long long fixed64`

    fx_s1615로 표현된 숫자를 long long으로 형변환하는 macro
    
<br>
<br>


* `#define FX_1615_LONGLONG_MUL1(a, b) (fx_s1615) (((fixed64)(a) * (b)) >> 15)`

    fx_s1615로 표현된 값을 long long으로 cast 해준 수를 곱한 후, 15만큼 right shifting 해주는 macro

* `#define FX_1615_LONGLONG_MUL2(a, b) ((a) * (b)) >> 15`

    fx_s1615로 표현된 값을 곱해주고 15만큼 right shifting해주는 macro
    
* `#define FX_1615_LONGLONG_MUL3(a, b) ((a >> 8) * (b >> 7))`

    fx_s1615로 표현된 값인 a를 8만큼 right shifting 해주고, b를 7만큼 right shifiting 해준 후, 두 값을 곱해주는 macro  
    
* `#define FX_1615_LONGLONG_DIV01(a, b) (fx_s1615)((fixed64)((a >> 15) / (b >> 15)) << 15)`

    fx_s1615로 표현된 값을 long long으로 cast 해주고, a와 b를 각각 15만큼 right shfiting 하고 a 와 b를 나눠준 후, 15만큼 left shifting 해주는  macro  
    
    
* `#define FX_1615_LONGLONG_DIV02(a, b) (((a << 5) / (b >> 6)) << 4)`

    fx_s1615로 표현된 값인 a를 5만큼 left shifting 해주고, b를 6만큼 right shfiting 하고 나눠준 후, 4만큼 left shifting 해주는  macro  
    
    
* `#define FX_1615_LONGLONG_DIV03(a, b) (fx_s1615)(((fixed64)(a) << 15) / (b))`

    fx_s1615로 표현된 값을 long long으로 cast 해주고, a를 15만큼 left shfiting 하고 b와 나눠주는  macro  
    
    
    
<br>

#### Functions
* `fx_s1615 sine_fx_s1615_longlong(fx_s1615 angle)`

    fx_s1615로 표현된 각의 sine 을 구해주는 함수





### Precision Tests
* Multiply
1. MUL_01
![image](images/MUL_01.png)

2. MUL_02
![image](images/MUL_02.png)

3. MUL_03
![image](images/MUL_03.png)

위에 첨부된 엑셀 시뮬레이션 결과를 보면 MUL_01의 경우 범용적으로 사용하기 좋다.
MUL_02와 MUL_03의 경우 상호보완적인 연산으로서의 서로의 단점을 보완해주며 근접한 성능을 보인다.
MUL_02의 경우 소수부에서의 정밀도가 높아 작은 수에 적합하며 MUL_03의 경우 정수부에서의 정밀도가 높아 큰 수에 적합하다.

연산 정확도는 다양한 환경 (구동 시스템 비트 수, 등)에 따라 다르기 때문에 1차원적으로 비교하는 것은 적절치 않다.
사용 목적에 따라 필요한 연산을 선택해 사용하는 것이 권장된다.

<br>

* Division
1. DIV_01
![image](images/DIV_01.png)

2. DIV_02
![image](images/DIV_02.png)

3. DIV_03
![image](images/DIV_03.png)

위에 첨부된 엑셀 시뮬레이션 결과를 보면 과제 명세에 해당하는 64비트 시스템에선 DIV_01과 DIV_02를 사용하는 것이 적절하다.
상대적으로 큰 숫자는 DIV_01로, 작은 숫자는 DIV_02로 연산을 수행하면 좋다.
DIV_03의 경우 오차율이 조금 증가하지만 범용적으로 사용할 수 있다는 장점이 있다.

연산 정확도는 다양한 환경 (구동 시스템 비트 수, 등)에 따라 다르기 때문에 1차원적으로 비교하는 것은 적절치 않다.
사용 목적에 따라 필요한 연산을 선택해 사용하는 것이 권장된다.
<br>
<br>

### Performance Speed Tests

![image](images/speed-experiment.png)

* 32bit 실행 결과

1. Multiply

    MUL_03 = MUL_02 < MUL_01



2. Division    

    DIV_03 < DIV_02 < DIV_01


<br>

* 64bit 실행 결과
1. Multiply     

    MUL_03 < MUL_02 < MUL_01



2. Division      

    DIV_01 = DIV_02 < DIV_03

<br>
<br>

### Sine

#### Sine Table
angle 이 0도부터 90도까지인 경우, sine 값을 fx_s1516으로 표현한 SineTable이다.
불필요한 연산을 줄이고자 아래와 같은 SineTable을 사용하게 되었다.

```
const static fx_s1615 fx_1615_SineTable[91] = { 
        0,   571,  1143,  1714,  2285,  2855,  3425,  3993,  4560,  5126,  
     5690,  6252,  6812,  7371,  7927,  8480,  9032,  9580, 10125, 10668, 
    11207, 11743, 12275, 12803, 13327, 13848, 14364, 14876, 15383, 15886,
    16384, 16876, 17364, 17846, 18323, 18794, 19260, 19720, 20173, 20621, 
    21062, 21497, 21926, 22347,	22762, 23170, 23571, 23964, 24351, 24730, 
    25101, 25465, 25821, 26169, 26509, 26841, 27165, 27481, 27788, 28087, 
    28377, 28659, 28932, 29196, 29451, 29697, 29935, 30163, 30381, 30591, 
    30791, 30982, 31164, 31336, 31498, 31651, 31794, 31928, 32051, 32165,
    32270, 32364, 32449, 32523, 32588, 32643, 32688, 32723, 32748, 32763,
    32768 
};


```


#### fx_s1615 sine_fx_s1615_longlong(fx_s1615 angle) function에 대하여...
이 함수는 파라미터를 각도로 받아오는 경우, 해당하는 sin값을 찾아서 반환해주는 함수이다.
sin은 360도를 주기로 하는 함수이기 때문에, angle이 360도로 나누었을때의 나머지에 대한 값의 sine 값을 찾아주고자 하였다.

```
idx = angle >> 15;

ret0 = fx_1516_SinTable[idx]; 
diff = fx_1516_SinTable[idx + 1] - ret0;
return ( sign * ( ret0 + ((diff * (angle & 0x7FFF)) >> 15) ));
```

fx_1516_SinTable은 fx_s1516에 맞춰진 표이므로, fx_s1615에 맞춰 변환하기 위해 위의 코드와 작업을 하였다.


<br>
<br>



### double vs long long

* double 과 long long으로 형변환을 하여 곱셈 및 나눗셈을 수행할 때, 어떤 것이 더 빠른지 측정해보았다.

1. multiple test

 
 ```
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls   s/call   s/call  name    
 63.43      2.00     2.00        1     2.00     2.00  fx_1615_double_mul_test
 12.69      2.41     0.40        1     0.40     0.40  fx_1615_longlong_mul1_test
 12.05      2.79     0.38        1     0.38     0.38  fx_1615_longlong_mul2_test
 12.05      3.17     0.38        1     0.38     0.38  fx_1615_longlong_mul3_test

			Call graph


granularity: each sample hit covers 2 byte(s) for 0.32% of 3.17 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.00    3.17                 main [1]
                2.00    0.00       1/1           fx_1615_double_mul_test [2]
                0.40    0.00       1/1           fx_1615_longlong_mul1_test [3]
                0.38    0.00       1/1           fx_1615_longlong_mul3_test [5]
                0.38    0.00       1/1           fx_1615_longlong_mul2_test [4]
-----------------------------------------------
                2.00    0.00       1/1           main [1]
[2]     63.3    2.00    0.00       1         fx_1615_double_mul_test [2]
-----------------------------------------------
                0.40    0.00       1/1           main [1]
[3]     12.7    0.40    0.00       1         fx_1615_longlong_mul1_test [3]
-----------------------------------------------
                0.38    0.00       1/1           main [1]
[4]     12.0    0.38    0.00       1         fx_1615_longlong_mul2_test [4]
-----------------------------------------------
                0.38    0.00       1/1           main [1]
[5]     12.0    0.38    0.00       1         fx_1615_longlong_mul3_test [5]
-----------------------------------------------

Index by function name

   [2] fx_1615_double_mul_test [4] fx_1615_longlong_mul2_test
   [3] fx_1615_longlong_mul1_test [5] fx_1615_longlong_mul3_test

 ```

[실행 결과 정리]
* double이 long long으로 곱셈을 실행하는 것 보다 더 많은 시간이 소요된다는 것을 알 수 있었다.
* fx_s1615로 표현된 값인 a를 8만큼 right shifting 해주고, b를 7만큼 right shifiting 해준 후, 두 값을 곱해주는 fx_1615_longlong_mul3_test의 실행속도가 가장 빠른 것을 알 수 있었다.

<br>
<br>


## 0819 Assignment

### Requirements Specification
* 목적   
32bit의 fixed point 연산을 구현한다.   
double을 사용한 연산과 long long을 사용한 연산을 나누어 구현하며 이 차이를 구분
할 수 있는 테스트 함수들을 작성하고 분석한다.

<br>
<br>

* 제공 기능


| 매크로 및 함수 이름 | 기능 |
| ---- | ---- |
| FX_S1615_ADD(a,b) | fx_s1615로 표현된 두 값을 더해준다.  |
| FX_S1615_SUB(a,b) | fx_s1615로 표현된 두 값을 빼준다. |
| FX_S1615_MUL(a,b) | fx_s1615로 표현된 두 값을 곱해준다. |
| FX_S1615_DIV(a,b) | fx_s1615로 표현된 두 값을 나눠준다. |
| ---- | ---- |
| fx_s1615 sine_fx_s1615_int(fx_s1615 a) | fx_s1615로 표현된 값의 sine 을 구해준다.  |
| fx_s1615 sqrt_fx_s1615_int(fx_s1615 a) | fx_s1615로 표현된 값의 제곱근을 구해준다. |
| fx_s1615 power_fx_s1615_int(fx_s1615 a, double n) | fx_s1615로 표현된 값의 n승을 구해준다. |
| ---- | ---- |
| FX_1615_LONGLONG_MUL1(a,b) | fx_s1615로 표현된 값을 long long으로 cast 해준 수를 곱한 후, 15만큼 right shifting 해주어 곱셈을 수행한다. 속도는 가장 느리나 정밀도가 가장 높다. 또한 오버플로가 발생하지 않는다. |
| FX_1615_LONGLONG_MUL2(a,b) | fx_s1615로 표현된 값을 곱해주고 15만큼 right shifting해주어 곱셈을 수행한다. 속도는 빠르고 소수부 정밀도 손실 또한 없다. 하지만 정수부가 크면 오버플로의 가능성이 있으므로 절대값이 10 이하인 값의 연산에만 사용할 것을 권장 |
| FX_1615_LONGLONG_MUL3(a,b) | fx_s1615로 표현된 값인 a를 8만큼 right shifting 해주고, b를 7만큼 right shifiting 해준 후, 두 값을 곱해주어 곱셈을 수행한다. 소수부 정밀도에서 약간의 손실이 있으나 준수한 속도를 가지는 함수이다.  |
| ---- | ---- |
| FX_1615_LONGLONG_DIV01(a,b) | fx_s1615로 표현된 값을 long long으로 cast 해주고, a와 b를 각각 15만큼 right shfiting 하고 a 와 b를 나눠준 후, 15만큼 left shifting 해주어 나눗셈을 수행한다. 소수부가 대부분 손실 되므로 정수부가 큰 연산에 적합하다. | 
| FX_1615_LONGLONG_DIV02(a,b) | fx_s1615로 표현된 값을 long long으로 cast 해주고, a를 15만큼 left shfiting 하고 b와 나눠주어 나눗셈을 수행한다. 연산을 수행해도 손실되는 값이 거의 없어 정밀도가 높다. 32bit 시스템에선 가장 빠르나 64bit 시스템에선 느리다는 단점이 있다. |
| FX_1615_LONGLONG_DIV03(a,b) | fx_s1615로 표현된 값인 a를 5만큼 left shifting 해주고, b를 6만큼 right shfiting 하고 나눠준 후, 4만큼 left shifting 해주어 나눗셈을 수행한다. 약간의 정밀도 손해를 감수하되 시스템에 상관 없이 항상 준수한 속도의 연산을 수행한다. |





<br>
<br>

* 테스트 빌드 및 분석 방법
    - 다음과 같은 순서로 빌드 후 분석한다.
        1. ``make DEFINE=D[macro] PG=-pg``
        2. ``./test``
        3. ``gprof test``


    - 조건부 컴파일을 이용하여 macro의 정의에 따라 다른 test가 수행되도록 코드를 구성하였다.
        ```
        [ifdef로 정의된 macro]
        (1) MULTIPLE_TIME_TEST : 곱셈을 수행하는 경우, double vs long long 시간 테스트
        (2) DIVISION_TIME_TEST : 나눗셈을 수행하는 경우, double vs long long 시간 테스트
        (3) SIN_PRECISION_TEST : sine table이 알맞은지 확인하기 위해 시험해주는 테스트
        (4) FX_MUL_TEST : scanf로 두개의 숫자를 받았을 때, 정의된 4가지 함수로 곱셈을 수행해주는 테스트
        -->FX_S1615_MUL(a, b), FX_1615_LONGLONG_MUL1(a, b),FX_1615_LONGLONG_MUL2(a, b),FX_1615_LONGLONG_MUL3(a, b)
        (5) FX_DIV_TEST : scanf로 두개의 숫자를 받았을 때, 정의된 4가지 함수로 나눗셈을 수행해주는 테스트
        -->FX_S1615_DIV(a, b), FX_1615_LONGLONG_DIV01(a,b),FX_1615_LONGLONG_DIV02(a,b),FX_1615_LONGLONG_DIV03(a,b)
        ```


<br>
<br>


### MISRA-C 2012 Conformity Test
총 39였던 오류를 아래의 20개의 오류로 수정하였다.

```
* #define은 __로 시작할 수 없다.
* int main에 파라미터가 없는 경우 void를 명시적으로 표시해야 한다.
* 함수를 정의하기전에 선언이 필요하다.
* 동일한 이름을 가진 변수가 존재하면 안된다.
```
![0819_capture](/uploads/82b0d00d85a19bd008dacec005b46586/0819_capture.PNG)

### Test Results
violations 첨부함


## 0820 Assignment
* 유닛테스트를 통해 커버리지 확인하기

![0820_TeamProject](/uploads/d2896b245ff5835e5138c144fc64831a/0820_TeamProject.PNG)


CodeScroll Controller Tester 에서 유닛테스트를 실행해서 커버리지를 확인한 결과, 
분기가 없는 함수들이기 때문에 100이 나오는 것을 확인할 수 있었다.