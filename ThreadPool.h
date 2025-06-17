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

    static ThreadPool& Get();

    void EnqueueTask(std::unique_ptr<ThreadTaskInterface> task);

private:

    ThreadPool(uint8_t noOfThreads);
    ~ThreadPool();

    // Worker threads
    std::vector<std::thread> m_workers{};

    // Task queue
    std::queue<std::unique_ptr<ThreadTaskInterface>> m_tasks{};

    // Synchronization
    std::mutex m_queueMutex;
    std::condition_variable m_condition;
    std::atomic<bool> m_stop{false};
};