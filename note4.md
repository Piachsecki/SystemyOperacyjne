Semaphores

Date: 2025-03-29



Tags:
[#university]

Semaphore is a simple integer value that can be used to manage concurrent processes. Basically the value of this semaphor is shared between threads/processes and can be accessed only by two (atomic) operations:
- wait() -> P (to test if there is any other process using the resource)
```bash
wait() {
	while (semaphore <= 0 ) {
		#not leaving the loop
	};
	semaphore--;
}
```


- signal() -> V (to increment - to signal other processes that this process finished with the semaphore and it can be used)
```bash
signal() {
	semaphore++;
}
```

Semaphore can be modified ONLY by one process. It used by many processes, but modfiied it can be only by ONE !



We have 2 types of semaphores:

-  Binary Semaphore
The value can be only 1 / 0. If semaphore is 0 then it means that the semaphore is being used by some other resource and the process who requests the access have to wait for the semaphore to be free. If the value is 1(initial value when we create) - means that this semaphore can be used.


So basically it works like this:
1. We have 3 processes.
2. 1st process access the resource AND uses a semafor to change its value to 0 (blocking the access for the different processes)
3. 2nd process wants to acquire the access to the shared resource so tries to access it, but there is a semafor (wait() operation especially) that checks if the resource is blocked (0) or open (1). In this case its blocked -> we put this process in a loop.
4. 1st process decided to finish, so there is an operation signal() performed on the semaphor. Changing the value from 0 to 1 and letting the other processes know that the can use this semaphor again
5. 2nd process see that its free so its using the shared resource and its blocking the semaphor again
6. ........ over and over again.......


- Counting semaphore
This semaphores are used when there are multiple instances of a shared resource. It kinda looks the same but semaphor right now can be 2 or 3 or 12 and all of this operations of locking by wait() operations will be the same, but the starting value of semaphore will be 12. If some process use the instance of the resource, we will decriment the value to 11 and so on and so on. And the value when this resource will be locked is 0 as well


 




