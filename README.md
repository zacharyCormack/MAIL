# MAIL

## Introduction

This program is a mail daemon.

It has only one dependency, `mutt`.
This is a command line mail software.
It must be configured and installed for this program to work.

## Usage

This program takes three arguments from the command line.
1. When, in UTS seconds, to start sending messages
2. How many messages to send
3. How long, in microseconds, to wait between messages

The message requires command line arguments to be given to `mutt`.

## Workings

The program begins by reading arguments from the command line.
**(If you want to just add them in the command, use `echo` *`args`* `|` *`command`* instead.)**
Then, there is a `if (!fork()) return 0;` statement, which runs the remainder of the program as a `daemon`.
A `stringstream` is initialized to handle arguments, and promptly does so.
Then, using the first arguement, the program waits until after the given time to begin sending messages.
At this point, the `stringstream` is used to convert the next two arguments, and then to get the `mutt` command.
Finally, the command is executed a number of times with pauses in between.
