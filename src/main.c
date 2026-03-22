#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

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
    enable_raw_mode();
    disable_raw_mode();
    return 0;
}
