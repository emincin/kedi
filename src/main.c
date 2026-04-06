/**
 * @file main.c
 * @author Emin Cin
 * @date 2026-04-05
 *
 * MIT License
 * Copyright (c) 2026 Emin Cin
 *
 * This file is part of kedi.
 * Licensed under the MIT License.
 * See the LICENSE file for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define KEDI_VERSION "0.0.1"

typedef typeof(sizeof(nullptr)) size_t;

typedef struct termios termios;

typedef struct winsize winsize;

typedef struct Size {
    int width;
    int height;
} Size;

typedef struct EditorState {
    Size window_size;
    bool is_running;
} EditorState;

Size get_window_size();

static EditorState editor;

void init_editor() {
    editor.window_size = get_window_size();
    editor.is_running = true;
}

bool is_printable_ascii_char(char c) {
    if (32 <= c && c <= 126) {
        return true;
    }
    return false;
}

bool str_eq(const char* a, const char* b) {
    if (strcmp(a, b) == 0) {
        return true;
    }
    return false;
}

void enable_raw_mode() {
    int ret = 0;
    termios io = {};
    ret = tcgetattr(STDIN_FILENO, &io);
    if (ret == -1) {
    }
    io.c_lflag &= ~(tcflag_t)ECHO;
    io.c_lflag &= ~(tcflag_t)ICANON;
    ret = tcsetattr(STDIN_FILENO, TCSANOW, &io);
    if (ret == -1) {
    }
}

void disable_raw_mode() {
    int ret = 0;
    termios io = {};
    ret = tcgetattr(STDIN_FILENO, &io);
    if (ret == -1) {
    }
    io.c_lflag |= ECHO;
    io.c_lflag |= ICANON;
    ret = tcsetattr(STDIN_FILENO, TCSANOW, &io);
    if (ret == -1) {
    }
}

size_t read_buf(char* buf, size_t len) {
    ssize_t ret = read(STDIN_FILENO, buf, len);
    if (ret == -1) {
        return 0;
    }
    return (size_t)ret;
}

size_t write_buf(const char* buf, size_t len) {
    ssize_t ret = write(STDOUT_FILENO, buf, len);
    if (ret == -1) {
        return 0;
    }
    return (size_t)ret;
}

Size get_window_size() {
    Size size = {};
    winsize ws = {};
    int ret = ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    if (ret == -1) {
        return size;
    }
    size.width = ws.ws_col;
    size.height = ws.ws_row;
    return size;
}

void process_input() {
    char buf[1024] = {};
    size_t count = read_buf(buf, sizeof(buf));
}

void render_screen() {
}

void parse_args(int argc, char** argv) {
    if (argc == 2) {
        if (str_eq(argv[1], "--rawmode")) {
        } else if (str_eq(argv[1], "--version")) {
            printf("%s\n", KEDI_VERSION);
            exit(0);
        }
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);
    init_editor();
    enable_raw_mode();
    while (editor.is_running) {
        render_screen();
        process_input();
    }
    disable_raw_mode();
    return 0;
}
