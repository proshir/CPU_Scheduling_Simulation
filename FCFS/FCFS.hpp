#ifndef FCFS_HPP
#define FCFS_HPP

#include "../Bases/scheduler.hpp"

using namespace std;

class FCFS : public Scheduler {
public:
    void Schedule();
};

#endif // FCFS_HPP