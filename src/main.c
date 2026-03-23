#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

typedef struct EditorState {
    bool is_running;
} EditorState;

static EditorState editor;

void init_editor(void) {
    editor.is_running = true;
}

void enable_raw_mode(void) {
    int ret = 0;
    struct termios io = {0};
    ret = tcgetattr(STDIN_FILENO, &io);
    io.c_lflag &= ~ECHO;
    io.c_lflag &= ~ICANON;
    ret = tcsetattr(STDIN_FILENO, TCSANOW, &io);
}

void disable_raw_mode(void) {
    int ret = 0;
    struct termios io = {0};
    ret = tcgetattr(STDIN_FILENO, &io);
    io.c_lflag |= ECHO;
    io.c_lflag |= ICANON;
    ret = tcsetattr(STDIN_FILENO, TCSANOW, &io);
}

int read_buf(char* buf, int len) {
    int count = 0;
    count = read(STDIN_FILENO, buf, len);
    return count;
}

int write_buf(const char* buf, int len) {
    int count = 0;
    count = write(STDOUT_FILENO, buf, len);
    return count;
}

void process_input() {
    char buf[1024] = {};
    int count = read_buf(buf, sizeof(buf));
}

void render_screen() {
}

void parse_args(int argc, char** argv) {
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
