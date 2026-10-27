#include <stdio.h>
#include <unistd.h>

int main(void) {
    while (1) {
        printf("[+] Cyber Daemon actif — surveillance en cours...\n");
        fflush(stdout);
        sleep(5);
    }
    return 0;
}
