# **CS252 OperatingSystems**
This repository contains the assignment regarding the course CS252 : Operating Systems mentored by Prof.Mohit Tahiliani

## **Program 1**:
The Collatz conjecture concerns what happens when we take any positive integer and apply the following algorithm:

        n =     n∕2,if n is even
                3n+1,  if n is odd
        
Write a C program using the fork() system call that generates thissequence in the child process. The starting number will be provided from the command line.Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.

### **Code**:
In this program,we use *fork()* function creates a child process that runs concurrently with the parent process(one that makes *fork()* call). When the parent process successfully creates a child process, the *fork()* system call returns a positive value.The *wait()* system call halts the parent process till the termination of its child process and returns status information and pid of the terminated child process.

### **Result**:
Output from the code:

<img src="/Results/collatz.png" alt="Collatz Conjucture code" />

Here, the *fork()* system call only operates in Linux based operating system. To run the code in Windows OS, one might have to install MinGW (GCC compiler) and select appropriate packages/header files or might use some online compilers.

## **Program 2**:
Write a multithreaded program that calculates various statistical values for a list of numbers. This program will be passed a series of numberson the command line and will then create three separate worker threads.One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine the minimum value.The variables representing the average, minimum, and maximum values will be stored globally. The worker threads will set these values and the parent thread will output the values once the workers have exited.

### **Code**:
In this code, we use function *pthread_create()* which creates a new thread in the calling process.Function *pthread_join()* suspends execution of the calling thread until the target thread terminates.

### **Results**:
Output from the code:

<img src="/Results/multithread.png" alt="Multithreading code"/>

*Pthread* api is really useful tool while working on thread creation and synchronization.While executing in terminal, one must add *-lpthread* to ensure the pthread library to be linked.




