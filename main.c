#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void part1();
void set_gpio_direction(int pin, const char *direction);

int main()
{
    part1();
}

void part1()
{
    // Init GPIO
    set_gpio_direction(17, "in");
    set_gpio_direction(24, "out");

    int gpio24 = 24;

    FILE *led = fopen("/sys/class/gpio/gpio24/value", "w");
    FILE *button = fopen("/sys/class/gpio/gpio17/value", "r");

    if (led == NULL)
    {
        printf("Error");
    }

    while (true)
    {
        char line[4];
        // fgets(line, sizeof(line), button);
        size_t bytesRead = fread(line, sizeof(char), sizeof(line), button);
        fseek(button, 0, 0);
        

        if (line[0] == '1')
        {
            fprintf(led, "%d", 1);
            // fputs("1", led);
            fflush(led);
            sleep(0.1);
        }
        else if (line[0] == '0')
        {
            fprintf(led, "%d", 0);
            fflush(led);
            sleep(0.1);
        }

        sleep(0.1);
    }
}

void set_gpio_direction(int pin, const char *direction)
{
    char export_path[50];
    char direction_path[50];

    // Create the paths for export and direction files
    snprintf(export_path, sizeof(export_path), "/sys/class/gpio/export");
    snprintf(direction_path, sizeof(direction_path), "/sys/class/gpio/gpio%d/direction", pin);

    // Open /sys/class/gpio/export for writing
    int gpio_export_fd = open(export_path, O_WRONLY);
    if (gpio_export_fd == -1)
    {
        perror("Error opening export file");
        exit(EXIT_FAILURE);
    }

    // Write GPIO pin number to export file
    char pin_str[4];
    snprintf(pin_str, sizeof(pin_str), "%d", pin);
    if (write(gpio_export_fd, pin_str, strlen(pin_str)) == -1)
    {
        perror("Error writing to export file");
        // close(gpio_export_fd);
        // exit(EXIT_FAILURE);
    }
    else
    {
        printf("GPIO pin %d exported successfully\n", pin);
    }

    // Close the export file
    close(gpio_export_fd);

    // Open direction file for writing
    int gpio_direction_fd = open(direction_path, O_WRONLY);
    if (gpio_direction_fd == -1)
    {
        perror("Error opening direction file");
        // exit(EXIT_FAILURE);
    }
    else
    {
        // Write direction to the direction file
        if (write(gpio_direction_fd, direction, strlen(direction)) == -1)
        {
            perror("Error writing to direction file");
            close(gpio_direction_fd);
            // exit(EXIT_FAILURE);
        }
        else
        {
            printf("GPIO pin %d set to %s direction successfully\n", pin, direction);
        }
    }

    // Close the direction file
    close(gpio_direction_fd);
}