Shell Project

The project is about writing a simple UNIX command interpreter.

The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and others at Bell Labs in the late 1960s and early 1970s.

Ken Thompson also wrote the first version of the Unix shell, known as the Thompson shell or the "sh" shell.

The B programming language, which served as a direct predecessor to the C programming language, was invented by Ken Thompson at Bell Labs in the early 1970s.

Ken Thompson is a computer scientist who played a significant role in the development of the Unix operating system and the C programming language. He is also known for his contributions to computer security and the development of the Plan 9 from Bell Labs operating system.

A shell is a command-line interface that provides a user-friendly way to interact with an operating system. It works by taking user input (commands), interpreting them, and then executing the corresponding system calls or programs.

PID (Process ID) stands for the unique identifier assigned to each running process in an operating system. PPID (Parent Process ID) is the identifier of the parent process that spawned the current process.

You can manipulate the environment of the current process in Unix-like systems using environment variables. You can set environment variables using commands like export in a shell. For example, export MY_VAR="Hello" sets an environment variable named MY_VAR with the value "Hello" for the current process.

The main difference between a function and a system call is that functions are part of a programming language and are executed in the user's address space, whereas system calls are requests made by user-level programs to the operating system kernel to perform privileged operations, such as I/O or process management.

Processes can be created in Unix-like systems using system calls like fork or exec. The fork system call creates a new process that is a copy of the current process, while exec replaces the current process with a new program.

The three prototypes of the main function in C are:

int main(void): This is the simplest form of the main function, which takes no arguments.
int main(int argc, char *argv[]): This form of main accepts command-line arguments, with argc representing the number of arguments and argv being an array of pointers to the argument strings.
int main(int argc, char *argv[], char *envp[]): This form of main also accepts environment variables through the envp parameter.
The shell uses the PATH environment variable to find programs. When you enter a command in the shell, it searches for the executable file associated with that command in the directories listed in the PATH variable. If it finds a match, it executes the program.

You can execute another program with the execve system call in C. This call replaces the current process image with the new program specified in the arguments.

To suspend the execution of a process until one of its children terminates, you can use the wait or waitpid system calls in C. These calls allow a parent process to wait for its child processes to exit and retrieve their exit status.

EOF, or "end-of-file," is a condition in input and output operations that indicates the end of the data stream. In C and many other programming languages, EOF is typically represented as a special constant (often -1) and is used to signify the end of reading from a file or input stream. It's important for programs to check for EOF to handle input and file processing correctly.

List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

0. Betty would be proud
mandatory
Write a beautiful code that passes the Betty checks

1. Simple shell 0.1
mandatory
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
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…

2. Simple shell 0.2
mandatory
Simple shell 0.1 +

Handle command lines with arguments

3. Simple shell 0.3
mandatory
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist

4. Simple shell 0.4
mandatory
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

5. Simple shell 1.0
mandatory
Simple shell 0.4 +

Implement the env built-in, that prints the current environment

Team
Onyiso Chris(https://github.com/OnyisoChris)

Acknowledgment
- My fellow cohort members.
- The developers of the C language.
- Betty Holberton.
