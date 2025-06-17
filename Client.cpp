#include <iostream>
#include <memory>

#include "ThreadPool.h"
#include "ThreadTask.h" 
#include "ThreadTaskInterface.h"

int main() {

    std::unique_ptr<ThreadTaskInterface> task1{new ThreadTask("Task-1")};
    std::unique_ptr<ThreadTaskInterface> task2{new ThreadTask("Task-2")};
    std::unique_ptr<ThreadTaskInterface> task3{new ThreadTask("Task-3")};
    std::unique_ptr<ThreadTaskInterface> task4{new ThreadTask("Task-4")};
    std::unique_ptr<ThreadTaskInterface> task5{new ThreadTask("Task-5")};
    
    // Get the instance of thread pool.
    ThreadPool::Get().EnqueueTask(std::move(task1));
    ThreadPool::Get().EnqueueTask(std::move(task2));
    ThreadPool::Get().EnqueueTask(std::move(task3));
    ThreadPool::Get().EnqueueTask(std::move(task4));
    ThreadPool::Get().EnqueueTask(std::move(task5));

    //std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}