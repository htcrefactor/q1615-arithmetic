SRCS := test.c fx_s1615_double.c fx_1615_longlong.c
OBJS := $(SRCS:.c=.o)
CC := gcc	# pre-defined macro can be redefined!
#CFLAGS = -c -Wall -g
CFLAGS = -Wall

test : $(OBJS)
	$(CC) -o $@ $^ -lm

# default rule
.c.o : 
	$(CC) $(CFLAGS) $< -lm

# dummy target - no dependency 
clean :
	-rm $(OBJS)
	-rm test

# dummy target - no dependency 
dep :
	gccmakedep ${SRCS}
