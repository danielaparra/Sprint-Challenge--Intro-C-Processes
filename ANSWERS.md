**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Created - The process was just created and waiting to enter Ready state.
Ready - The process has been loaded into main memory and waiting the for a CPU to process it.
Running - The process is either running and executed by one of the CPUs.
Blocked - The process is in a standstill and waiting for an event to complete. 
Terminated - The process has been terminated after completing its execution or by being explicitly killed.

**2. What is a zombie process?**
The zombie process is when a process is terminated but waiting for their exit status to be collected.

**3. How does a zombie process get created? How does one get destroyed?**
When a child process gets terminated and it waiting for the parent process to collect its exit status. Once that parent process collects its exit status, it can be terminated. 


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Working with a compiled language there is a chance for faster performance since you are working with the native code of the machine. You can apply serious optimizations when working with a compiled language as opposed to a non-compiled language.
