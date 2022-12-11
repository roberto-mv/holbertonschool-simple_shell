C - Simple Shell
Everything you need to know to start coding your own shell

Description
This version of a simple shell will execute commands that are found in the path and some built ins. All output is written to stdout, this shell can work in both interactive mode, and non-interactive mode.

File list
- AUTHORS : Authors
- README.md : Description projec
- builtins.c : Exit builtin now frees line before exit with bad arguments
- contructors.c : Add constructor functions
- finders.c : Handle message errors
- free.c : Free only if not NULL
- getcmd.c : Add sigint handler
- gettoken.c : Add gettoken function
- helpers.c : Set unused variable
- main.c : Free line before exit 127 in non interactive mode
- main.h : Add structure list_t
- man_1_simple_shell : Man simple shell
- parsers.c : Improve parsing
- runcmd.c : Add environ variable to execve

