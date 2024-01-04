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
