# CS480 A1
**README** \
**CS480, Summer 2026** \
**Programming Assignment #1** \
Alice Hua and Brianna Garcia

**Class Accounts:** 
* Brianna: cssc3122 
* **USING Alice account:**  cssc3124

## Project Description
This project implements multi threads of chatbots to asynchronously
but simultaneously run with each other . This is done by using semaphores and threads.


## File Manifest
* **bots.cpp** \
Source file that creates and manages the threads and semaphores.
Contains the implementation of threads, even and odd, writing to a shared file.

* **bots.hpp** \
Header file that contains the thread function.

* **MakeFile** \
Used to compile and clean the project.

* **README** \
Description of the project and how to compile.

### Compile Instructions
To compile the program, use 'make', and an executable 'bots' will be created.
For it to be cleaned, use 'make clean'

### Operating Instructions
To run the program, the command ./bots is used. This allows for a file named
QUOTES.txt to be created in the directory, displaying the threads created. No
 command line or arguments are required.

### Significant Design Decisions
* Threads were created using POSIX version of threads by using the system call
pthread_create().
* A semaphore was used to allow threads to access the file QUOTE.txt one at a time
* Depending on whether the thread is even or odd, their sleep timer is determined.

### Extra Features
No extra features are included

### Known deficiencies or bugs
No deficiencies or bugs encountered at the time of submission.

### Lessons Learned
1. Learned how to create POSIX threads
2. How semaphores are used for multiple threads to access the file
3. Gained knowledge of synchronization



