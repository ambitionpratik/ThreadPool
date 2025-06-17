# ThreadPool
It is used create a pool of threads. The thread can be pick from to pool to process a task.

**Why it's important:**
- Real-world apps (servers, games, GUI, embedded systems) need efficient thread reuse.
- Creating and destroying threads is expensive.
- A thread pool manages a fixed number of threads to process any number of tasks.

**How it implemented**
- Created a singleton thread pool class.
- Create a task that can be executed by worker thread in thread pool.
- Added a task into thread pool's task queue.



