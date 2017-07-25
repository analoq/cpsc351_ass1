CPSC 351 - Assignment 1
=======================

Group
-----
Aaron Matthews, apmatthews@csu.fullerton.edu
Anas Elhadidy, aelhadidy@csu.fullerton.edu


Programming Language
--------------------
C++ for shell
C for downloader


Instructions
------------
Programs can be built with the Makefile using make

For the shell:
  As the name implies, createBash create the bash shell, where the parent waits for the command, and child executes it. 
  Run ./createBash for the shell
  type "exit" to quit

For the Downloader:
  Ensure urls.txt in working directory
  Run ./serial for serial downloader
  Run ./parallel for parallel downloader


Execution Times
---------------
Serial downloader: 4.8 seconds
Parallel downloader: 2.1 seconds


Questions
---------
> In the output of time, what is the difference between real, user, and sys time?

Real time is the actual execution time.  User time is the amount of the CPU's time used in user space, whereas Sys time is the amount of the CPU's time used in kernel space e.g. by system calls.

> Which is longer: user time or systime?  Use your knowledge to explain why.

User time is longer.  This must mean more CPU was used in user space rather than in kernel space with system calls.

> When downloading the files above, which downloader finished faster? Why? Explain.

The parallel downloader finished faster.  Instead of waiting for the first file to finish before starting the second, both downloads were started at the same time.  

> Repeat the experiment for 10 files.  Is the downloader in the previous question still faster?  If not so, why?  Please explain.

With 10 files, serial took 15.2 seconds and parallel took 3.2 seconds.  So, yes, the parallel downloader was even faster in this case.

Volunteering
------------
Yes.

Special Notes
-------------
None.

Hard Times
----------
Switching to FreeBSD, the path to wget was needed to be changed.
