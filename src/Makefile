all: kedi

CFLAGS += -std=c23
CFLAGS += -Wall
CFLAGS += -Wconversion
CFLAGS += -Wextra

kedi: main.c
	cc main.c -o kedi $(CFLAGS)

clean:
	rm kedi

install: kedi
	sudo cp kedi /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/kedi
