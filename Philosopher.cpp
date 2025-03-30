#include "./Philosopher.hpp"

#include <iostream>
#include <thread>
#include <ctime>
#include <sstream>
#include <mutex>

std::mutex cout_mutex;

std::string Philosopher::get_current_time() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::ostringstream oss;
    oss << localTime->tm_hour << ":"
        << localTime->tm_min << ":"
        << localTime->tm_sec;

    return oss.str();
}

void Philosopher::sleep_long() {
    std::uniform_real_distribution<double> dist(1.0, 5.0);
    const double seconds = dist(rng);
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<uint16_t>(seconds * 1000)));
}

void Philosopher::sleep_short() {
    std::uniform_real_distribution<double> dist(0.1, 0.5);
    const double seconds = dist(rng);
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<uint16_t>(seconds * 1000)));
}

void Philosopher::thinking() {
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << get_current_time() << " Philosopher " << id << " is thinking" << std::endl;
    }
    sleep_long();
}

void Philosopher::eating() {
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << get_current_time() << " Philosopher " << id << " is eating" << std::endl;
    }
    sleep_long();
}

void Philosopher::pick_up_forks() {
    if (id % 2 == 0) {
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " is trying to pick up left fork" << std::endl;
        }
        left_fork.lock();
        sleep_short();
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " is trying to pick up right fork" << std::endl;
        }
        right_fork.lock();
    } else {
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " is trying to pick up right fork" << std::endl;
        }
        right_fork.lock();
        sleep_short();
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " is trying to pick up left fork" << std::endl;
        }
        left_fork.lock();
    }
}

void Philosopher::put_back_forks() {
    if (id % 2 == 0) {
        right_fork.unlock();
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id<< " put down right fork" << std::endl;
        }
        left_fork.unlock();
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " put down left fork" << std::endl;
        }
    } else {
        left_fork.unlock();
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " put down left fork" << std::endl;
        }
        right_fork.unlock();
        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << get_current_time() << " Philosopher " << id << " put down right fork" << std::endl;
        }
    }
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << get_current_time() << " Philosopher " << id << " has put back both forks" << std::endl;
    }
}

void Philosopher::run() {
    while (true) {
        thinking();
        pick_up_forks();
        eating();
        put_back_forks();
    }
}