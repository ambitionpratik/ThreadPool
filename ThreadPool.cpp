#include "ThreadPool.h"

ThreadPool::ThreadPool(uint8_t noOfThreads) {
    auto threadRoutine{[this](){
        while(!m_stop) {
            std::unique_lock<std::mutex> lock(m_queueMutex);

            m_condition.wait(lock, [this]{
                return (m_stop || !m_tasks.empty());
            });

            if (m_stop && m_tasks.empty()) {
                return;
            }

            std::unique_ptr<ThreadTaskInterface> threadTask{std::move(m_tasks.front())};
            m_tasks.pop();

            std::cout<<"Thread with id:"<<std::this_thread::get_id()<<" has picked up task"<<std::endl;
            threadTask->Execute();

            //std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }};

    for (uint8_t i{0}; i < noOfThreads; ++i) {
        m_workers.emplace_back(threadRoutine);        
    }
    std::cout<<"No of threads created:"<<m_workers.size()<<std::endl;
}

ThreadPool::~ThreadPool() {
    m_stop = true;
    m_condition.notify_all();
    for (std::thread &worker : m_workers) {
        worker.join();
    }
}

ThreadPool &ThreadPool::Get() {
    // TODO: insert return statement here
    static ThreadPool threadPool(8);
    return threadPool;
}

void ThreadPool::EnqueueTask(std::unique_ptr<ThreadTaskInterface> task) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    m_tasks.push(std::move(task));

    m_condition.notify_all();
}