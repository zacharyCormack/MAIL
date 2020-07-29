# MAIL

## Introduction

This program is a mail daemon.

It has only one dependency, `mutt`.
This is a command line mail software.
It must be configured and installed for this program to work.

## Usage

This program requires at least three arguments.
1. When, in UTS seconds, to start sending messages
2. How many messages to send
3. How long, in microseconds, to wait between messages

*However*, the message will be unable to send if no additional arguments are required.
This is because any remaining arguments are forwarded to `mutt`.
So, you need to also provide arguments for mutt.

## Workings

The program begins with `if (!fork()) return 0;`, which runs the program as a `daemon`.
A `stringstream` is initialized to handle arguments, and promptly does so.
Then, using the first arguement, the program waits until after the given time to begin sending messages.
At this point, the `stringstream` is used to convert the next two arguments, and then to get the `mutt` command.
Finally, the command is executed a number of times with pauses in between.
