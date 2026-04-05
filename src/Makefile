all: kedi

CFLAGS += -std=c23
CFLAGS += -Wall
CFLAGS += -Wconversion
CFLAGS += -Wextra

kedi: main.c
	cc main.c -o kedi $(CFLAGS)

clean:
	rm kedi
