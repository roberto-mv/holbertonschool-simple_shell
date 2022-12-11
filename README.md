<h1 align ="center">
<img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" height="36%" width="26%">
</h1>

# Simple Shell

## Synopsis :page_facing_up:
A basic UNIX command language interpreter that reads and executes commands from a file or standard input.

## Description :speech_balloon:
When a command is entered at the command line and the enter key is pressed, the shell process of reading and executing that command begins. Here is a step-by-step breakdown of what happens:

  1. The command is read from the standard input (i.e., the keyboard).
  2. The shell tokenizes the command into words, separating it into the command itself and any arguments or options that were provided with it.
  3. The shell checks to see if the command is a built-in shell command (e.g., cd, exit, etc.). If it is, the shell will execute the command directly.
  4. If the command is not a built-in shell command, the shell will search for an executable file with the same name as the command in the directories specified by the   PATH environment variable.
  5. If the shell finds an executable file with the same name as the command, it will execute that file.
  6. If the shell does not find an executable file with the same name as the command, it will return an error message indicating that the command could not be found.
  7. Once the command has been executed, the shell will return to the command prompt, waiting for the next command to be entered.

This process is repeated each time a command is entered at the command line and executed by the shell.

## Usage :running:
+ All the files are to be compiled on Ubuntu 20.04 LTS
+ Compile your code with 
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o hsh

```
## Example :muscle:

**hsh** can be invoked both interactively and non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:

```
$ echo "/bin/ls" | ./hsh
ada.txt betty cisfun.js
$
```

If **hsh** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **hsh** displays the prompt `$ ` when it is ready to read a command.

Example:

```
$ ./hsh
$
```

Alternatively, if command line arguments are supplied upon invocation, **hsh** treats the first argument as a file from which to read commands. The supplied file should contain one command per line. **hsh** runs each of the commands contained in the file in order before exiting.

Example:

```
$ cat test
echo 'betty'
$ ./hsh test
'betty'
$
```

## Authors :black_nib:

* Marcelo Vizcarra <[mavix21](https://github.com/mavix21)>
* Roberto Montes <[jocalao001](https://github.com/roberto-mv)>

## Acknowledgements :pray:

This program was written as part of the curriculum for Holberton School.
Holberton School is a campus-based full-stack software engineering program
that prepares students for careers in the tech industry using project-based
peer learning. For more information, visit [this link](https://www.holbertonschool.com/).

<p align ="center">
<img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" height="25%" width="15%">
</p>
