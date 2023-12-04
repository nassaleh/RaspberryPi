#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void part1();

int main()
{
    part1();
}

void part1()
{
    int gpio24 = 24;

    FILE *led = fopen("/sys/class/gpio/gpio24/value", "w");

    if (led == NULL)
    {
        printf("Error");
    }

    while (true)
    {
        fprintf(led, "%d", 1);
        // fputs("1", led);
        fflush(led);
        sleep(1);
        fprintf(led, "%d", 0);
        fflush(led);
        sleep(1);
    }
}