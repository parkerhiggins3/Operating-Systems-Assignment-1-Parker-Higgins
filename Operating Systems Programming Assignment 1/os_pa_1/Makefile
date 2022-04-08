

CC= gcc -pthread -lrt
CFLAGS=-g -Wall
OBJS=table.o 
EXE= consumer.elf producer.elf destroy.elf

all: $(EXE)

%.elf: %.o $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.dSYM *.o $(EXE)