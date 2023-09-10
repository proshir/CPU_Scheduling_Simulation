#ifndef SJF_H
#define SJF_H

#include "../Bases/scheduler.hpp"

class SJF : public Scheduler {
public:
    void Schedule();
};

#endif