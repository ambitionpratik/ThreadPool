#include <iostream>
#include "ThreadTask.h"

ThreadTask::ThreadTask(const std::string &taskName) : _name{taskName} { }

void ThreadTask::Execute() {
    std::cout << "Executing the task:" << _name << std::endl;
}