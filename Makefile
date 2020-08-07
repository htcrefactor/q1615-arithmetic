SRCS := test.c fx_s1615_double.c
OBJS := $(SRCS:.c=.o)
CC := gcc	# pre-defined macro can be redefined!
CFLAGS = -c -Wall -g
# CFLAGS = -c -Wall -O2

test : $(OBJS)
	$(CC) -o $@ $^

# default rule
.c.o : 
	$(CC) $(CFLAGS) $<

# dummy target - no dependency 
clean : 
	-rm $(OBJS)
	rm mytest

# dummy target - no dependency 
dep :
	gccmakedep ${SRCS}

