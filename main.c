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
    FILE *button = fopen("/sys/class/gpio/gpio17/value", "r");

    if (led == NULL)
    {
        printf("Error");
    }

    while (true)
    {
        char line[1];
        fgets(line, sizeof(line), button);

        if (line[0] == '1')
        {
            fprintf(led, "%d", 1);
            // fputs("1", led);
            fflush(led);
            sleep(1);
        }
        else if (line[0] == '0')
        {
            fprintf(led, "%d", 0);
            fflush(led);
            sleep(1);
        }
    }
}