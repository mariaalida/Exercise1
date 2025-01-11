Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
> concurrency is when dealing with multiple things/threads at the time (only dealing, not doing) using one core, while parallelism is when youre uning multiple cores  

What is the difference between a *race condition* and a *data race*? 
> Race condition is when the result depends on the order the code is run. Data race is when multiple threads access/writes to the same memory, causing unpredictable behavior due to not handling the syncronization correctly.   
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> A scheduler decides which threads to run at what time.  


### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
> Its used when handling multiple problems at the same time.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> fibers are threads divided into multiple tasks. 

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> its a lot to managing all the aspects of concurrent programs but is key to optimize paralell tasks. 

What do you think is best - *shared variables* or *message passing*?
> message passing


