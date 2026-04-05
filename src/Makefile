all: kedi

CFLAGS += -std=c23
CFLAGS += -Wconversion

kedi: main.c
	cc main.c -o kedi $(CFLAGS)

clean:
	rm kedi
