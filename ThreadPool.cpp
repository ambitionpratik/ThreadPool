#include "ThreadPool.h"

ThreadPool::ThreadPool(uint8_t noOfThreads) {
    auto threadRoutine{[this](){
        while(true) {
            std::lock_guard<std::mutex> lock(queueMutex);

            // There is a task in the queue, process it
            if(!tasks.empty()) {
                std::unique_ptr<ThreadTaskInterface> threadTask{std::move(tasks.front())};
                tasks.pop();

                threadTask->Execute();
            }
        }
    }};

    for (uint8_t i{0}; i < noOfThreads; ++i) {
        workers.emplace_back(threadRoutine);        
    }
}

ThreadPool::~ThreadPool() {
for (std::thread &worker : workers)
        worker.join();
}

void ThreadPool::EnqueueTask() {

}