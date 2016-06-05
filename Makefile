ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT = 
	endif
endif

CC = gcc
CFLAGS = -msse3 -O3 -fomit-frame-pointer -funroll-loops -lm

all: bigfilewriter
	$(CC) $(CFLAGS) -o bigfilewriter$(EXT) bigfilewriter.o

bigfilewriter:
	$(CC) $(CFLAGS) -c bigfilewriter.c

clean:
	$(RM) bigfilewriter$(EXT) bigfilewriter.o
