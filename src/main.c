#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

typedef struct {
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
    ret = tcsetattr(STDIN_FILENO, TCSANOW, &io);
}

void disable_raw_mode(void) {
    int ret = 0;
    struct termios io = {0};
    ret = tcgetattr(STDIN_FILENO, &io);
    ret = tcsetattr(STDIN_FILENO, TCSANOW, &io);
}

int main(int argc, char** argv) {
    init_editor();
    enable_raw_mode();
    while (editor.is_running) {
    }
    disable_raw_mode();
    return 0;
}
