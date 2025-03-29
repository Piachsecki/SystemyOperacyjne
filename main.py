import logging
import threading
import time
import sys
import random

number_of_philosophers = sys.argv[0]

class Philosopher:
    def __init__(self, id, his_left_fork, his_right_fork):
        self.id = id
        self.his_left_fork = his_left_fork
        self.his_right_fork = his_right_fork
    
    def thinking(self):
        time.sleep(random.uniform(1, 5))
        logging("Philosopher %d is thinking", id)
    
    def eating(self):
        logging("Philosopher %d is eating", id)
        time.sleep(random.uniform(1, 5))


    def pick_up_forks(self):
        if not self.his_left_fork.locked() and not self.his_right_fork.locked():
            logging(f"Philosopher can try picking forks, because both of his left and right are available!")
        
        if self.id % 2 == 0:
            self.his_left_fork.acquire()
            logging(f"Philosopher {self.id} is picking up his left fork")
            time.sleep(random.uniform(1, 2))

            self.his_right_fork.acquire()
            logging(f"Philosopher {self.id} is picking up his left fork")
            time.sleep(random.uniform(1, 2))
               
            
        else:
            self.his_right_fork.acquire()
            logging(f"Philosopher {self.id} is picking up his right fork")
            time.sleep(random.uniform(1, 2))

            self.his_left_fork.acquire()
            logging(f"Philosopher {self.id} is picking up his left fork")
            time.sleep(random.uniform(1, 2))  

        logging("Philosopher %d picked up forks", id)   

    def put_back_forks(self):
        logging("Philosopher %d is putting back forks", id)
        self.his_left_fork.release()
        self.his_right_fork.release()


if __name__ == "__main__":
    print(f"Executing script: {sys.argv[0]}")

    if len(sys.argv) < 2:
        print("You must pass number of philosophers!")
        exit
    forks = []
    philosophers = []

    for philosopher in range(number_of_philosophers):
        forks.append(threading.Lock())
    
    for philosopher in range(number_of_philosophers):
        philosophers.append(Philosopher(philosopher, forks[philosopher], forks[(philosopher + 1) % number_of_philosophers]))

    print("Hello")

