TARGET = programm.exe
HIPE = DinMylib.dll
SRCS = main.c
POP = main2.c
.PHONY: all build clean run

$(HIPE):
		gcc -shared -o $(HIPE) $(SRCS) -fPIC

$(TARGET):
		gcc $(POP) -I. -L. -l:$(HIPE) -o $(TARGET)


all: clean $(TARGET)

build: $(HIPE) $(TARGET)

clean:
		rm -f $(HIPE) $(TARGET)

run: $(TARGET)
		export PATH=.:$$PATH && ./$(TARGET)