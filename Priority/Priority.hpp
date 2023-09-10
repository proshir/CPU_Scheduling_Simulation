#ifndef PRT_H
#define PRT_H

#include "../Bases/scheduler.hpp"

class Priority : public Scheduler {
public:
    void Schedule();
};

#endif