CC     = gcc
CFLAGS = -I./libvec -g -MMD -MP -Wall
LFLAGS = -L./libvec -Wl,-rpath=$(PWD)/libvec
LIBS   = -lvec
OBJS   = main.o
BIN    = a.out

.SUFFIXES: .c.o
.PHONY: clean

ALL: $(BIN)

$(LIBS): 
	make -C libvec

.c.o:
	$(CC) -c $(CFLAGS) $<

$(BIN): $(OBJS) $(LIBS)
	$(CC) $(LFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f *.o *.d *~ $(BIN)
	make -C libvec clean

