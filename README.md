# Simple Shell
Releade date August 25, 2023

## Table of Contents
1. Introduction
2. Project Information
    - Task
    - General Requirements
    - Allowed functions & system calls
3. Documentation
    - Usage
4. Authors
  -Jesus R. Mendez Cruz
  -Kelvin A. Santana Collazo

## 📜 Introduction
- What is Shell?
The name "shell" for a command-line interpreter and the concept of making the shell a user program
outside of the operating system kernel were introduced in Unix's precursor Multics. Shell is an enviorment
in which we can run our commands, programs and shell scripts. Is the operating system's command-line interface
(CLI) and interpreter for the set of commands that are used to communicate with the system. A shell script is
usually created for command sequences in which a user has a need to use repeatedly in order to save time.
## 📢 Project Information

### 🎯 Tasks

  * Task 0 - Write a README, Write a man for your shell & AUTHOR file.

  * Task 1 - Write a beautiful code that passed the Betty checks

  * Task 2
     Write a UNIX command line interpreter.

   Usage: simple_shell

Your Shell should:

   Display a prompt and wait for the user to type a command. A command line always ends with a new line.
   The prompt is displayed again each time a command has been executed.
   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
   The command lines are made only of one word. No arguments will be passed to programs.
   If an executable cannot be found, print an error message and display the prompt again.
   Handle errors.
   You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

   use the PATH
   implement built-ins
   handle special characters
   be able to move the cursor
   handle commands with arguments

  * Task 3 - Handle command lines with arguments

  * Task 4 - Handle the PATH, fork must not be called if the command doesnt exist

  * Task 5 - Implement the exit built-in, that exits the shell

  * Task 6 - Implement the env built-in, that prints the current enviorment


### ⚒ General requirements

   Allowed editors:
   ![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white)
   ![Emacs](https://img.shields.io/badge/Emacs-%237F5AB6.svg?&style=for-the-badge&logo=gnu-emacs&logoColor=white)

   All our files were compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-g -Wall -Werror -Wextra -pedantic -std=gnu89`

   Language: ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

### ✅ Allowed functions & system calls & used

    - access (man 2 access)
    - chdir (man 2 chdir)
    - close (man 2 close)
    - closedir (man 3 closedir)
    - execve (man 2 execve)
    - exit (man 3 exit)
    - _exit (man 2 _exit)
    - fflush (man 3 fflush)
    - fork (man 2 fork)
    - free (man 3 free)
    - getcwd (man 3 getcwd)
    - getline (man 3 getline)
    - getpid (man 2 getpid)
    - isatty (man 3 isatty)
    - kill (man 2 kill)
    - malloc (man 3 malloc)
    - open (man 2 open)
    - opendir (man 3 opendir)
    - perror (man 3 perror)
    - read (man 2 read)
    - readdir (man 3 readdir)
    - signal (man 2 signal)
    - stat (__xstat) (man 2 stat)
    - lstat (__lxstat) (man 2 lstat)
    - fstat (__fxstat) (man 2 fstat)
    - strtok (man 3 strtok)
    - wait (man 2 wait)
    - waitpid (man 2 waitpid)
    - wait3 (man 2 wait3)
    - wait4 (man 2 wait4)
    - write (man 2 write)
### File names & content

|Name                |Information                        |Relevant Files                         |
|----------------|-------------------------------|-----------------------------|
|`man_shell` |Man page of the shell program.| `None` |
|`simple_shell.h`| Header file with the  libraries and custom prototypes.| `*.c compilation` |
\`hsh.c`|Main shell function file. Calls other functions.|`shell.func.c` |
\`shell_func.c` |costume functions created. | `None` |
\`README.md` |Readme file| `None` |

## 🗃️ Documentation

### 🕹️ Usage
  First complie the shell program using the following command:
  ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```
  Then run the shell program using the following command:
  ```./hsh```

  ![Output Example](./simple_shell.png)
  Interactive

  An interactive shell is defined as the shell that simply takes commands as input from the user and
  acknowledges the output to the user. This shell also reads startup files that occurred during activation
 and display a prompt.

  Non-Interactive

  As the name inplies, a non-interactive shell is a type of shell that doesn't interact with the user. We can
 run it through a script. Also, it can be run through some automated process. The non-interactive shell influence
the PATH variables. It is higly recommended to use the full path for a command in non-interactive shells. Non-interactive
scripts can smoothly run in the background easily.

  Built-In

  A built-in is a command or function that is part of the shell itself. The command is "built-in" to the shell program
 - no external program is necessary to run the command, and a new process does not need to be created.

## 🖋️ Developers
 Hey there! Im `Jesus R. Mendez Cruz` you can find me over at:  [GitHub](https://github.com/JRMC-PR) / [linkedin](https://www.linkedin.com/in/jes%C3%BAs-m%C3%A9ndez-068b8a27a/). Im a recenly graduated software engineer from Holberton School. I have a passion for learning and teaching others. I love to code and I am always looking for new challenges and opportunities to grow as a professional.
### Kelvin A. Santana
