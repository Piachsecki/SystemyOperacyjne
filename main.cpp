#include "./Philosopher.hpp"

#include <vector>
#include <thread>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Add number of philosophers to check\n");
        return 1;
    }

    uint8_t number_of_philosophers = std::stoi(argv[1]);
    std::vector<std::mutex> forks(number_of_philosophers);
    std::vector<Philosopher> philosophers;

    for (int i = 0; i < number_of_philosophers; i++) {
        philosophers.emplace_back(i, forks[i], forks[(i + 1) % number_of_philosophers]);
    }

    std::vector<std::thread> philosopher_threads;
    for (int i = 0; i < number_of_philosophers; i++) {
        philosopher_threads.emplace_back(&Philosopher::run, &philosophers[i]);
    }

    for (auto& t : philosopher_threads) {
        t.join();
    }

    printf("Simulation complete!\n");
    return 0;
}
