import logging
import threading
import time
import sys
import random

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')

class Philosopher:
    def __init__(self, id, left_fork, right_fork):
        self.id = id
        self.left_fork = left_fork
        self.right_fork = right_fork
    
    def thinking(self):
        logging.info(f"Philosopher {self.id} is thinking")
        time.sleep(random.uniform(1, 5))
    
    def eating(self):
        logging.info(f"Philosopher {self.id} is eating")
        time.sleep(random.uniform(1, 5))

    def pick_up_forks(self):
        if self.id % 2 == 0: 
            logging.info(f"Philosopher {self.id} is trying to pick up left fork")
            self.left_fork.acquire()
            logging.info(f"Philosopher {self.id} picked up left fork")
            time.sleep(random.uniform(0.1, 0.5)) 
            
            logging.info(f"Philosopher {self.id} is trying to pick up right fork")
            self.right_fork.acquire()
            logging.info(f"Philosopher {self.id} picked up right fork")
        else: 
            logging.info(f"Philosopher {self.id} is trying to pick up right fork")
            self.right_fork.acquire()
            logging.info(f"Philosopher {self.id} picked up right fork")
            time.sleep(random.uniform(0.1, 0.5))  
            
            logging.info(f"Philosopher {self.id} is trying to pick up left fork")
            self.left_fork.acquire()
            logging.info(f"Philosopher {self.id} picked up left fork")
    
    def put_back_forks(self):
        if self.id % 2 == 0: 
            self.right_fork.release()
            logging.info(f"Philosopher {self.id} put down right fork")
            self.left_fork.release()
            logging.info(f"Philosopher {self.id} put down left fork")
        else: 
            self.left_fork.release()
            logging.info(f"Philosopher {self.id} put down left fork")
            self.right_fork.release()
            logging.info(f"Philosopher {self.id} put down right fork")
        logging.info(f"Philosopher {self.id} has put back both forks")

    def run(self):
        while True:  
            self.thinking()
            self.pick_up_forks()
            self.eating()
            self.put_back_forks()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Add number of philosophers to check")
        sys.exit(1)

    number_of_philosophers = int(sys.argv[1])
    forks = []
    philosophers = []

    for i in range(number_of_philosophers):
        forks.append(threading.Lock())

    for i in range(number_of_philosophers):
        philosophers.append(Philosopher(i, forks[i], forks[(i + 1) % number_of_philosophers]))

    philosopher_threads = []
    for philosopher in philosophers:
        t = threading.Thread(target=philosopher.run)
        t.start()
        philosopher_threads.append(t)

    for t in philosopher_threads:
        t.join()
    print("Simulation complete!")
  