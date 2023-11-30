IDIR=./include
SRCDIR=./src
TSTDIR=./test

CC=gcc
CFLAGS=-I$(IDIR)

_DEPS = dice.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DRIV = diceDriver.c
DRIV = $(patsubst %,$(SRCDIR)/%,$(_DRIV))

_SRC = diceLogic.c
SRC = $(patsubst %,$(SRCDIR)/%,$(_SRC))

_TESTDEPS = diceTest.h
TESTDEPS = $(patsubst %,$(IDIR)/%,$(_TESTDEPS))

_TSTSRC = diceTest.c
TSTSRC = $(patsubst %,$(TSTDIR)/%,$(_TSTSRC))

.DEFAULT_GOAL: dice

dice: $(DRIV) $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

test: $(TSTSRC)	$(SRC)
	$(CC) -o $@ $^ $(CFLAGS)
	test.exe