CC=gcc
AR=ar
OBGECT_LIB_CLASS_REC_A= stringClass.o
OBGECT_LIB_CLASS_REC_SO= stringClass.o
FLAGS=-g -Wall
all: recursives loopd stringProg maindrec


recursives: libclassrec.a
loopd:libclassrec.so

libclassrec.a:$(OBGECT_LIB_CLASS_REC_A)
	$(AR) -rcs libclassrec.a $(OBGECT_LIB_CLASS_REC_A)

libclassrec.so:$(OBGECT_LIB_CLASS_REC_SO) 
	$(CC) -shared -o libclassrec.so $(OBGECT_LIB_CLASS_REC_SO)

stringClass.o: stringClass.c stringClass.h 
	$(CC) $(FLAGS) -c stringClass.c

stringProg: main.o libclassrec.a 
	$(CC) $(FLAGS) -o stringProg main.o libclassrec.a
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c stringClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg maindrec