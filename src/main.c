#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

void enable_raw_mode(void) {
    struct termios io = {0};
}

void disable_raw_mode(void) {
    struct termios io = {0};
}

int main(int argc, char** argv) {
    return 0;
}
