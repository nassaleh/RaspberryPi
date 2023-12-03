#include <stdbool.h>
#include <cstdio>

int main()
{
    int gpio24 = 24;

    FILE* led = fopen("/sys/class/gpio/gpio24/value", "w");

    while(true)
    {
        fprintf(led, "%d", 1);
        sleep(1);
        fprintf(led, "%d", 0);
        sleep(1);
    }

}