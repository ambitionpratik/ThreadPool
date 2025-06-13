#pragma once

#include <string>
#include "ThreadTaskInterface.h"

class ThreadTask : public ThreadTaskInterface {
    public:
        ThreadTask(const std::string& taskName);
        void Execute();

    private:
        // Data members
        std::string _name{};
};