Philosopers dining problem
Date: 2025-03-29



Tags:
[#university]


We have philosophers at the dining table. They can either think OR eat. When they:
- want to eat they have to use 2 forks 
- think - they are not interracting with anyone,
but when they want to eat - they can pick only 1 fork at the time (the fork ofc cannot be used by the other phisolopher simultaunously)



It is a very common programming problem, where:
- philosophers - are threads/processes
- forks - are resources that have to be shared between those threads, without 


The solution for this problem can be achieved by the usage of [[Semaphores]].

1. When phisolopher tries to grab a fork - executes wait() operation on that semaphore
2. When he finishes, he is realising resource (fork) by signal() operation on that semaphore

These forks will be stored in an array / list. But by only this solution, we can face a [[Thread deadlock]]. If every philosopher takes the fork on his left, then every philosopher will end up having only 1 fork, while blocking the access to other philosophers to pick it up.

To avoid this we should implement the logic:
- to pick up 1st fork by a philosopher only if the second of them are still available.
- or use the asymmetric solution - the odd philosopher pick up first his left fork and then the right one, whereas even philosopher picks up his right fork and then left one.

But again, those 2 upper solutions will not really solve the [[Thread starvation]], because there might be a philosopher that will not get both forks never.


