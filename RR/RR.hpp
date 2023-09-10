#ifndef RR_H
#define RR_H

#include "../Bases/scheduler.hpp"

class RR : public Scheduler {
public:
    RR(int tq) : timeQuantum(tq) {}

    void Schedule();
private:
    int timeQuantum;
};

#endif