#make file example

CC = gcc #compiler

# flags para compilar
CFLAGS= -Wall -std=c99 -O3
TARGET= RoaP_Int
# gerar variáveis com listas ficheiros de cada tipo para usar nas várias regras
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRCS))
HEADERS=$(wildcard *.h)
PDFS=$(wildcard *.pdf)

all: 
	$(CC)$(CFLAGS) main.c Processor.c Read.c Write.c -o RoaP_Int

# para criar um tar.gz com todos os ficheiros, dar o comando "make tgz"
tgz: $(TARGET).tar.gz

$(TARGET).tar.gz: $(SRCS) $(HEADERS) $(PDFS)
	tar czvf $@ $^

clean: 
	rm $(TARGET)
