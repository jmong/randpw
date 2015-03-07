GPLUSPLUS=g++
WOPTIONS=-Wall -Wno-deprecated
DFLAGS=
OUTPUT=randpw
SRC=randpw.cpp

all:
	$(GPLUSPLUS) $(WOPTIONS) -o $(OUTPUT) $(SRC)

debug:
	$(GPLUSPLUS) $(WOPTIONS) -D_DEBUG -o $(OUTPUT) $(SRC)

clean:
	rm -f $(OUTPUT)
