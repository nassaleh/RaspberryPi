# Useful Links

https://github.com/Projet-Sherbrooke

# Part 1

## Make a program that reads from switch and makes light blink
Step 1: Do C
Step 2: Do lower level Linux system calls, like polling
    open poll file, poll on file descriptor,

https://www.kernel.org/doc/Documentation/gpio/sysfs.txt
https://www.ics.com/blog/gpio-programming-using-sysfs-interface

Use system calls in C instead of writing to sysfs directly

use open/write instead of sopen

## Use poll system call
poll file for switch
https://man7.org/linux/man-pages/man2/poll.2.html

Use C library `poll` (look up man poll)

https://www.youtube.com/watch?v=O-yMs3T0APU

# Unix domain sockets

# Create `Make` files

# Systemd service

https://man7.org/linux/man-pages/man2/lseek.2.html

# Linux Sockets
BEEJ.us/guide

# Part 2
Configure BMP280
https://iotstarters.com/configuring-bmp280-sensor-with-raspberry-pi/