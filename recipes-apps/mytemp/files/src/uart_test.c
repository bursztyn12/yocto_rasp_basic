#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

static const char uart2_path[] = "/dev/ttyAMA1";
static int uart2_port;

static struct termios uart2;

static char msg[] = {'D', 'u', 'p', 'a', '2'};
static char response_buf[256];

int main(void){
    if ((uart2_port = open(uart2_path, O_RDWR)) < 0){
        printf("Ooops error: %i ... failed to open the uart2 dev (%s)", errno, strerror(errno));
        return 1;
    }

    if(tcgetattr(uart2_port, &uart2) != 0){
        printf("Ooops error: %i ... faild to initialize uart2 (%s)", errno, strerror(errno));
        return 1;
    }

    printf("uart2 port: %i \n", uart2_port);

    /** disable parity */
    //uart2.c_cflag &= ~PARENB;

    /** one stop bit */
    //uart2.c_cflag &= ~CSTOP;
    char read_buf[256];

    /** disable flow control */
    //uart2.c_cflag &= ~CRTSCTS;

    /** disable canonical mode */
    //uart2.c_lflag &= ~ICANON;

    /** disable echo, erasure */
    //uart2.c_lflag &= ~(ECHO | ECHOE);
    
    /** disable signal chars */
    //uart2.c_lflag &= ~ISIG;

    /** disable flow control */
    //uart2.c_iflag &= ~(IXON | IXOFF | IXANY);
    
    /** disable special handling stuff */
    //uart2.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);

    /** save settings */

    write(uart2_port, msg, sizeof(msg));
    sleep(10);
    int idx = read(uart2_port, &response_buf, sizeof(response_buf));
    
    printf("Bytes read: %i \n", idx);
    printf("Response: %s \n", response_buf);

    close(uart2_port);

    return 0;
}