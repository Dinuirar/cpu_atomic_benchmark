CFLAGS=-g -Wall -Wextra -Werror -std=gnu11
ifeq ($(DEBUG),1)
 CFLAGS+=-Og -DDEBUG
else
 CFLAGS+=-O3
endif

ifeq ($(TEST),1)
 CFLAGS+=-DTEST
endif

LDLIBS=-lrt -lpthread -lm

PROGS = threads ring

OBJS = bench.o

all: $(PROGS)

ring: ring.o bench.o

threads: threads.o bench.o

clean:
	rm -f $(PROGS) $(PROGS:=.o) $(OBJS)
