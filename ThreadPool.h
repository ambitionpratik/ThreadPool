#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <condition_variable>
#include <queue>
#include <functional>

#include "ThreadTaskInterface.h"

class ThreadPool
{
    public:

    ThreadPool(uint8_t noOfThreads);
    ~ThreadPool();

    void EnqueueTask();

    private:

    // Worker threads
    std::vector<std::thread> workers{};

    // Task queue
    std::queue<std::unique_ptr<ThreadTaskInterface>> tasks{};

    // Synchronization
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};