When it comes to dynamic memory management in C, many developers struggle with a very well known and common error called 'Segmentation Fault'.

Let us discuss how we can resolve these issues using GDB (GNU Degbugger)

The file seg_fault.c contains some C code that contains Segmentation Fault, let us find out where this error is occurring:

If you observe closely you find that at line 10 we are trying to access NULL which is not a valid memory location and this leads to segmentation fault.

This was a small program and hence we were able to detect the error early on but what if this was a huge program?
Doing a drive run(running the program in your head) would be a tedious task.

So we do what programmers do automate it with tools and code. Fortunately we have GDB packaged with the GCC compiler.

Steps to resolve errors using gdb:
1. Compile your code with g flag:

gcc -g seg_fault.c      (Don't forget to change the file name to your file name)

![alt text](image.png)

2. run the command: gdb a.out

3. run the command: run

4. We instantly get a message stating that we have a segfault at line 10 and now we can rectify it. 

This seems simple but we can modify code that was not causing the segfault. This can happen when the function where the fault occurred received invalid arguments.

To check all function calls that eventually led to the fault, we run the command: 
bt      (which stands for backtrace)

now we know what all functions were called since the start of the program that are still active and led to segfault.

Let us check the below function main to see what arguments we passed, this can be done by running the following commands:
up
info locals

As you can see the addresses passed as current was 0x0 which is NULL and thus was the root cause of the issue.

(Similarly you can use 'down' to traverse the other side of the stack call)

Some other GDB commands that might be handy for you:
1. list (lists adjacent lines to frames present in the backtrace)
2. step (if you didn't want to execute the program directly but wanted to check what happens to data from current line use step)
3. next (if you want to execute next line)
4. quit (for exiting offcourse)
5. break <line number> (to set up break points)
6. continue (to resume after inspecting break points)