#pragma once

class ThreadTaskInterface {

    public:
        virtual ~ThreadTaskInterface() = default;

        virtual void Execute() = 0;
};