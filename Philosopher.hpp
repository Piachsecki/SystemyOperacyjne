#pragma once

#include <mutex>
#include <chrono>
#include <random>
#include <cstdint>

class Philosopher {
private:
    int id;
    std::mutex& left_fork;
    std::mutex& right_fork;
    std::mt19937 rng;

    void thinking();
    void eating();
    void pick_up_forks();
    void put_back_forks();
    void sleep_long();
    void sleep_short();
    static std::string get_current_time();

public:
    Philosopher(int id, std::mutex& left_fork, std::mutex& right_fork)
            : id(id), left_fork(left_fork), right_fork(right_fork) {

        std::random_device rd;
        rng = std::mt19937(rd() + id);
    }
    void run();
};